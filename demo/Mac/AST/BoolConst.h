//
//  BoolConst.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BoolConst_h
#define BoolConst_h
#include "ASTNode.h"
class BoolConst : public ASTNode, public std::enable_shared_from_this<BoolConst>{
public:
    bool value;
    BoolConst(bool i){
        value = i;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* BoolConst_h */
