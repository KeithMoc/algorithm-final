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
public:
    // find minimum spanning tree
     int **gRoute;
    int currentLenght = 0;
    int  findMST(int** &srcMatrix, int const lenght);
    int  runHeuristicAlgo(int** &srcMatrix, int const lenght);
    int  runApproximationAlgo(int** &srcMatrix, int const lenght);
    int  runBranchAndBoundAlgo(int** &srcMatrix, int const lenght);
    int  findMinFromArray(int* &inputArray, int const lenght);
    bool isSelected(int const src);
};

#endif /* defined(__algorithm_final_assignment__Algorithm__) */
