//
//  Move.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Move_h
#define Move_h
class Move : public IRInstruction {
public:
    std::shared_ptr<IntValue> dest;
    std::shared_ptr<IntValue> source;
};

#endif /* Move_h */
