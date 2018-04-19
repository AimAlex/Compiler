//
//  ArrayAccess.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/19.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef ArrayAccess_h
#define ArrayAccess_h
#include "Expr.h"

class ArrayAccess : public Expr{
    std::shared_ptr<Expr> array;
    std::shared_ptr<Expr> subscript;
    size_t position;
};

#endif /* ArrayAccess_h */
