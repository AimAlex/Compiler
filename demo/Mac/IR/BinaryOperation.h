//
//  BinaryOperation.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BinaryOperation_h
#define BinaryOperation_h
#include "IRInstruction.h"
class BinaryOperation : public IRInstruction{
public:
    enum BinaryOp {
        ADD, SUB, MUL, DIV, MOD, SHL, SHR, AND, OR, XOR
    };
    std::shared_ptr<Register> dest;
    BinaryOp op;
    std::shared_ptr<Register> lhs;
    std::shared_ptr<Register> rhs;
    
    BinaryOperation(std::shared_ptr<BasicBlock> Block, std::shared_ptr<Register> destination, BinaryOp Op, std::shared_ptr<Register> Lhs, std::shared_ptr<Register> Rhs) : IRInstruction(Block){
        dest = destination;
        op = Op;
        lhs = Lhs;
        rhs = Rhs;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(std::dynamic_pointer_cast<BinaryOperation>(shared_from_this()));
    }
    
    std::shared_ptr<Register> getDefRegister(){
        return dest;
        
    }
    std::vector<std::shared_ptr<Register>> getRegister(){
        std::vector<std::shared_ptr<Register>> vec;
//        if(dest -> getType() == "VirtualRegister"){
//            vec.push_back(dest);
//        }
        if(lhs -> getType() == "VirtualRegister"){
            vec.push_back(lhs);
        }
        if(rhs -> getType() == "VirtualRegister"){
            vec.push_back(rhs);
        }
        return vec;
    }
    
    void refreshRegister(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<PhysicalRegister>> allocMap){
        if(lhs -> getType() == "VirtualRegister"){
            lhs = allocMap[std::dynamic_pointer_cast<VirtualRegister>(lhs)];
        }
        if(rhs -> getType() == "VirtualRegister"){
            rhs = allocMap[std::dynamic_pointer_cast<VirtualRegister>(rhs)];
        }
    }
    
    void setDefRegister(std::shared_ptr<Register> reg){
        dest = reg;
    }
};

#endif /* BinaryOperation_h */
