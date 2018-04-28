//
//  Program.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/25.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Program_h
#define Program_h
#include "ASTNode.h"
class Program : public ASTNode {
public:
    std::vector<std::shared_ptr<ASTNode>> decls;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec) {
        for(int i = 0; i < vec.size(); ++i) {
            decls.push_back(vec[i]);
        }
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(std::shared_ptr<Program>(this));
    }
};

#endif /* Program_h */
