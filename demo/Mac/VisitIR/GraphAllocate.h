
//
//  GraphAllocate.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/6.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef GraphAllocate_h
#define GraphAllocate_h
#include "IRVisitor.h"
class GraphAllocate : public IRVisitor, public std::enable_shared_from_this<GraphAllocate>{
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
    
    std::string jump = "";
    int stringnum = 0;
    
    
    std::shared_ptr<StackSlot> getSlot(std::shared_ptr<VirtualRegister> vr){
        if(slots.find(vr) == slots.end()) {
            slots[vr] = std::shared_ptr<StackSlot> (new StackSlot(curFunction, vr -> hintName, curFunction -> stackSize));
            
            curFunction -> stackSize += 8;
            //            //std::cout<<"hhh"<<std::endl;
        }
        return slots.find(vr) -> second;
    }
    
    std::shared_ptr<PhysicalRegister> moveInReg(std::shared_ptr<Register> reg, int dest, std::shared_ptr<IRInstruction> node){
        std::shared_ptr<PhysicalRegister> ptr(new PhysicalRegister(dest));
        if(reg -> getType() == "IntImmediate"){
            node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, ptr, reg)));
        }
        else if(reg -> getType() == "VirtualRegister"){
            node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, ptr, getSlot(std::dynamic_pointer_cast<VirtualRegister>(reg)))));
        }
        else if(reg -> getType() == "StaticSpace"){
            node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, ptr, reg)));
        }
        else if(reg -> getType() == "StaticString"){
            node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, ptr, reg)));
        }
        else if(reg -> getType() == "PhysicalRegister"){
            node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, ptr, reg)));
        }
        else if(reg -> getType() == "StackSlot"){
            node -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, ptr, reg)));
        }
//        node -> prev -> visited(shared_from_this());
        return ptr;
    }
    
    void moveOutReg(std::shared_ptr<Register> reg, int dest, std::shared_ptr<IRInstruction> node){
        std::shared_ptr<PhysicalRegister> ptr(new PhysicalRegister(dest));
        if(reg -> getType() == "VirtualRegister"){
            node -> next -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, getSlot(std::dynamic_pointer_cast<VirtualRegister>(reg)), ptr)));
        }
        else if(reg -> getType() == "StaticSpace"){
            node -> next -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, reg, ptr)));
        }
        else if(reg -> getType() == "PhysicalRegister"){
            node -> next -> prepend(std::shared_ptr<IRInstruction>(new Move(curBlock, reg, ptr)));
        }
//        node -> next -> visited(shared_from_this());
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
        //std::cout<<"%"<<labelId(node)<<":"<<std::endl;
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
        //std::cout<<"func "<<node -> name<<" ";
        curFunction = node;
        
        slots.clear();
        
        std::shared_ptr<StackSlot> ptr;
        curBlock = curFunction -> getReversePostOrder()[0];
        int argSize = curFunction -> argVarRegList.size();
        if(argSize > 6){
            for(int i = 6; i < argSize; ++i) {
//                slots[std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[i])] = std::shared_ptr<StackSlot>(new StackSlot(curFunction, "", -(argSize - 1 - i) * 8 - 8));
                if(curFunction -> argVarRegList[i] -> getType() == "PhysicalRegister"){
                    curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, curFunction -> argVarRegList[i], std::shared_ptr<StackSlot>(new StackSlot(curFunction, "", -(argSize - 1 - i) * 8 - 8)))));
                }
            }
            argSize = 6;
        }
        switch(argSize){
            case 6:
                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, curFunction -> argVarRegList[5], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r9")))));
                //std::cout<< curFunction -> argVarRegList[5] -> getHintName()<<" ";
            case 5:
                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, curFunction -> argVarRegList[4], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r8")))));
                //std::cout<< curFunction -> argVarRegList[4] -> getHintName()<<" ";
            case 4:
                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, curFunction -> argVarRegList[3], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rcx")))));
                //std::cout<< curFunction -> argVarRegList[3] -> getHintName()<<" ";
            case 3:
                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, curFunction -> argVarRegList[2], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rdx")))));
                //std::cout<< curFunction -> argVarRegList[2] -> getHintName()<<" ";
            case 2:
                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, curFunction -> argVarRegList[1], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsi")))));
                //std::cout<< curFunction -> argVarRegList[1] -> getHintName()<<" ";
            case 1:
                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, curFunction -> argVarRegList[0], std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rdi")))));
                //std::cout<< curFunction -> argVarRegList[0] -> getHintName()<<" ";
            case 0:
                break;
        }
        
        //std::cout<<"{"<<std::endl;
        std::vector<std::shared_ptr<BasicBlock>> reversePostOrder(node -> getReversePostOrder());
        for(int i = 0; i < reversePostOrder.size(); ++i) {
            reversePostOrder[i] -> visited(shared_from_this());
        }
        //std::cout<<"}"<<std::endl;
    }
    
    void visit(std::shared_ptr<BinaryOperation> node){
        
        //std::cout<<"    ";
        std::string op;
        std::shared_ptr<Register> ptr;
        switch (node -> op) {
            case BinaryOperation::ADD:
                op = "add";
                node -> lhs = moveInReg(node -> lhs, 10, node);
                moveOutReg(node -> dest, 10, node);
                break;
            case BinaryOperation::SUB:
                op = "sub";
                node -> lhs = moveInReg(node -> lhs, 10, node);
                moveOutReg(node -> dest, 10, node);
                break;
            case BinaryOperation::MUL:
                op = "mul";
                node -> lhs = moveInReg(node -> lhs, 10, node);
                moveOutReg(node -> dest, 10, node);
                break;
            case BinaryOperation::DIV:
                op = "div";
                node -> lhs = moveInReg(node -> lhs, 0, node);
                node -> rhs = moveInReg(node -> rhs, 11, node);
                moveOutReg(node -> dest, 0, node);
                break;
            case BinaryOperation::MOD:
                op = "rem";
                node -> lhs = moveInReg(node -> lhs, 0, node);
                node -> rhs = moveInReg(node -> rhs, 11, node);
                moveOutReg(node -> dest, 3, node);
                break;
            case BinaryOperation::SHL:
                op = "shl";
                node -> lhs = moveInReg(node -> lhs, 10, node);
                if(node -> rhs -> getType() != "IntImmediate"){
                    node -> rhs = moveInReg(node -> rhs, 2, node);
                }
                moveOutReg(node -> dest, 10, node);
                break;
            case BinaryOperation::SHR:
                op = "shr";
                node -> lhs = moveInReg(node -> lhs, 10, node);
                if(node -> rhs -> getType() != "IntImmediate"){
                    node -> rhs = moveInReg(node -> rhs, 2, node);
                }
                moveOutReg(node -> dest, 10, node);
                break;
            case BinaryOperation::AND:
                op = "and";
                node -> lhs = moveInReg(node -> lhs, 10, node);
                moveOutReg(node -> dest, 10, node);
                break;
            case BinaryOperation::OR:
                op = "or";
                node -> lhs = moveInReg(node -> lhs, 10, node);
                moveOutReg(node -> dest, 10, node);
                break;
            case BinaryOperation::XOR:
                op = "xor";
                node -> lhs = moveInReg(node -> lhs, 10, node);
                moveOutReg(node -> dest, 10, node);
                break;
            default:
                break;
        }
        node -> dest -> visited(shared_from_this());
        //std::cout<<" = "<<op<<" ";
        node -> lhs -> visited(shared_from_this());
        //std::cout<<" ";
        node -> rhs -> visited(shared_from_this());
        //std::cout<<std::endl;
    }
    void visit(std::shared_ptr<UnaryOperation> node){
        std::string op;
        std::shared_ptr<Register> ptr;
        switch (node -> op) {
            case UnaryOperation::NEG:
                op = "neg";
                node -> operand = moveInReg(node -> operand, 10, node);
                moveOutReg(node -> dest, 10, node);
                break;
            case UnaryOperation::NOT:
                op = "not";
                node -> operand = moveInReg(node -> operand, 10, node);
                moveOutReg(node -> dest, 10, node);
                break;
            default:
                break;
        }
        
        //std::cout<<"    ";
        node -> dest -> visited(shared_from_this());
        //std::cout<<" = "<<op<<" ";
        node -> operand -> visited(shared_from_this());
        //std::cout<<std::endl;
    }
    void visit(std::shared_ptr<IntComparison> node){
        
        //std::cout<<"    ";
        std::string op;
        if(node -> lhs -> getType() == "IntImmediate" || node -> lhs -> getType() == "StaticSpace"){
            node -> lhs = moveInReg(node -> lhs, 10, node);
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
        //std::cout<<" = "<<op<<" ";
        jump = op;
        node -> lhs -> visited(shared_from_this());
        //std::cout<<" ";
        node -> rhs -> visited(shared_from_this());
        //std::cout<<std::endl;
    }
    void visit(std::shared_ptr<IntImmediate> node){
        //std::cout<<node -> value;
    }
    //    void visit(Call node);
    //    void visit(SystemCall node);
    //    void visit(PhiInstruction node);
    //
    void visit(std::shared_ptr<Branch> node){
        
        if(jump == ""){
            std::shared_ptr<Register> reg(new VirtualRegister(""));
            node -> prepend(std::shared_ptr<IRInstruction>(new IntComparison(curBlock, reg, IntComparison::GT, node -> cond, std::shared_ptr<Register>(new IntImmediate(0)))));
            node -> prev -> visited(shared_from_this());
//            node -> cond = reg;
        }
        //            //std::cout<<node -> cond -> getType()<<regId(std::dynamic_pointer_cast<VirtualRegister>(node -> cond))<<std::endl;
        //std::cout<<"    br ";
//        node -> cond -> visited(shared_from_this());
        //std::cout<<" %"<<labelId(node -> getThen()) << " %"<<labelId(node -> getElse());
        //std::cout<<std::endl;
        jump = "";
    }
    void visit(std::shared_ptr<Return> node){
        
        if(node -> ret != NULL){
            node -> ret = moveInReg(node -> ret, 0, node);
        }
        //std::cout<<"    ret ";
        if(node -> ret != NULL){
            node -> ret -> visited(shared_from_this());
        }
        //std::cout<<std::endl<<std::endl;
    }
    void visit(std::shared_ptr<Jump> node){
        
        //std::cout<<"    jump %"<<labelId(node -> target)<<std::endl<<std::endl;
    }
    
    void visit(std::shared_ptr<VirtualRegister> node){
        //std::cout<<"$"<<regId(node);
    }
    
    void visit(std::shared_ptr<HeapAllocate> node){
        
        node -> allocSize = moveInReg(node -> allocSize, 5, node);
        if(node -> dest != NULL){
            moveOutReg(node -> dest, 0, node);
        }
        //std::cout<<"    ";
        node -> dest -> visited(shared_from_this());
        //std::cout<<" = alloc ";
        node -> allocSize -> visited(shared_from_this());
        //std::cout<<std::endl;
    }
    void visit(std::shared_ptr<Load> node){
        
        //std::cout<<"    ";
        if(node -> address -> getType() == "StackSlot"){

            moveOutReg(node -> dest, 10, node);
            node -> dest = std::shared_ptr<PhysicalRegister>(new PhysicalRegister(10));
            return;
        }else{
            node -> address = moveInReg(node -> address, 10, node);
            moveOutReg(node -> dest, 10, node);
            node -> dest = std::shared_ptr<PhysicalRegister>(new PhysicalRegister(10));
            node -> dest -> visited(shared_from_this());
        //std::cout<<" = load "<<node -> size<<" ";
            node -> address -> visited(shared_from_this());
        //std::cout<<" "<<node -> offset << std::endl;
        }
    }
    void visit(std::shared_ptr<Store> node){
        if(node -> address -> getType() != "StackSlot"){
            node -> address = moveInReg(node -> address, 11, node);
        }
        if(node ->  value -> getType() != "IntImmediate"){
            node -> value = moveInReg(node -> value, 10, node);
        }
        //std::cout<<"    store "<<node -> size<<" ";
        node -> address -> visited(shared_from_this());
        //std::cout<<" ";
        node -> value -> visited(shared_from_this());
        //std::cout<<" "<<node -> offset<< std::endl;
    }
    void visit(std::shared_ptr<Move> node){
        
        //std::cout<<"    ";
        if(node -> source -> getType() == "VirtualRegister" || ((node -> source -> getType() == "StaticString"|| node -> source -> getType() == "StaticSpace") && node -> dest -> getType() != "PhysicalRegister")){
            node -> source = moveInReg(node -> source, 10, node);
        }
        
        if(node -> dest -> getType() != "PhysicalRegister" && node -> dest -> getType() != "StackSlot" && node -> dest -> getType() != "StaticSpace"){
            moveOutReg(node -> dest, 10, node);
            node -> dest = std::shared_ptr<Register>(new PhysicalRegister(14));
        }
        
        node -> dest -> visited(shared_from_this());
        
        //std::cout<<" = move ";
        node -> source -> visited(shared_from_this());
        //std::cout<<std::endl;
    }
    
    void visit(std::shared_ptr<StaticSpace> node){
        if(definingStatic) {
            //std::cout<<"space @"<<dataId(node)<<" "<<node -> length<<std::endl;
        }
        else{
            //std::cout<<"@"<<dataId(node);
        }
    }
    void visit(std::shared_ptr<StaticString> node){
        if(definingStatic) {
            ++stringnum;
            node -> no = stringnum;
            //std::cout<<"asciiz @"<<dataId(node)<<" "<<node -> value<<std::endl;
        }
        else{
            //std::cout<<"@"<<dataId(node);
        }
    }
    void visit(std::shared_ptr<Call> node){
        int argSize = node -> args.size();
        for(std::set<std::shared_ptr<Register>>::iterator iter = node -> liveOut.begin(); iter != node -> liveOut.end(); ++iter){
            if(node -> getDefRegister() == curFunction -> graphMap[std::dynamic_pointer_cast<VirtualRegister>(*iter)] -> color) continue;
            if(curFunction -> graphMap.find(std::dynamic_pointer_cast<VirtualRegister>(*iter)) != curFunction -> graphMap.end()){
                if(curFunction -> graphMap[std::dynamic_pointer_cast<VirtualRegister>(*iter)] -> color -> getType() != "PhysicalRegister") continue;
                node -> prepend(std::shared_ptr<Move>(new Move(curBlock, std::shared_ptr<StackSlot>(new StackSlot(curFunction, "", 0, false)), curFunction -> graphMap[std::dynamic_pointer_cast<VirtualRegister>(*iter)] -> color)));
                node -> prepend(std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsp")), BinaryOperation::SUB, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsp")), std::shared_ptr<IntImmediate>(new IntImmediate(8)))));
                node -> next -> prepend(std::shared_ptr<Move>(new Move(curBlock, curFunction -> graphMap[std::dynamic_pointer_cast<VirtualRegister>(*iter)] -> color, std::shared_ptr<StackSlot>(new StackSlot(curFunction, "", 0, false)))));
                node -> next -> prepend(std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsp")), BinaryOperation::ADD, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsp")), std::shared_ptr<IntImmediate>(new IntImmediate(8)))));
            }
        }
        if(argSize > 6){
            for(int i = 6; i < argSize; ++i){
                node -> args[i] = moveInReg(node -> args[i], 10, node);
                node -> prepend(std::shared_ptr<Move>(new Move(curBlock, std::shared_ptr<StackSlot>(new StackSlot(curFunction, "", (i - 6) * 8, false)), node -> args[i])));
            }
            node -> prepend(std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsp")), BinaryOperation::SUB, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsp")), std::shared_ptr<IntImmediate>(new IntImmediate(8 * (argSize - 6))))));
            node -> next -> prepend(std::shared_ptr<IRInstruction> (new BinaryOperation(curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsp")), BinaryOperation::ADD, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rsp")), std::shared_ptr<IntImmediate>(new IntImmediate(8 * (argSize - 6))))));
            argSize = 6;
        }
        std::shared_ptr<Register> hhhh;
        switch (argSize) {
            case 6:
                node -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r9")), node -> args[5])));
            case 5:
                node -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r8")), node -> args[4])));
            case 4:
                node -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(2)), node -> args[3])));
            case 3:
                node -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(3)), node -> args[2])));
            case 2:
                node -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(4)), node -> args[1])));
            case 1:
                if(node -> args[0] -> getType() == "VirtualRegister"){
                    
                }
                node -> prepend(std::shared_ptr<IRInstruction> (new Move (curBlock, std::shared_ptr<PhysicalRegister>(new PhysicalRegister(5)), node -> args[0])));
            case 0:
            default:
                break;
        }
        if(node -> dest != NULL){
            moveOutReg(node -> dest, 0, node);
        }
        //std::cout<<"    ";
        if(node -> dest != NULL){
            node -> dest -> visited(shared_from_this());
            //std::cout<<" = ";
        }
        //std::cout<<"call "<<node -> func -> name<<" ";
        //std::cout<<std::endl;
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
        //std::cout<<node -> name;
    }
    void visit(std::shared_ptr<StackSlot> node){
//        std::cout<<"####"<<node -> offset;
    }
};

#endif /* GraphAllocate_h */
