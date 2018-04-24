//
//  UnaryExpr.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef UnaryExpr_h
#define UnaryExpr_h
#include "ASTNode.h"

class UnaryExpr : public ASTNode {
public:
    enum UnaryOp {
        INC, DEC, POS, NEG, LOGICAL_NOT, BITWISE_NOT
    };
    
    UnaryOp op;
    std::shared_ptr<ASTNode> body;
    size_t position;
    UnaryExpr(UnaryOp opp) {
        op = opp;
    }
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        body = vec[0];
    }
};

#endif /* UnaryExpr_h */
