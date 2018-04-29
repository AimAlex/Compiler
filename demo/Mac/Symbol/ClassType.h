//
//  ClassType.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ClassType_h
#define ClassType_h
#include "SymbolNode.h"
class ClassType : public SymbolNode{
public:
    std::string name;
    ClassType(std::string str) {
        name = str;
    }
//    SymbolTable members;
};

#endif /* ClassType_h */
