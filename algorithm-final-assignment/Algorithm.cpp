//
//  Algorithm.cpp
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/16.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#include "Algorithm.h"
#include "Helper.h"
/**
 * run the Heuristic Algorithm
 */
int Algorithm::runHeuristicAlgo(int** &srcMatrix, const int length) {
    // clone the matrix
    int **inputMatrix = new int*[length];
    bool* selected = new bool[length];
    for(int i = 0; i < length ; i++) {
        inputMatrix[i] = new int[length];
        for(int j = 0; j < length; j++)
            inputMatrix[i][j] = srcMatrix[i][j];
        selected[i] = false;
    }
    
    Helper::printMatrix(inputMatrix, length);
    gRoute = new int*[2];
    int src,dst;
    // receive position
    gRoute[0] = new int[length+1];
    // receive value
    gRoute[1] = new int[length+1];
    src = dst = 0;
    gRoute[0][0] = 0;
    gRoute[1][0] = 0;
    currentLenght++;
    selected[0] = true;
    for(int i = 0; i < length ; i++) {
        if(i == length - 1) {
            gRoute[0][length] = 0;
            gRoute[1][length] = inputMatrix[dst][0];
            currentLenght++;
            break;
        }
        dst = findMinFromArray(inputMatrix[src], selected, length);
        selected[dst] = true;
        gRoute[0][i+1]=dst;
        gRoute[1][i+1]=inputMatrix[src][dst];
        currentLenght++;
        
        //for(int j = 0; j < length; j++) {
        //    inputMatrix[src][j] = 0;
        //    inputMatrix[j][dst] = 0;
        //}
        src = dst;
    }
    Helper::printRoute(gRoute, length+1);
    return 0;
}


/**
 * find the position of the minimum value element for an input array.
 */
int Algorithm::findMinFromArray(int* inputArray, bool* selected, const int lenght) {
    // assume that the first element has the minimum value
    int minValue = INT_MAX;
    int minIndex = 0;
    for(int i = 0; i < lenght ; i++) {
        if(selected[i] == false  && (inputArray[i] < minValue))
        {
            minIndex = i;
            minValue = inputArray[i];
        }
    }
    return minIndex;
}


/**
 *  Run the approximation algorithm
 *
 *  @param srcMatrix input matrix of weight (between each two vertices)
 *  @param length    number of vertices
 *
 *  @return for checking only
 */
int Algorithm::runApproximationAlgo(int **&srcMatrix, const int length) {
    
    // clone the matrix
    int **inputMatrix = new int*[length];
    for(int i = 0; i < length ; i++) {
        inputMatrix[i] = new int[length];
        for(int j = 0; j < length; j++)
            inputMatrix[i][j] = srcMatrix[i][j];
    }
    
    Helper::printMatrix(inputMatrix, length);
    // store the parrent vertices that go to other vertices
    int* parent = new int[gintLength];
    // weight of vertices in mst
    int* weigth = new int[gintLength];
    // indicate which vertice is included in mst Set - selected: true, unselected: false
    bool* mstSet = new bool[gintLength];
    
    // initialize value for weight and mst set
    for(int i = 0; i < gintLength; i++) {
        weigth[i] = INT_MAX; // INT_MAX as the infinite value
        mstSet[i] = false; // every vertex is unselected
    }
    
    // weigth of the first vertex
    weigth[0] = 0;
    // root vertice
    parent[0] = 0;
    
    // loop to total vertices - 1
    for(int j = 0; j < gintLength - 1; j++) {
        // find the minumum weight of vertex that is not included in mst Set
        int minWV = findMinWeigthVertice(weigth, mstSet);
        // add the min-weigth-vertex to mst set
        mstSet[minWV] = true;
        
        /**
         *  inputMatrix[minWV][v] : weight from the minWeight Vertex to Vertex v is non-zero
         *  vertex v is not seleted in mst Set
         *  weigth of inputMatrix[minWV][v] less than the weigth in the weigth list (update the smallest)
         */
        for(int v = 0; v < gintLength; v++) {
            if(inputMatrix[minWV][v] != 0 && mstSet[v] == false && inputMatrix[minWV][v] < weigth[v]) {
                parent[v] = minWV;
                weigth[v] = inputMatrix[minWV][v];
            }
        }
    }
    
    // initialize child vertices
    int * child = new int[gintLength];
    for (int i = 0; i < gintLength; i++) {
        child[i] = i;
    }
    
    // recorrect the mstSet
    for(int j = 1; j < gintLength -1 ; j++) {
        for(int i = j+1; i < gintLength; i++) {
            if(parent[j] > parent[i]) {
                int temp = parent[j];
                parent[j] = parent[i];
                parent[i] = temp;
                child[j] = i;
                child[i] = j;
            }
        }
    }
    
    /**
     *  find the full route of the spanning tree
     */
    int fullListLength = (gintLength)*2;
    int *fullList = new int[fullListLength];
    for(int i = 0; i < gintLength-1; i++){
        fullList[i*2] = parent[i+1];
        fullList[i*2+1] = child[i+1];
    }
    /**
     *  Adjust the vertices
     */
    // store route weigth
    int *route = new int[gintLength+1];
    // store route vertices
    int *routeVertices = new int[gintLength+1];
    int currentLength = 1;
    routeVertices[0] = 0;
    route[0] = 0;
    for(int j = 1; j < fullListLength; j++) {
        if(!isSelected(routeVertices,fullList[j],currentLength)) {
            routeVertices[currentLength] = fullList[j];
            route[currentLength] = inputMatrix[routeVertices[currentLength-1]][routeVertices[currentLength]];
            currentLength++;
        }
        if(j == fullListLength - 1) {
            routeVertices[currentLength] = 0;
            route[currentLength] = inputMatrix[routeVertices[currentLength-1]][routeVertices[currentLength]];
            currentLength++;
        }
    }
    
    gRoute = new int*[2];
    // receive position
    gRoute[0] = routeVertices;
    // receive value
    gRoute[1] = route;
    Helper::printRoute(gRoute, currentLength);
    // show route
    
    return 0;
}

bool Algorithm::isSelected(int *vertices, const int vertex, int const length) {
    for(int v = 0; v < length; v++) {
        if(vertices[v] == vertex)
            return true;
    }
    return false;
}


/**
 * find the vertices with minimum weigth which is not included in MST Set.
 */
int Algorithm::findMinWeigthVertice(int* weigth, bool* mstSet) {
    /* initialize the min value,
    *we assign the MAXIMUM VALUE OF A INTEGER 2bytes value 2^15 -1
    *(To indicate the first vertice is 0)
    */
    int minWeigth = INT_MAX, min_vertice = 0;
    for(int v = 0; v < gintLength; v++) {
        /* if vertices v is not in the mst Set, 
         and its weigth less than the current minimun weigth */
        if(mstSet[v] == false && weigth[v] < minWeigth) {
            minWeigth = weigth[v];
            min_vertice = v;
        }
    }
    return min_vertice;
}