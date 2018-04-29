//
//  VariableType.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef VariableType_h
#define VariableType_h
#include "SymbolNode.h"
class VariableType : public SymbolNode{
public:
    std::string name;
    Types type;
};

#endif /* VariableType_h */
