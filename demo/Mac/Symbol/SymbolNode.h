//
//  SymbolNode.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SymbolNode_h
#define SymbolNode_h
#include "SymbolType.h"
#include "Register.h"
class SymbolTable;
class SymbolNode{
public:
    std::shared_ptr<SymbolType> type;
    std::shared_ptr<SymbolTable> table;
    std::shared_ptr<Register> reg = NULL;
};

#endif /* SymbolNode_h */
