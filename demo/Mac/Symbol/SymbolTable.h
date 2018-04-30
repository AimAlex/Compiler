//
//  SymbolTable.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/29.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SymbolTable_h
#define SymbolTable_h
#include "SymbolNode.h"
#include <map>
#include <vector>
class SymbolTable{
public:
    std::map<std::string, std::shared_ptr<SymbolNode>> symbolTable;
    std::string name;
    void add(std::string str, std::shared_ptr<SymbolNode> node){
        if(symbolTable.find(str) != symbolTable.end()){
            std::cout<<"exist symbol"<<std::endl;
            exit(1);
        }
        symbolTable[str] = node;
    }
};

#endif /* SymbolTable_h */
