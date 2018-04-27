//
//  ArrayAccess.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ArrayAccess_h
#define ArrayAccess_h
#include "ASTNode.h"

class ArrayAccess : public ASTNode{
    std::shared_ptr<ASTNode> array;
    std::shared_ptr<ASTNode> subscript;
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        array = vec[0];
        subscript = vec[1];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(this);
    }
};

#endif /* ArrayAccess_h */
