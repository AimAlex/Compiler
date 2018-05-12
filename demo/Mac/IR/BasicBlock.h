//
//  BasicBlock.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BasicBlock_h
#define BasicBlock_h
#include <map>
#include "IntValue.h"
class IRInstruction;
class Function;
class BasicBlock{
public:
    std::shared_ptr<IRInstruction> head = NULL;
    std::shared_ptr<IRInstruction> last = NULL;
    bool ended = false;
    std::string hintName;
    std::shared_ptr<Function> parent;
    std::map<std::shared_ptr<IntValue>, std::shared_ptr<IRInstruction>> phi;
};

#endif /* BasicBlock_h */
