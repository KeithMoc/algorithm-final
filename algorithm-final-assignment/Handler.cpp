//
//  Handler.cpp
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/16.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#include "Handler.h"
#include "Helper.h"

int Handler::handleInput(const int input) {
    switch (input) {
        case 1:
            createInputMatrix(1);
            break;
        case 2:
            createInputMatrix(2);
            break;
        case 3:
            createInputMatrix(3);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
    }
    return 0;
}

void Handler::createInputMatrix(int input) {
    switch (input) {
        case 1: {
            int tempMatrix[5][5] = {
                {0,4,8,9,12},
                {4,0,6,8,9},
                {8,6,0,12,12},
                {9,8,12,0,7},
                {12,9,12,7,0}
            };
            gintLength = 5;
            // initialize rows
            gintInputMatrix = new int* [gintLength];
            for(int i = 0; i < gintLength; i++){
                // assign value to each rows
                gintInputMatrix[i] = tempMatrix[i];
            }
            break;
        }
        case 2:
        {
            int tempMatrix[6][6] = {
                {0,41,19,99,83,108},
                {41,0,35,88,96,121},
                {19,35,0,80,70,95},
                {99,88,80,0,53,66},
                {83,96,70,53,0,26},
                {108,121,95,66,26,0}
            };
            gintLength = 6;
            // initialize rows
            gintInputMatrix = new int* [gintLength];
            for(int i = 0; i < gintLength; i ++) {
                // assing value to each rows
                gintInputMatrix[i] = tempMatrix[i];
            }
            break;
        }
        case 3:
        {
            Helper::printInputNewMatrix();
            cin >> gintLength;
            // initialize rows
            gintInputMatrix = new int* [gintLength];
            for(int i = 0; i < gintLength ; i ++) {
                // initialize columns
                gintInputMatrix[i] = new int[gintLength];
                for (int j = 0; j < gintLength ; j ++){
                    cout << "Please insert [" << i << "][" << j << "] :";
                    cin >> gintInputMatrix[i][j];
                }
            }
            break;
        }
        default:
            break;
    }
    Helper::printMatrix(gintInputMatrix, gintLength);
}