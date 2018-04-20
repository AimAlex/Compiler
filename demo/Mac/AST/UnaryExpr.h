//
//  UnaryExpr.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef UnaryExpr_h
#define UnaryExpr_h
#include "Expr.h"
class UnaryExpr : public Expr {
    enum UnaryOp {
        INC, DEC, POS, NEG, LOGICAL_NOT, BITWISE_NOT
    }
    
    UnaryOp op;
    std::shared_ptr<Expr> body;
    size_t position;
};

#endif /* UnaryExpr_h */
