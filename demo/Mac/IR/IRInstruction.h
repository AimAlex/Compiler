//
//  IRInstruction.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRInstruction_h
#define IRInstruction_h
#include "BasicBlock.h"
#include "IntValue.h"
#include <vector>
class IRInstruction {
public:
    BasicBlock curBlock;
    std::shared_ptr<IRInstruction> prev = NULL;
    std::shared_ptr<IRInstruction> next = NULL;
    bool removed = false;
    std::vector<IntValue> usedReg;
    std::vector<IntValue> usedIntValue;
    
};

#endif /* IRInstruction_h */
