//
//  SelfIncrement.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SelfIncrement_h
#define SelfIncrement_h
#include "ASTNode.h"
class SelfIncrement : public ASTNode, public std::enable_shared_from_this<SelfIncrement>{
public:
    std::shared_ptr<ASTNode> oneself;
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        oneself = vec[0];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* SelfIncrement_h */
