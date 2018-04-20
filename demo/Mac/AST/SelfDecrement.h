//
//  SelfDecrement.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SelfDecrement_h
#define SelfDecrement_h
class SelfDecrement : public Expr {
    std::shared_ptr<Expr> oneself;
    size_t posSelf;
}

#endif /* SelfDecrement_h */
