//
//  SystemCall.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef SystemCall_h
#define SystemCall_h
class SystemCall : public IRInstruction{
public:
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<IRInstruction>(shared_from_this()));
    }
};

#endif /* SystemCall_h */
