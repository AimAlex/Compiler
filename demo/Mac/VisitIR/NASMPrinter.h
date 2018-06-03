//
//  RegisterAllocatorPrinter.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/1.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef RegisterAllocatorPrinter_h
#define RegisterAllocatorPrinter_h
#include "IRVisitor.h"
class NASMPrinter : public IRVisitor, public std::enable_shared_from_this<NASMPrinter>{
public:
    std::map<std::shared_ptr<VirtualRegister>, std::string> regMap;
    std::map<std::string, int> counterReg;
    std::map<std::shared_ptr<BasicBlock>, std::string> labelMap;
    std::map<std::shared_ptr<Register>, std::string> dataMap;
    std::map<std::string, int> counterBlock;
    bool definingStatic = true;
    std::map<std::shared_ptr<BasicBlock>, bool> BlockVisited;
    std::string jump;
    int stackSize;
    
    std::string newRegId(std::string name){
        int cnt = counterReg[name] + 1;
        counterReg[name] = cnt;
        if(cnt == 1) return name;
        return name + "_" + std::to_string(cnt);
    }
    
    std::string newId(std::string name){
        int cnt = counterBlock[name] + 1;
        counterBlock[name] = cnt;
        if(cnt == 1) return name;
        return name + "_" + std::to_string(cnt);
    }
    
    std::string regId(std::shared_ptr<VirtualRegister> reg) {
        std::map<std::shared_ptr<VirtualRegister>, std::string>::iterator iter = regMap.find(reg);
        if(iter == regMap.end()){
            if(reg -> oldName != NULL) {
                regMap[reg] = regId(std::dynamic_pointer_cast<VirtualRegister>(reg -> oldName));
            }
            else if(reg -> hintName.empty()){
                regMap[reg] = newRegId("t");
            }
            else{
                regMap[reg] = newRegId(reg -> hintName);
            }
        }
        return regMap[reg];
    }
    
    std::string labelId(std::shared_ptr<BasicBlock> Block){
        std::map<std::shared_ptr<BasicBlock>, std::string>::iterator iter = labelMap.find(Block);
        if(iter == labelMap.end()){
            labelMap[Block] = newId(Block -> hintName);
        }
        return labelMap[Block];
    }
    
    std::string dataId(std::shared_ptr<Register> data) {
        std::map<std::shared_ptr<Register>, std::string>::iterator iter = dataMap.find(data);
        if(iter == dataMap.end()){
            dataMap[data] = newId(data -> getHintName());
        }
        return dataMap[data];
    }
    
    void visit(std::shared_ptr<IRRoot> node){
         std::cout<<"EXTERN malloc"<<std::endl;
        for(int i = 0; i < node -> dataList.size(); ++i) {
            node -> dataList[i] -> visited(shared_from_this());
        }
        for(std::map<std::string, std::shared_ptr<Register>>::iterator iter = node -> strings.begin(); iter != (node -> strings.end()); ++iter) {
            iter -> second -> visited(shared_from_this());
        }
        for(std::map<std::string, std::shared_ptr<ClassRoot>>::iterator iter = node -> classList.begin(); iter != node -> classList.end(); ++iter){
            iter -> second -> visited(shared_from_this());
        }
        for(std::map<std::string, std::shared_ptr<Function>>::iterator iter = node -> functions.begin(); iter != (node -> functions.end()); ++iter){
            std::cout<<"global "<<iter -> second -> name<<std::endl;
        }
        definingStatic = false;
        std::cout<<"SECTION .text"<<std::endl;
        for(std::map<std::string, std::shared_ptr<Function>>::iterator iter = node -> functions.begin(); iter != (node -> functions.end()); ++iter){
            iter -> second -> visited(shared_from_this());
        }
        std::cout<<"SECTION .data"<<std::endl;
        std::cout<<"SECTION .bbs"<<std::endl;
    }
    
    void visit(std::shared_ptr<BasicBlock> node){
        if(BlockVisited.find(node) != BlockVisited.end()) return;
        BlockVisited[node] = 1;
        std::cout<<labelId(node)<<":"<<std::endl;
        for(std::map<std::shared_ptr<Register>, std::shared_ptr<IRInstruction>>::iterator iter = node -> phi.begin(); iter != node -> phi.end(); ++iter){
            iter -> second -> visited(shared_from_this());
        }
        for(std::shared_ptr<IRInstruction> i = node-> head; i != NULL; i = i -> next){
            i -> visited(shared_from_this());
        }
    }
    
    void visit(std::shared_ptr<Function> node){
        std::cout<<node -> name<<": "<<std::endl;
        std::vector<std::shared_ptr<BasicBlock>> reversePostOrder(node -> getReversePostOrder());
        std::cout<<"    "<<"push rbp"<<std::endl;
        std::cout<<"    "<<"mov rbp, rsp"<<std::endl;
        std::cout<<"    "<<"sub rsp, "<<node -> stackSize<<std::endl;
        stackSize = node -> stackSize;
        for(int i = 0; i < reversePostOrder.size(); ++i) {
            reversePostOrder[i] -> visited(shared_from_this());
        }
    }
    
    void visit(std::shared_ptr<BinaryOperation> node){
        std::cout<<"    ";
        std::string op;
        switch (node -> op) {
            case BinaryOperation::ADD:
                op = "add";
                break;
            case BinaryOperation::SUB:
                op = "sub";
                break;
            case BinaryOperation::MUL:
                op = "imul";
                break;
            case BinaryOperation::DIV:
                op = "idiv";
                break;
            case BinaryOperation::MOD:
                op = "idiv";
                break;
            case BinaryOperation::SHL:
                op = "shl";
                break;
            case BinaryOperation::SHR:
                op = "shr";
                break;
            case BinaryOperation::AND:
                op = "and";
                break;
            case BinaryOperation::OR:
                op = "or";
                break;
            case BinaryOperation::XOR:
                op = "xor";
                break;
            default:
                break;
        }
        if(op == "idiv"){
            std::cout<<op<<" ";
            node -> rhs -> visited(shared_from_this());
            std::cout<<std::endl;
        }
        else{
            std::cout<<op<<" ";
            node -> lhs -> visited(shared_from_this());
            std::cout<<", ";
            node -> rhs -> visited(shared_from_this());
            std::cout<<std::endl;
        }
    }
    void visit(std::shared_ptr<UnaryOperation> node){
        std::cout<<"    ";
        std::string op = "neg";
        std::cout<<op<<" ";
        node -> operand -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<IntComparison> node){
        std::cout<<"    ";
        std::string op;
        switch (node -> cond) {
            case IntComparison::EQ:
                op = "je";
                break;
            case IntComparison::NE:
                op = "jne";
                break;
            case IntComparison::GT:
                op = "jg";
                break;
            case IntComparison::GE:
                op = "jge";
                break;
            case IntComparison::LT:
                op = "jl";
                break;
            case IntComparison::LE:
                op = "jle";
                break;
            default:
                break;
        }
        std::cout<<"cmp ";
        node -> lhs -> visited(shared_from_this());
        std::cout<<", ";
        node -> rhs -> visited(shared_from_this());
        std::cout<<std::endl;
        jump = op;
        
    }
    void visit(std::shared_ptr<IntImmediate> node){
        std::cout<<node -> value;
    }
    //    void visit(Call node);
    //    void visit(SystemCall node);
    //    void visit(PhiInstruction node);
    //
    void visit(std::shared_ptr<Branch> node){
        std::cout<<"    "<<jump;
        std::cout<<" "<<labelId(node -> getThen());
        std::cout<<std::endl;
        std::cout<<"    "<<"jmp";
        std::cout<<" "<<labelId(node -> getElse());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<Return> node){
        std::cout<<"    "<<"add rsp, "<<stackSize<<std::endl;
        std::cout<<"    pop rbp"<<std::endl;
        std::cout<<"    ret ";
        std::cout<<std::endl<<std::endl;
    }
    void visit(std::shared_ptr<Jump> node){
        std::cout<<"    jmp "<<labelId(node -> target)<<std::endl<<std::endl;
    }
    
    void visit(std::shared_ptr<VirtualRegister> node){
        std::cout<<"nonononono"<<regId(node);
    }
    //    void visit(PhysicalRegister node);
    //    void visit(StackSlot node);
    void visit(std::shared_ptr<HeapAllocate> node){
        std::cout<<"    ";
        std::cout<<"call malloc";
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<Load> node){
        std::cout<<"    mov ";
        node -> dest -> visited(shared_from_this());
        std::cout<<", qword [";
        node -> address -> visited(shared_from_this());
        std::cout<<"+"<<node -> offset <<"H]"<< std::endl;
    }
    void visit(std::shared_ptr<Store> node){
        std::cout<<"    mov qword [";
        node -> address -> visited(shared_from_this());
        std::cout<<"+"<<node -> offset<<"H],";
        std::cout<<" ";
        node -> value -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<Move> node){
        std::cout<<"    ";
        std::cout<<"mov ";
        node -> dest -> visited(shared_from_this());
        std::cout<<", ";
        node -> source -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    
    void visit(std::shared_ptr<StaticSpace> node){
        if(definingStatic) {
            std::cout<<"space @"<<dataId(node)<<" "<<node -> length<<std::endl;
        }
        else{
            std::cout<<"@"<<dataId(node);
        }
    }
    void visit(std::shared_ptr<StaticString> node){
        if(definingStatic) {
            std::cout<<"asciiz @"<<dataId(node)<<" "<<node -> value<<std::endl;
        }
        else{
            std::cout<<"@"<<dataId(node);
        }
    }
    void visit(std::shared_ptr<Call> node){
        std::cout<<"    ";
        std::cout<<"call "<<node -> func -> name<<std::endl;
    }
    void visit(std::shared_ptr<ClassRoot> node) {
        if(node -> constructor != NULL){
            node -> constructor -> visited(shared_from_this());
        }
        for(std::map<std::string, std::shared_ptr<Function>>::iterator iter = node -> functions.begin(); iter != node -> functions.end(); ++iter) {
            iter -> second -> visited(shared_from_this());
        }
    }
    void visit(std::shared_ptr<PhysicalRegister> node){
        std::cout<<node -> name;
    }
    void visit(std::shared_ptr<StackSlot> node){
        std::cout<<"qword [rbp-"<<node -> offset + 8<<"H]";
    }
};

#endif /* RegisterAllocatorPrinter_h */
