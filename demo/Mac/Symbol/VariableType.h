//
//  VariableType.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef VariableType_h
#define VariableType_h
#include "SymbolType.h"
class VariableType : public SymbolType{
public:
    std::string className;
    int demension;
    VariableType(std::string str, int n){
        className = str;
        demension = n;
    }
    std::string getName()
    {
        return className;
    }
    int getDemension(){
        return demension;
    }
    
    int getsize(){
        return 8;
    }
};

#endif /* VariableType_h */
