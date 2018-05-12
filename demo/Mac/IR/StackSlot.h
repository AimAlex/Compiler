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
class StackSlot : public IntValue {
    std::shared_ptr<Function> parent;
    std::string hintName;
}

#endif /* StackSlot_h */
