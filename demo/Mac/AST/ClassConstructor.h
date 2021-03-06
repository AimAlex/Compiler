//
//  ClassConstructor.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ClassConstructor_h
#define ClassConstructor_h
#include "ASTNode.h"
#include <vector>
class ClassConstructor : public ASTNode, public std::enable_shared_from_this<ClassConstructor> {
public:
    size_t position;
    std::string name;
    std::shared_ptr<ASTNode> body;
    std::shared_ptr<SymbolTable> constructorTable;
    void acceptStr(std::string str) {
        name = str;
    }
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        body = vec[0];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* ClassConstructor_h */
