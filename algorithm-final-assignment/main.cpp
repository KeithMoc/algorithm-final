//
//  main.cpp
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/15.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#include "Helper.h"
#include "Handler.h"

// store current input option
int gintOption;


int main(int argc, const char * argv[]) {
    // insert code here...
    Helper::displayDescription();
    Handler handler;
    cin >> gintOption;
    return handler.handleInput(gintOption);
}
