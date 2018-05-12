//
//  Branch.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Branch_h
#define Branch_h
class Branch : public IRInstruction {
public:
    std::shared_ptr<IntValue> cond;
    std::shared_ptr<BasicBlock> then;
    std::shared_ptr<BasicBlock> otherwise;
};

#endif /* Branch_h */
