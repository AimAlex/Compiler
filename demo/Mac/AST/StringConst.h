//
//  StringConst.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef StringConst_h
#define StringConst_h
#include "ASTNode.h"

class StringConst : public ASTNode {
public:
    std::string value;
    StringConst(std::string str) {
        value = str;
    }
    virtual void accept(std::vector<std::shared_ptr<ASTNode>>){};
};

#endif /* StringConst_h */
