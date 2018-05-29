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
    std::string name;
    FunctionType(std::vector<std::shared_ptr<SymbolType>> vec, std::string str){
        returnType = vec[0];
        for(int i = 1; i < vec.size(); ++i) {
            argType.push_back(vec[i]);
        }
        name = str;
//        std::cout<<vec.size()<<std::endl;
    }
    FunctionType(std::string str){
        name = str;
    }
    std::vector<std::shared_ptr<SymbolType>> getFunction(){
        std::vector<std::shared_ptr<SymbolType>> vec;
        vec.push_back(returnType);
        for(int i = 0; i < argType.size(); ++i){
            vec.push_back(argType[i]);
        }
        return vec;
    }
    std::string getName(){return name;}
};


#endif /* FunctionType_h */
