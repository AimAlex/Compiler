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

class ArrayAccess : public ASTNode, public std::enable_shared_from_this<ArrayAccess>{
public:
    std::shared_ptr<ASTNode> array;
    std::shared_ptr<ASTNode> subscript;
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        array = vec[0];
        subscript = vec[1];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    bool needMemoryAccess(){
        return true;
    }
};

#endif /* ArrayAccess_h */
