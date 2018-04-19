//
//  ClassConstructor.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ClassConstructor_h
#define ClassConstructor_h

#include "CompoundState.h"
class ClassConstructor{
public:
    size_t position;
    std::shared_ptr<CompoundState> body;
};

#endif /* ClassConstructor_h */
