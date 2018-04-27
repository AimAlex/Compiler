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
#include "CompoundState.h"
#include <vector>
class ClassConstructor : public ASTNode{
public:
    size_t position;
    std::string name;
    std::shared_ptr<ASTNode> body;
    void acceptStr(std::string str) {
        name = str;
    }
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        body = vec[0];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(this);
    }
};

#endif /* ClassConstructor_h */
