//
//  Handler.cpp
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/16.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#include "Handler.h"
#include "Helper.h"
#include "Algorithm.h"

void Handler::handleInput(int input) {
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
    //Helper::printMatrix(gintInputMatrix, gintLength);
    chooseAlgorithm();
}

void Handler::chooseAlgorithm() {
    bool flag = true;
    int option;
    do {
        if(flag) {
            Helper::printAlgorithmList();
            cin >> option;
        }
        else {
            Helper::printError(0);
            cin >> option;
        }
        flag = false;
    } while(option < 1 || option > 9);
    handleAlgorithm(option);
}

void Handler::handleAlgorithm(const int input) {
    Algorithm algo;
    algo.setMatrixLength(gintLength);
    switch (input) {
        case 1: {
            auto start = chrono::steady_clock::now();
            algo.runHeuristicAlgo(gintInputMatrix, gintLength);
            auto end = chrono::steady_clock::now();
            auto diff = end - start;
            cout << "Heuristic Running Time:" << chrono::duration<double,nano> (diff).count() << " (ns)" << endl;
            break;
        }
        case 2:
        {
            auto start = chrono::steady_clock::now();
            algo.runApproximationAlgo(gintInputMatrix, gintLength);
            auto end = chrono::steady_clock::now();
            auto diff = end - start;
            cout << "Approximation Running Time:" << chrono::duration<double,nano> (diff).count() << " (ns)" << endl;
            break;
        }
        case 3:
            
            break;
        case 4: {
            auto start = chrono::steady_clock::now();
            algo.runHeuristicAlgo(gintInputMatrix, gintLength);
            auto end = chrono::steady_clock::now();
            auto diff = end - start;
            cout << "Heuristic Running Time:" << chrono::duration<double,nano> (diff).count() << " (ns)" << endl;
            
            start = chrono::steady_clock::now();
            algo.runApproximationAlgo(gintInputMatrix, gintLength);
            end = chrono::steady_clock::now();
            diff = end - start;
            cout << "Approximation Running Time:" << chrono::duration<double,nano> (diff).count() << " (ns)" << endl;
            break;
        }
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            break;
        case 9:
            exit(0);
            break;
        default:
            break;
    }
}