//
//  Load.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Load_h
#define Load_h
#include "IRInstruction.h"
class Load : public IRInstruction {
public:
    std::shared_ptr <Register> dest;
    int size;
    std::shared_ptr <Register> address;
    int offset;
    bool isStaticData;
    bool isLoadAddress;
    Load(std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> Dest, int n, std::shared_ptr<Register> Address, int Offset) : IRInstruction(Block){
        dest = Dest;
        size = n;
        address = Address;
        offset = Offset;
        isStaticData = false;
        
    }
};

#endif /* Load_h */
