//
//  Store.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Store_h
#define Store_h
#include "IRInstruction.h"
class Store : public IRInstruction {
public:
    int size;
    std::shared_ptr<Register> address;
    int offset;
    std::shared_ptr<Register> value;
    bool isStaticData;
    Store(std::shared_ptr<BasicBlock> BB, std::shared_ptr<Register> val, int s, std::shared_ptr<Register> addr, int off):IRInstruction(BB) {
        size = s;
        address = addr;
        offset = off;
        value = val;
        isStaticData = false;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Store>(shared_from_this()));
    }
};

#endif /* Store_h */
