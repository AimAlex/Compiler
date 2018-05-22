//
//  Move.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Move_h
#define Move_h
#include "IRInstruction.h"
class Move : public IRInstruction {
public:
    std::shared_ptr<Register> dest;
    std::shared_ptr<Register> source;
    Move(std::shared_ptr<BasicBlock> BB, std::shared_ptr<Register> destination, std::shared_ptr<Register> sour) : IRInstruction(BB){
        dest = destination;
        source = sour;
//        reloadUsedRegisterCollection();
    }
};

#endif /* Move_h */
