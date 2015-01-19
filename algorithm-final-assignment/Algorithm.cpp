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
    for(int i = 0; i < length ; i++) {
        inputMatrix[i] = new int[length];
        for(int j = 0; j < length; j++)
            inputMatrix[i][j] = srcMatrix[i][j];
    }
    
    Helper::printMatrix(inputMatrix, length);
    cout << "Lenght:" << length << endl;
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
    for(int i = 0; i < length ; i++) {
        if(i == length - 1) {
            gRoute[0][length] = 0;
            gRoute[1][length] = inputMatrix[dst][0];
            currentLenght++;
            break;
        }
        cout << "source:" << src << endl;
        dst = findMinFromArray(inputMatrix[src], length);
        gRoute[0][i+1]=dst;
        gRoute[1][i+1]=inputMatrix[src][dst];
        currentLenght++;
        
        for(int j = 0; j < length; j++) {
            inputMatrix[src][j] = 0;
            inputMatrix[j][dst] = 0;
        }
        src = dst;
        cout << "destination:" << dst << endl;
        Helper::printMatrix(inputMatrix, length);
        Helper::printRoute(gRoute, currentLenght);
        
    }
    Helper::printRoute(gRoute, length+1);
    return 0;
}


/**
 * find the position of the minimum value element for an input array.
 */
int Algorithm::findMinFromArray(int* &inputArray, const int lenght) {
    // assume that the first element has the maximum value
    int tempMin = 1;
    for(int i = 2; i < lenght ; i++) {
        if(!isSelected(i) && inputArray[i] != 0)
        {
            if(inputArray[tempMin]==0)
                tempMin = i;
            else if (inputArray[i] < inputArray[tempMin])
                tempMin = i;
            cout << "tempMin:" << tempMin;
        }
    }
    return tempMin;
}

/**
 * find the position is selected or not
 */
bool Algorithm::isSelected(const int src) {
    for(int i = 0; i < currentLenght ; i++) {
        if(gRoute[0][i] == src) {
            cout << "check" << gRoute[0][i] << endl;
            return true;
        }
    }
    return false;
}