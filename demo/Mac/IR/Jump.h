//
//  Jump.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Jump_h
#define Jump_h
class Jump : public IRInstruction {
public:
    std::shared_ptr<BasicBlock> target;
    Jump(std::shared_ptr<BasicBlock> BB, std::shared_ptr<BasicBlock> tar) : IRInstruction(BB){
        target = tar;
    }
    
    std::string getType(){
        return "Jump";
    }
    
    std::shared_ptr<BasicBlock> getTarget(){
        return target;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<Jump>(shared_from_this()));
    }
    std::shared_ptr<Register> getDefRegister(){
        return NULL;
        
    }
    std::vector<std::shared_ptr<Register>> getRegister(){
        std::vector<std::shared_ptr<Register>> vec;
        return vec;
    }
};

#endif /* Jump_h */
