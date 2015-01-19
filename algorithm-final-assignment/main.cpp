//
//  main.cpp
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/15.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#include "Helper.h"
#include "Handler.h"
#include "Algorithm.h"

// store current input option
int gintOption;


int main(int argc, const char * argv[]) {
    // insert code here...
    Handler handler;
    bool flag = true;
    do {
        if(flag) {
            Helper::printTitle();
            Helper::printDescription();
            cin >> gintOption;
        }
        else {
            Helper::printError(0);
            Helper::printDescription();
            cin >> gintOption;
        }
        flag = false;
    } while (gintOption < 1 || gintOption > 4);
    handler.handleInput(gintOption);
    
    return 0;
}
