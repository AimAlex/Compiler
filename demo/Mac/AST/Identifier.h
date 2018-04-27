//
//  Identifier.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Identifier_h
#define Identifier_h
#include "ASTNode.h"

class Identifier : public ASTNode{
public:
    std::string name;
    size_t pos;
//    SymbolInfo symbolInfo;
    void acceptStr(std::string str){
        name = str;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(this);
    }
};

#endif /* Identifier_h */
