//
//  IRPrinter.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/25.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRPrinter_h
#define IRPrinter_h
#include "IRVisitor.h"
class IRPrinter : public IRVisitor, public std::enable_shared_from_this<IRPrinter>{
public:
    std::map<std::shared_ptr<VirtualRegister>, std::string> regMap;
    std::map<std::string, int> counterReg;
    std::map<std::shared_ptr<BasicBlock>, std::string> labelMap;
    std::map<std::shared_ptr<Register>, std::string> dataMap;
    std::map<std::string, int> counterBlock;
    bool definingStatic = true;
    std::map<std::shared_ptr<BasicBlock>, bool> BlockVisited;
    
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
//        std::cout<<"root"<<std::endl;
        for(int i = 0; i < node -> dataList.size(); ++i) {
            node -> dataList[i] -> visited(shared_from_this());
        }
        for(std::map<std::string, std::shared_ptr<Register>>::iterator iter = node -> strings.begin(); iter != (node -> strings.end()); ++iter) {
            iter -> second -> visited(shared_from_this());
        }
        for(std::map<std::string, std::shared_ptr<ClassRoot>>::iterator iter = node -> classList.begin(); iter != node -> classList.end(); ++iter){
            iter -> second -> visited(shared_from_this());
        }
        definingStatic = false;
        for(std::map<std::string, std::shared_ptr<Function>>::iterator iter = node -> functions.begin(); iter != (node -> functions.end()); ++iter){
            iter -> second -> visited(shared_from_this());
        }
    }
    
    void visit(std::shared_ptr<BasicBlock> node){
        if(BlockVisited.find(node) != BlockVisited.end()) return;
        BlockVisited[node] = 1;
        std::cout<<"%"<<labelId(node)<<":"<<std::endl;
//        for(std::map<std::shared_ptr<Register>, std::shared_ptr<IRInstruction>>::iterator iter = node -> phi.begin(); iter != node -> phi.end(); ++iter){
//            iter -> second -> visited(shared_from_this());
//        }
        for(std::shared_ptr<IRInstruction> i = node-> head; i != NULL; i = i -> next){
            i -> visited(shared_from_this());
            for(std::set<std::shared_ptr<Register>>::iterator iter = i -> liveIn.begin(); iter != i -> liveIn.end(); ++iter){
                std::cout<<regId(std::dynamic_pointer_cast<VirtualRegister>(*iter))<<" ";
            }
            std::cout<<std::endl;
            for(std::set<std::shared_ptr<Register>>::iterator iter = i -> liveOut.begin(); iter != i -> liveOut.end(); ++iter){
                std::cout<<regId(std::dynamic_pointer_cast<VirtualRegister>(*iter))<<" ";
            }
            std::cout<<std::endl;
        }
    }
    
    void visit(std::shared_ptr<Function> node){
        regMap.clear();
        counterReg.clear();
        std::cout<<"func "<<node -> name<<" ";
        for(int i = 0; i < node -> argVarRegList.size(); ++i) {
            std::shared_ptr<VirtualRegister> reg = std::dynamic_pointer_cast<VirtualRegister>(node -> argVarRegList[i]);
            std::cout<< "$"<<regId(reg)<<" ";
        }
        std::cout<<"{"<<std::endl;
        std::vector<std::shared_ptr<BasicBlock>> reversePostOrder(node -> getReversePostOrder());
        for(int i = 0; i < reversePostOrder.size(); ++i) {
            reversePostOrder[i] -> visited(shared_from_this());
        }
        std::cout<<"}"<<std::endl;
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
                op = "mul";
                break;
            case BinaryOperation::DIV:
                op = "div";
                break;
            case BinaryOperation::MOD:
                op = "rem";
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
        node -> dest -> visited(shared_from_this());
        std::cout<<" = "<<op<<" ";
        node -> lhs -> visited(shared_from_this());
        std::cout<<" ";
        node -> rhs -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<UnaryOperation> node){
        std::cout<<"    ";
        std::string op;
        switch (node -> op) {
            case UnaryOperation::NEG:
                op = "neg";
                break;
            case UnaryOperation::NOT:
                op = "not";
                break;
            default:
                break;
        }
        node -> dest -> visited(shared_from_this());
        std::cout<<" = "<<op<<" ";
        node -> operand -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<IntComparison> node){
        std::cout<<"    ";
        std::string op;
        switch (node -> cond) {
            case IntComparison::EQ:
                op = "seq";
                break;
            case IntComparison::NE:
                op = "sne";
                break;
            case IntComparison::GT:
                op = "sgt";
                break;
            case IntComparison::GE:
                op = "sge";
                break;
            case IntComparison::LT:
                op = "slt";
                break;
            case IntComparison::LE:
                op = "sle";
                break;
            default:
                break;
        }
        node -> dest -> visited(shared_from_this());
        std::cout<<" = "<<op<<" ";
        node -> lhs -> visited(shared_from_this());
        std::cout<<" ";
        node -> rhs -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<IntImmediate> node){
        std::cout<<node -> value;
    }
    //    void visit(Call node);
    //    void visit(SystemCall node);
    //    void visit(PhiInstruction node);
    //
    void visit(std::shared_ptr<Branch> node){
        std::cout<<"    br ";
        node -> cond -> visited(shared_from_this());
        std::cout<<" %"<<labelId(node -> getThen()) << " %"<<labelId(node -> getElse());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<Return> node){
        std::cout<<"    ret ";
        if(node -> ret != NULL){
            node -> ret -> visited(shared_from_this());
        }
        std::cout<<std::endl<<std::endl;
    }
    void visit(std::shared_ptr<Jump> node){
        std::cout<<"    jump %"<<labelId(node -> target)<<std::endl<<std::endl;
    }
    
    void visit(std::shared_ptr<VirtualRegister> node){
        std::cout<<"$"<<regId(node);
    }

    void visit(std::shared_ptr<HeapAllocate> node){
        std::cout<<"    ";
        node -> dest -> visited(shared_from_this());
        std::cout<<" = alloc ";
        node -> allocSize -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<Load> node){
        std::cout<<"    ";
        node -> dest -> visited(shared_from_this());
        std::cout<<" = load "<<node -> size<<" ";
        node -> address -> visited(shared_from_this());
        std::cout<<" "<<node -> offset << std::endl;
    }
    void visit(std::shared_ptr<Store> node){
        std::cout<<"    store "<<node -> size<<" ";
        node -> address -> visited(shared_from_this());
        std::cout<<" ";
        node -> value -> visited(shared_from_this());
        std::cout<<" "<<node -> offset<< std::endl;
    }
    void visit(std::shared_ptr<Move> node){
        std::cout<<"    ";
        node -> dest -> visited(shared_from_this());
        std::cout<<" = move ";
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
        if(node -> dest != NULL){
            node -> dest -> visited(shared_from_this());
            std::cout<<" = ";
        }
        std::cout<<"call "<<node -> func -> name<<" ";
        for(int i = 0; i < node -> args.size(); ++i) {
            node -> args[i] -> visited(shared_from_this());
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<ClassRoot> node) {
        if(node -> constructor != NULL){
            node -> constructor -> visited(shared_from_this());
        }
        for(std::map<std::string, std::shared_ptr<Function>>::iterator iter = node -> functions.begin(); iter != node -> functions.end(); ++iter) {
            iter -> second -> visited(shared_from_this());
        }
    }
    
    void visit(std::shared_ptr<PhysicalRegister>){}
    void visit(std::shared_ptr<StackSlot>){}
};

#endif /* IRPrinter_h */
