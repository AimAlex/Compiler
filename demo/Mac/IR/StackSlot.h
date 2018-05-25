//
//  StackSlot.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef StackSlot_h
#define StackSlot_h
#include "Function.h"
class StackSlot : public Register, public std::enable_shared_from_this<StackSlot> {
    std::shared_ptr<Function> parent;
    std::string hintName;
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
}

#endif /* StackSlot_h */
