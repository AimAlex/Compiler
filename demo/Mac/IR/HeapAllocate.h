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
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<HeapAllocate>(shared_from_this()));
    }
    std::shared_ptr<Register> getDefRegister(){
        return dest;
    }
    std::vector<std::shared_ptr<Register>> getRegister(){
        std::vector<std::shared_ptr<Register>> vec;
//        if(dest -> getType() == "VirtualRegister"){
//            vec.push_back(dest);
//        }
        if(allocSize -> getType() == "VirtualRegister"){
            vec.push_back(allocSize);
        }
        return vec;
    }
};

#endif /* HeapAllocate_h */
