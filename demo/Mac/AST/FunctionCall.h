//
//  FunctionCall.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef FunctionCall_h
#define FunctionCall_h
#include "ASTNode.h"
#include <vector>
class FunctionCall : public ASTNode {
    std::shared_ptr<Expr> name;
    std::vector<std::shared_ptr<Expr>> parameters;
    size_t position;
//    Expr argThis = null;
#endif /* FunctionCall_h */
