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

class UnaryExpr : public ASTNode, public std::enable_shared_from_this<UnaryExpr> {
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
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    std::string gettype(){
        return "UnaryExpr";
    }
    bool isLogicalExpression(){
        if(op == LOGICAL_NOT){
            return true;
        }
        else{
            return false;
        }
    }
};

#endif /* UnaryExpr_h */
