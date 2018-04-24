//
//  BoolConst.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BoolConst_h
#define BoolConst_h
#include "ASTNode.h"
class BoolConst : public ASTNode{
public:
    bool value;
    BoolConst(bool i){
        value = i;
    }
};

#endif /* BoolConst_h */
