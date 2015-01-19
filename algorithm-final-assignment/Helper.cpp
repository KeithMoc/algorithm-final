//
//  Helper.cpp
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/15.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#include "Helper.h"


const string Helper::line = "***********************************************************";
const string Helper:: lineAlt = "----------------------------------";


void Helper::printLine() {
    cout << line << endl;
}

void Helper::printShortLine() {
    cout << lineAlt << endl;
}

void Helper::printTitle() {
    cout << line << endl;
    cout << "\t\tAlgorithm Final Assignment" << endl;
    cout << line << endl;
}


/*!
 * @brief display program description when it is started
 */
void Helper::printDescription() {
    cout << "Please choose your options:" << endl;
    cout << "\t1: Use default matrix 1." << endl;
    cout << "\t2: Use default matrix 2." << endl;
    cout << "\t3: Input a new matrix." << endl;
    cout << "\t4: Exit the program." << endl;
    cout << "Your option is [1/2/3/4]:";
}

void Helper::printAlgorithmList() {
    printShortLine();
    cout << "Please select the algorithms you want to execute:" << endl;
    cout << "\t1. Heuristic Algo." << endl;
    cout << "\t2. Approximation Algo." << endl;
    cout << "\t3. Branch and Bound." << endl;
    cout << "\t4. Heuristic and Approximation." << endl;
    cout << "\t5. Heuristic and Branch&Bound." << endl;
    cout << "\t6. Approximation and Branch&Bound." << endl;
    cout << "\t7. Heuristic and Approximation and Branch&Bound." << endl;
    cout << "\t8. Back to previous step." << endl;
    cout << "\t9. Exit the application." << endl;
    printShortLine();
    cout << "Please choose your option:";
}



void Helper::printMatrix(int **const matrix, const int length) {
    printShortLine();
    cout << "\tMatrix Information :" << endl;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j ++) {
            cout << "\t" << matrix[i][j];
        }
        cout << endl;
    }
}

void Helper::printRoute(int **const matrix, int const lenght) {
    printShortLine();
    int total = 0;
    cout << "\tRoute Information :" << endl;
    cout << "Route:" ;
    
    for(int i = 0; i < lenght; i ++) {
        cout << "\t" << matrix[0][i] << "->";
    }
    cout << endl;
    cout << "Value:";
    for(int j = 0; j < lenght; j ++) {
        cout << "\t" << matrix[1][j];
        total += matrix[1][j];
    }
    cout << endl;
    cout << "Total value:" << total << endl;
}

void Helper::printInputNewMatrix() {
    printShortLine();
    cout << "____Input a new matrix option____" << endl;
    cout << "Please insert the 'length' of square matrix:";
}

void Helper::printError(const int error) {
    printShortLine();
    switch (error) {
        case 0:
            cout << "[You inserts an invalid option! Please try again...]" << endl;
            break;
            
        default:
            break;
    }
}
