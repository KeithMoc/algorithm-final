//
//  Helper.cpp
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/15.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#include "Helper.h"

/*!
 * @brief display program description when it is started
 */
void Helper::displayDescription() {
    string line = "*******************************************************************************";
    cout << line << endl;
    cout << "\t\tAlgorithm Final Assignment" << endl;
    cout << line << endl;
    cout << "Please choose your options:" << endl;
    cout << "\t1: Use default matrix 1." << endl;
    cout << "\t2: Use default matrix 2." << endl;
    cout << "\t3: Input a new matrix." << endl;
    cout << "\t4: Exit the program." << endl;
    cout << "Your option is [1/2/3/4]:";
}


