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
    std::shared_ptr<ASTNode> name;
    std::vector<std::shared_ptr<ASTNode>> parameters;
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec) {
        name = vec[0];
        for(int i = 1; i < vec.size(); ++i) {
            parameters.push_back(vec[i]);
        }
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(std::shared_ptr<FunctionCall>(this));
    }
};
#endif /* FunctionCall_h */
