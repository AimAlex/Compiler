//
//  NewExpr.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef NewExpr_h
#define NewExpr_h
#include "ASTNode.h"
#include <vector>

class NewExpr : public ASTNode{
    std::shared_ptr<TypeNode> type;
    std::vector<std::shared_ptr<Expr>> dim;
    std::vector<size_t> posDim;
};

#endif /* NewExpr_h */
