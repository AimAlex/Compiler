//
//  FunctionType.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef FunctionType_h
#define FunctionType_h
#include "SymbolType.h"
#include "VariableType.h"
#include <vector>
class FunctionType : public SymbolType{
public:
    std::shared_ptr<SymbolType> returnType;
    std::vector<std::shared_ptr<SymbolType>> argType;
};


#endif /* FunctionType_h */
