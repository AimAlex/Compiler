//
//  HeapAllocate.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef HeapAllocate_h
#define HeapAllocate_h
#include "IRInstruction.h"
class HeapAllocate : public IRInstruction {
public:
    std::shared_ptr<Register> dest;
    std::shared_ptr<Register> allocSize;
    HeapAllocate(std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> Dest, std::shared_ptr<Register> allocsize) : IRInstruction(Block){
        dest = Dest;
        allocSize = allocsize;
    }
};

#endif /* HeapAllocate_h */
