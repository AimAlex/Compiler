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
class EmptyExpr : public ASTNode, public std::enable_shared_from_this<EmptyExpr>{
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* EmptyExpr_h */
