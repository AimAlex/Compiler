//
//  IntConst.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IntConst_h
#define IntConst_h
#include "ASTNode.h"

class IntConst : public ASTNode {
public:
    int value;
    IntConst(int i) {
        value = i;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(std::shared_ptr<IntConst>(this));
    }
};

#endif /* IntConst_h */
