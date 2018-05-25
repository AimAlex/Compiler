//
//  IntValue.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Register_h
#define Register_h
#include "IRVisitor.h"
class Register{
public:
    virtual void visited(std::shared_ptr<IRVisitor>){}
};

#endif /* IntValue_h */
