//
//  BinaryExpr.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BinaryExpr_h
#define BinaryExpr_h

#include "ASTNode.h"
class BinaryExpr : public ASTNode, public std::enable_shared_from_this<BinaryExpr> {
public:
    enum BinaryOp {
        ASSIGN,
        LOGICAL_OR, LOGICAL_AND,
        BITWISE_OR, BITWISE_AND, XOR,
        EQ, NE, LT, GT, LE, GE,
        SHL, SHR,
        ADD, SUB,
        MUL, DIV, MOD
    };
    BinaryOp op;
    std::shared_ptr<ASTNode> lhs;
    std::shared_ptr<ASTNode> rhs;
    size_t position;
   BinaryExpr(BinaryOp opp) {
        op = opp;
    }
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        lhs = vec[0];
        rhs = vec[1];
    }
    std::string gettype(){
        return "BinaryExpr";
    }
    bool isLogicalExpression(){
        if(op == LOGICAL_AND || op == LOGICAL_OR){
            return true;
        }
        else{
            return false;
        }
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};


#endif /* BinaryExpr_h */
