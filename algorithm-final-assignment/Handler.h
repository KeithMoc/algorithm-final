//
//  Handler.h
//  algorithm-final-assignment
//
//  Created by Keith-PC on 2015/1/16.
//  Copyright (c) 2015年 KeithM. All rights reserved.
//

#ifndef __algorithm_final_assignment__Handler__
#define __algorithm_final_assignment__Handler__

#include "main.h"


class Handler {
private:
    int ** gintInputMatrix;
    int gintLength;
public:
    
    Handler(){};
    void handleAlgorithm(int const input);
    void handleInput(int const input);
    void chooseAlgorithm();
    
};

#endif /* defined(__algorithm_final_assignment__Handler__) */
