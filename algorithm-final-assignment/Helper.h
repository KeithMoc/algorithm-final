//
//  Helper.h
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/15.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#ifndef __algorithm_final_assignment__Helper__
#define __algorithm_final_assignment__Helper__

#include "main.h"

class Helper {
public:
    
    static string const line ;
    static string const lineAlt;
    static void printTitle();
    static void printDescription();
    static void printError(int const error);
    static void processInput(int const input);
    static void printLine();
    static void printMatrix(int** const matrix, int const length);
    static void printInputNewMatrix();
    static void printShortLine();
    static void printAlgorithmList();
    static void printRoute(int** const matrix, int const lenght);
};

#endif /* defined(__algorithm_final_assignment__Helper__) */
