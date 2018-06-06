//
//  Push.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/6.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Push_h
#define Push_h
class Push : public IRInstruction {
public:
    std::shared_ptr<target
    std::string getType(){
        return "push";
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Load>(shared_from_this()));
    }
};

#endif /* Push_h */
