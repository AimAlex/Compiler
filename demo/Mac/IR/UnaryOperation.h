//
//  UnaryOperation.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef UnaryOperation_h
#define UnaryOperation_h
#include "IRInstruction.h"
class UnaryOperation : public IRInstruction {
public:
    enum UnaryOp{
        NEG, NOT
    };
    std::shared_ptr<Register> dest;
    UnaryOp op;
    std::shared_ptr<Register> operand;
    
    UnaryOperation(std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> Dest, UnaryOp Op, std::shared_ptr<Register> Operand) : IRInstruction(Block) {
        dest = Dest;
        op = Op;
        operand = Operand;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<UnaryOperation>(shared_from_this()));
    }
    
    std::shared_ptr<Register> getDefRegister(){
        return dest;
        
    }
    
    void setDefRegister(std::shared_ptr<Register> reg){
        dest = reg;
    }
    std::vector<std::shared_ptr<Register>> getRegister(){
        std::vector<std::shared_ptr<Register>> vec;
//        if(dest -> getType() == "VirtualRegister"){
//            vec.push_back(dest);
//        }
        if(operand -> getType() == "VirtualRegister"){
            vec.push_back(operand);
        }
        return vec;
    }
    void refreshRegister(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<PhysicalRegister>> allocMap){
        if(operand -> getType() == "VirtualRegister"){
            operand = allocMap[(std::dynamic_pointer_cast<VirtualRegister>(operand))];
        }
    }
};

#endif /* UnaryOperation_h */
