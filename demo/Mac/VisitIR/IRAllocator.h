//
//  IRAllocator.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/1.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRAllocator_h
#define IRAllocator_h
#include "IRVisitor.h"
class IRAllocator : public IRVisitor, public std::enable_shared_from_this<IRAllocator>{
public:
    std::map<std::shared_ptr<VirtualRegister>, std::string> regMap;
    std::map<std::string, int> counterReg;
    std::map<std::shared_ptr<BasicBlock>, std::string> labelMap;
    std::map<std::shared_ptr<Register>, std::string> dataMap;
    std::map<std::string, int> counterBlock;
    bool definingStatic = true;
    
    std::map<std::shared_ptr<BasicBlock>, bool> BlockVisited;
    
    std::shared_ptr<Function> curFunction;
    std::shared_ptr<IRInstruction> curInstruction;
    std::shared_ptr<BasicBlock> curBlock;
    
    std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<StackSlot>> slots;
    long long LRURegister[16];
    std::shared_ptr<Register> phy2vir[16];
    std::map<std::shared_ptr<Register>, std::shared_ptr<PhysicalRegister>> phyRegMap;
    
    std::string jump = "";
    
    
    std::shared_ptr<StackSlot> getSlot(std::shared_ptr<VirtualRegister> vr){
        if(slots.find(vr) == slots.end()) {
            slots[vr] = std::shared_ptr<StackSlot> (new StackSlot(curFunction, vr -> hintName, curFunction -> stackSize));
            curFunction -> stackSize += 8;
//            std::cout<<"hhh"<<std::endl;
        }
        return slots.find(vr) -> second;
    }
    
    std::shared_ptr<PhysicalRegister> destReg(std::shared_ptr<Register> reg, std::shared_ptr<PhysicalRegister> dest){
        if(slots.find(std::dynamic_pointer_cast<VirtualRegister>(phy2vir[dest -> no])) != slots.end()){
            curInstruction -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, getSlot(std::dynamic_pointer_cast<VirtualRegister>(phy2vir[dest -> no])), dest)));
            curInstruction -> prev -> visited(shared_from_this());
        }
        if(phyRegMap[reg] != NULL){
            phy2vir[phyRegMap[reg] -> no] = NULL;
            LRURegister[phyRegMap[reg] -> no] = 0;
            phyRegMap[reg] = NULL;
        }
//        getSlot(std::dynamic_pointer_cast<VirtualRegister>(reg));
        phyRegMap[phy2vir[dest -> no]] = NULL;
        phy2vir[dest -> no] = reg;
        phyRegMap[reg] = std::shared_ptr<PhysicalRegister> (new PhysicalRegister(dest -> name));
        for(int i = 0; i < 16; ++i) {
            if(i == dest -> no){
                LRURegister[i] = 1;
                continue;
            }
            if(LRURegister[i] == 0) continue;
            else{
                LRURegister[i]++;
            }
        }
        return phyRegMap[reg];
    }
    
    std::shared_ptr<PhysicalRegister> assignReg(std::shared_ptr<Register> reg, std::shared_ptr<PhysicalRegister> dest){
        if(phyRegMap.find(reg) != phyRegMap.end() && phyRegMap[reg] != NULL && phyRegMap[reg]->no == dest -> no){
            for(int i = 1; i < 16; ++i) {
                if(i == 3 || i == 6 || i == 7)  continue;
                if(i == dest -> no){
                    LRURegister[i] = 1;
                    continue;
                }
                if(LRURegister[i] == 0) continue;
                else{
                    LRURegister[i]++;
                }
            }
            return dest;
        }
        
        if(slots.find(std::dynamic_pointer_cast<VirtualRegister>(phy2vir[dest -> no])) != slots.end()){
            curInstruction -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, getSlot(std::dynamic_pointer_cast<VirtualRegister>(phy2vir[dest -> no])), dest)));
            curInstruction -> prev -> visited(shared_from_this());
        }
        
        std::shared_ptr<PhysicalRegister> ptr (new PhysicalRegister(dest -> name));
        if(phyRegMap.find(reg) != phyRegMap.end() && phyRegMap[reg] != NULL){
            curInstruction -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, ptr, phyRegMap[reg])));
            phy2vir[phyRegMap[reg] -> no] = NULL;
            LRURegister[phyRegMap[reg] -> no] = 0;
            phyRegMap[reg] = NULL;
            curInstruction -> prev -> visited(shared_from_this());
        }
        else if(reg -> getType() == "IntImmediate"){
            curInstruction -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, ptr, reg)));
            curInstruction -> prev -> visited(shared_from_this());
        }
        else if(slots.find(std::dynamic_pointer_cast<VirtualRegister>(reg)) != slots.end()){
            curInstruction -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, ptr, getSlot(std::dynamic_pointer_cast<VirtualRegister>(reg)))));
            curInstruction -> prev -> visited(shared_from_this());
        }
        else{
            getSlot(std::dynamic_pointer_cast<VirtualRegister>(reg));
        }
        phyRegMap[phy2vir[dest -> no]] = NULL;
        phy2vir[dest -> no] = reg;
        phyRegMap[reg] = std::shared_ptr<PhysicalRegister> (new PhysicalRegister(dest -> name));
        for(int i = 1; i < 16; ++i) {
            if(i == 3 || i == 6 || i == 7)  continue;
            if(i == dest -> no){
                LRURegister[i] = 1;
                continue;
            }
            if(LRURegister[i] == 0) continue;
            else{
                LRURegister[i]++;
            }
        }
        return phyRegMap[reg];
    }
    
    std::shared_ptr<PhysicalRegister> getReg(std::shared_ptr<Register> vr){
        if(phyRegMap.find(vr) != phyRegMap.end() && phyRegMap[vr] != NULL){
            for(int i = 1; i < 16; ++i) {
                if(i == 3 || i == 6 || i == 7)  continue;
                
                if(i == phyRegMap[vr] -> no){
                    LRURegister[i] = 1;
                    continue;
                }
                if(LRURegister[i] == 0){
                    continue;
                }
                LRURegister[i]++;
            }
            return phyRegMap[vr];
        }
        int max = 0;
        int maxNo = 0;
        for(int i = 1; i < 16; ++i) {
            if(i == 3 || i == 6 || i == 7)  continue;
            if(LRURegister[i] == 0){
                maxNo = i;
                max = -1;
                break;
            }
            if(LRURegister[i] > max){
                max = LRURegister[i];
                maxNo = i;
            }
        }
        if(max == -1){
//            std::cout<<maxNo<<std::endl;
            std::shared_ptr<PhysicalRegister> ptr(new PhysicalRegister(maxNo));
            return assignReg(vr, ptr);
        }
        else{
            return assignReg(vr, phyRegMap[phy2vir[maxNo]]);
        }
    }
    
    void clearReg(int iscall){
        if(iscall == 0){
            for(int i = 0; i < 16; ++i) {
                if(i == 3 || i == 6 || i == 7) continue;
                if(phy2vir[i] != NULL && slots.find(std::dynamic_pointer_cast<VirtualRegister>(phy2vir[i])) != slots.end()){
                    curInstruction -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, getSlot(std::dynamic_pointer_cast<VirtualRegister>(phy2vir[i])),  phyRegMap[phy2vir[i]])));
                    curInstruction -> prev -> visited(shared_from_this());
                }
                LRURegister[i] = 0;
                phy2vir[i] = NULL;
            }
        }
        else if(iscall == -1){
            for(int i = 1; i < 16; ++i) {
                LRURegister[i] = 0;
                phy2vir[i] = NULL;
            }
        }
        else{
            for(int i = 1; i < 16; ++i) {
                if(i == 3 || i == 6 || i == 7)  continue;
                LRURegister[i] = 0;
                phy2vir[i] = NULL;
            }
        }
        phyRegMap.clear();
    }
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
        
        curBlock = node;
        
        for(std::map<std::shared_ptr<Register>, std::shared_ptr<IRInstruction>>::iterator iter = node -> phi.begin(); iter != node -> phi.end(); ++iter){
            iter -> second -> visited(shared_from_this());
        }
        
        for(std::shared_ptr<IRInstruction> i = node-> head; i != NULL; i = i -> next){
            curInstruction = i;
            i -> visited(shared_from_this());
        }
        
    }
    
    void visit(std::shared_ptr<Function> node){
        regMap.clear();
        counterReg.clear();
        std::cout<<"func "<<node -> name<<" ";
        curFunction = node;
        
        slots.clear();
        for(int i = 0; i < 16; ++i) {
            LRURegister[i] = 0;
            phy2vir[i] = NULL;
        }

        std::shared_ptr<StackSlot> ptr;
        curBlock = curFunction -> getReversePostOrder()[0];
        switch(curFunction -> argVarRegList.size()){
            case 6:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[5]));
                phyRegMap[curFunction -> argVarRegList[5]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r9"));
//                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, ptr, phyRegMap[curFunction -> argVarRegList[5]])));
                LRURegister[9] = 1;
                phy2vir[9] = curFunction -> argVarRegList[5];
                curBlock -> head -> visited(shared_from_this());
                std::cout<< phyRegMap[curFunction -> argVarRegList[5]] -> getHintName()<<" ";
            case 5:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[4]));
                //                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Store (curBlock, func -> argVarRegList[4], 8, ptr, 0)));
                phyRegMap[curFunction -> argVarRegList[4]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r8"));
                LRURegister[8] = 1;
                phy2vir[8] = curFunction -> argVarRegList[4];
                std::cout<< phyRegMap[curFunction -> argVarRegList[4]] -> getHintName()<<" ";
            case 4:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[3]));
                //                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Store (curBlock, func -> argVarRegList[3], 8, ptr, 0)));
                phyRegMap[curFunction -> argVarRegList[3]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rcx"));
                LRURegister[2] = 1;
                phy2vir[2] = curFunction -> argVarRegList[3];
                std::cout<< phyRegMap[curFunction -> argVarRegList[3]] -> getHintName()<<" ";
            case 3:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[2]));
                phyRegMap[curFunction -> argVarRegList[2]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r15"));
                curBlock -> head -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, phyRegMap[curFunction -> argVarRegList[2]], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rdx")))));
                LRURegister[3] = 1;
                phy2vir[3] = curFunction -> argVarRegList[2];
                std::cout<< phyRegMap[curFunction -> argVarRegList[2]] -> getHintName()<<" ";
            case 2:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[1]));
                phyRegMap[curFunction -> argVarRegList[1]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsi"));
                LRURegister[4] = 1;
                phy2vir[4] = curFunction -> argVarRegList[1];
                std::cout<< phyRegMap[curFunction -> argVarRegList[1]] -> getHintName()<<" ";
            case 1:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[0]));
                phyRegMap[curFunction -> argVarRegList[0]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rdi"));
                LRURegister[5] = 1;
                phy2vir[5] = curFunction -> argVarRegList[0];
                std::cout<< phyRegMap[curFunction -> argVarRegList[0]] -> getHintName()<<" ";
            case 0:
                break;
        }
        
        std::cout<<"{"<<std::endl;
        std::vector<std::shared_ptr<BasicBlock>> reversePostOrder(node -> getReversePostOrder());
        for(int i = 0; i < reversePostOrder.size(); ++i) {
            reversePostOrder[i] -> visited(shared_from_this());
        }
        std::cout<<"}"<<std::endl;
        clearReg(-1);
    }
    
    void visit(std::shared_ptr<BinaryOperation> node){
        std::cout<<"    ";
        std::string op;
        std::shared_ptr<Register> ptr;
        switch (node -> op) {
            case BinaryOperation::ADD:
                op = "add";
//                if(node -> lhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> lhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> lhs = ptr;
//                }
                node -> lhs = getReg(node -> lhs);
                if(node -> rhs -> getType() != "IntImmediate"){
                    node -> rhs = getReg(node -> rhs);
                }
                node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> lhs));
                break;
            case BinaryOperation::SUB:
                op = "sub";
//                if(node -> lhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> lhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> lhs = ptr;
//                }
                node -> lhs = getReg(node -> lhs);
                if(node -> rhs -> getType() != "IntImmediate"){
                    node -> rhs = getReg(node -> rhs);
                }
                node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> lhs));
                break;
            case BinaryOperation::MUL:
                op = "mul";
//                if(node -> lhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> lhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> lhs = ptr;
//                }
                node -> lhs = getReg(node -> lhs);
                if(node -> rhs -> getType() != "IntImmediate"){
                    node -> rhs = getReg(node -> rhs);
                }
                node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> lhs));
                break;
            case BinaryOperation::DIV:
                op = "div";
//                if(node -> lhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> lhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> lhs = ptr;
//                }
                node -> lhs = getReg(node -> lhs);
                curInstruction -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(0)), node -> lhs)));
//                if(node -> rhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> rhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> rhs = ptr;
//                }
                node -> rhs = getReg(node -> rhs);
                node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> lhs));
                curInstruction -> next -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, node -> dest, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(0)))));
                break;
            case BinaryOperation::MOD:
                op = "rem";
//                if(node -> lhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> lhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> lhs = ptr;
//                }
                node -> lhs = getReg(node -> lhs);
                curInstruction -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(0)), node -> lhs)));
//                if(node -> rhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> rhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> rhs = ptr;
//                }
                node -> rhs = getReg(node -> rhs);
                node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> lhs));
                curInstruction -> next -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, node -> dest, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rdx")))));
                break;
            case BinaryOperation::SHL:
                op = "shl";
                break;
            case BinaryOperation::SHR:
                op = "shr";
                break;
            case BinaryOperation::AND:
                op = "and";
//                if(node -> lhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> lhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> lhs = ptr;
//                }
                node -> lhs = getReg(node -> lhs);
                if(node -> rhs -> getType() != "IntImmediate"){
                    node -> rhs = getReg(node -> rhs);
                }
                node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> lhs));
                break;
            case BinaryOperation::OR:
                op = "or";
//                if(node -> lhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> lhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> lhs = ptr;
//                }
                node -> lhs = getReg(node -> lhs);
                if(node -> rhs -> getType() != "IntImmediate"){
                    node -> rhs = getReg(node -> rhs);
                }
                node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> lhs));
                break;
            case BinaryOperation::XOR:
                op = "xor";
//                if(node -> lhs -> getType() == "IntImmediate"){
//                    ptr = std::shared_ptr<Register>(new VirtualRegister(""));
//                    node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getReg(ptr), node -> lhs)));
//                    node -> prev -> visited(shared_from_this());
//                    node -> lhs = ptr;
//                }
                node -> lhs = getReg(node -> lhs);
                if(node -> rhs -> getType() != "IntImmediate"){
                    node -> rhs = getReg(node -> rhs);
                }
                node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> lhs));
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
        
        std::string op = "neg";
        node -> operand = getReg(node -> operand);
        node -> dest = destReg(node -> dest, std::dynamic_pointer_cast<PhysicalRegister>(node -> operand));
        std::cout<<"    ";
        node -> dest -> visited(shared_from_this());
        std::cout<<" = "<<op<<" ";
        node -> operand -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<IntComparison> node){
        std::cout<<"    ";
        std::string op;
        node -> lhs = getReg(node -> lhs);
        if(node -> rhs -> getType() != "IntImmediate"){
            node -> rhs = getReg(node -> rhs);
        }
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
        if(node -> dest != NULL){
            node -> dest -> visited(shared_from_this());
        }
        std::cout<<" = "<<op<<" ";
        jump = op;
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
        if(jump == ""){
            std::shared_ptr<Register> reg(new VirtualRegister(""));
            node -> cond = reg;
            node -> prepend(std::shared_ptr<IRInstruction>(new IntComparison(curBlock, reg, IntComparison::GT, node -> cond, std::shared_ptr<Register>(new IntImmediate(0)))));
            node -> prev -> visited(shared_from_this());
        }
        clearReg(0);
        std::cout<<"    br ";
        node -> cond -> visited(shared_from_this());
        std::cout<<" %"<<labelId(node -> getThen()) << " %"<<labelId(node -> getElse());
        std::cout<<std::endl;
        jump = "";
    }
    void visit(std::shared_ptr<Return> node){
        if(node -> ret != NULL){
            node -> ret = getReg(node -> ret);
            curInstruction -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(0)), node -> ret)));
        }
        std::cout<<"    ret ";
        node -> ret -> visited(shared_from_this());
        std::cout<<std::endl<<std::endl;
        clearReg(-1);
    }
    void visit(std::shared_ptr<Jump> node){
        clearReg(0);
        std::cout<<"    jump %"<<labelId(node -> target)<<std::endl<<std::endl;
    }
    
    void visit(std::shared_ptr<VirtualRegister> node){
        std::cout<<"$"<<regId(node);
    }
    
    void visit(std::shared_ptr<HeapAllocate> node){
        node -> allocSize = assignReg(node -> allocSize, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rdi")));
        clearReg(0);
        
        node -> dest = getReg(node -> dest);
        node -> next -> prepend(std::shared_ptr<IRInstruction>(new Move (curBlock, node -> dest, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(0)))));
//        node -> dest = getReg(node -> dest);
//        node -> next -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, node -> dest, std::shared_ptr<Register>(new PhysicalRegister(0)))));
        std::cout<<"    ";
        node -> dest -> visited(shared_from_this());
        std::cout<<" = alloc ";
        node -> allocSize -> visited(shared_from_this());
        std::cout<<std::endl;
    }
    void visit(std::shared_ptr<Load> node){
        std::cout<<"    ";
        node -> address = getReg(node -> address);
        node -> dest = getReg(node -> dest);
        node -> dest -> visited(shared_from_this());
        std::cout<<" = load "<<node -> size<<" ";
        node -> address -> visited(shared_from_this());
        std::cout<<" "<<node -> offset << std::endl;
    }
    void visit(std::shared_ptr<Store> node){
        node -> address = getReg(node -> address);
        if(node ->  value -> getType() != "IntImmediate"){
            node -> value = getReg(node -> value);
        }
        std::cout<<"    store "<<node -> size<<" ";
        node -> address -> visited(shared_from_this());
        std::cout<<" ";
        node -> value -> visited(shared_from_this());
        std::cout<<" "<<node -> offset<< std::endl;
    }
    void visit(std::shared_ptr<Move> node){
        std::cout<<"    ";
        if(node -> dest -> getType() != "PhysicalRegister" && node -> dest -> getType() != "StackSlot"){
            node -> dest = getReg(node -> dest);
        }
        if(node -> source -> getType() == "VirtualRegister"){
            node -> source = getReg(node -> source);
        }
        
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
        switch (node -> args.size()) {
            case 6:
                node -> args[5] = assignReg(node -> args[5], std::shared_ptr<PhysicalRegister>(new PhysicalRegister(9)));
            case 5:
                node -> args[4] = assignReg(node -> args[4], std::shared_ptr<PhysicalRegister>(new PhysicalRegister(8)));
            case 4:
                node -> args[3] = assignReg(node -> args[3], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rcx")));
            case 3:
                node -> args[2] = getReg(node -> args[2]);
                node -> prepend(std::shared_ptr<IRInstruction>(new Move (curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(0)), node -> args[2])));
            case 2:
                node -> args[1] = assignReg(node -> args[1], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsi")));
            case 1:
                node -> args[0] = assignReg(node -> args[0], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rdi")));
            case 0:
            default:
                break;
        }
        if(node -> dest != NULL){
            node -> dest = destReg(node -> dest, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(0)));
        }
        clearReg(0);
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
    
    void visit(std::shared_ptr<PhysicalRegister>node){
        std::cout<<node -> name;
    }
    void visit(std::shared_ptr<StackSlot> node){
        std::cout<<"####"<<node -> offset;
    }
};


#endif /* IRAllocator_h */
