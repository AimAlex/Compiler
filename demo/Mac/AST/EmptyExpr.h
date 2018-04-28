//
//  EmptyExpr.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef EmptyExpr_h
#define EmptyExpr_h

#include "ASTNode.h"
class EmptyExpr : public ASTNode{
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(std::shared_ptr<EmptyExpr>(this));
    }
};

#endif /* EmptyExpr_h */
