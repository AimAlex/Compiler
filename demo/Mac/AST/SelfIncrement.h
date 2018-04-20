//
//  SelfIncrement.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SelfIncrement_h
#define SelfIncrement_h
#include "expr.h"
class SelfIncrement : public Expr{
    shared_ptr<Expr> oneself;
    size_t posSelf;
};

#endif /* SelfIncrement_h */
