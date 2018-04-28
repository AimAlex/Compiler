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

class NewExpr : public ASTNode, public std::enable_shared_from_this<NewExpr>{
public:
    std::shared_ptr<ASTNode> type;
    std::vector<std::shared_ptr<ASTNode>> dim;
    std::vector<size_t> posDim;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        type = vec[0];
        for(int i = 1; i < vec.size(); ++i) {
            dim.push_back(vec[i]);
        }
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* NewExpr_h */
