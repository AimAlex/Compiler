//
//  FunctionType.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef FunctionType_h
#define FunctionType_h
#include "SymbolNode.h"
#include "VariableType.h"
#include <vector>
class FunctionType : public SymbolNode{
public:
    std::shared_ptr<SymbolNode> returnType;
    std::string name;
    std::vector<std::shared_ptr<SymbolNode>> argType;
};


#endif /* FunctionType_h */
