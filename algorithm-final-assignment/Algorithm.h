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
    Algorithm(int** _inputMatrix, int _requestCode);
    int findMST();
    int runHeuristicAlgo();
    int runApproximationAlgo();
    int runBranchAndBoundAlgo();
};

#endif /* defined(__algorithm_final_assignment__Algorithm__) */
