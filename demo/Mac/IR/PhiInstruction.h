//
//  PhiInstruction.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef PhiInstruction_h
#define PhiInstruction_h
#include <map>
class PhiInstruction : public IRInstruction{
public:
    BasicBlock Block;
    std::shared_ptr<IntValue> dest;
    std::map<std::shared_ptr<BasicBlock>, std::shared_ptr<IntValue>> paths;
};

#endif /* PhiInstruction_h */