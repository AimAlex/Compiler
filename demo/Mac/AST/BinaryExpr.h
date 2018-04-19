//
//  BinaryExpr.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BinaryExpr_h
#define BinaryExpr_h

#include "Expr.h"
class BinaryExpr : public Expr {
    enum BinaryOp {
        ASSIGN,
        LOGICAL_OR, LOGICAL_AND,
        BITWISE_OR, BITWISE_AND, XOR,
        EQ, NE, LT, GT, LE, GE,
        SHL, SHR,
        ADD, SUB,
        MUL, DIV, MOD
    }
    BinaryOp op;
    std::shared_ptr<Expr> lhs;
    std::shared_ptr<Expr> rhs;
    size_t position;
};


#endif /* BinaryExpr_h */
