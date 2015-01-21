//
//  Algorithm.h
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/16.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#ifndef __algorithm_final_assignment__Algorithm__
#define __algorithm_final_assignment__Algorithm__

#include "main.h"
class Algorithm {
private:
    int **gRoute;
    int  currentLenght = 0;
    int gintLength;
public:
    
    // find minimum spanning tree
    
    int  runHeuristicAlgo(int** &srcMatrix, int const length);
    int  findMinFromArray(int* inputArray,bool* selected, int const length);
    
    int  runApproximationAlgo(int** &srcMatrix, int const length);
    int  findMinWeigthVertice(int* weigth, bool* mstSet);
    bool isSelected(int* vertices, int const vertex, int const length);
    
    int  runBranchAndBoundAlgo(int** &srcMatrix, int const length);
    
    
    //getter and setter
    void setMatrixLength(int const length) {
        this->gintLength = length;
    };
    
};

#endif /* defined(__algorithm_final_assignment__Algorithm__) */
