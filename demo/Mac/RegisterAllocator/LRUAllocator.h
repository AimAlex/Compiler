//
//  LRUAllocator.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/1.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef LRUAllocator_h
#define LRUAllocator_h
#include "RegisterAllocator.h"
#include "IRRoot.h"
#include "Function.h"
#include "PhysicalRegister.h"
#include "StackSlot.h"
#include "BasicBlock.h"
class LRUAllocator : public RegisterAllocator{
public:
    std::shared_ptr<IRRoot> irRoot;
    std::shared_ptr<Function> func;
    std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<StackSlot>> slots;
    long long LRURegister[16];
    std::shared_ptr<Register> phy2vir[16];
    LRUAllocator(std::shared_ptr<IRRoot> ir) : RegisterAllocator(){
        irRoot = ir;
    }
    std::shared_ptr<StackSlot> getSlot(std::shared_ptr<VirtualRegister> vr){
        std::shared_ptr<StackSlot> slot = slots[vr];
        if(slot == NULL) {
            slot = std::shared_ptr<StackSlot> (new StackSlot(func, vr -> hintName, func -> stackSize));
            func -> stackSize += 8;
            slots[vr] = slot;
        }
        return slot;
    }
    
    void LRUFunction(){
        slots.clear();
        for(int i = 0; i < 16; ++i) {
            LRURegister[i] = 0;
            phy2vir[i] = NULL;
        }
        
        std::map<std::shared_ptr<Register>, std::shared_ptr<Register>> regMap;
        std::vector<std::shared_ptr<BasicBlock>> BlockList(func -> reversePostOrder);
        std::shared_ptr<BasicBlock> curBlock = BlockList[0];
        std::shared_ptr<StackSlot> ptr;
        switch(func -> argVarRegList.size()){
            case 6:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(func -> argVarRegList[5]));
                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Store (curBlock, func -> argVarRegList[5], 8, ptr, 0)));
                regMap[func -> argVarRegList[5]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("%r9"));
                LRURegister[9] = 1;
                phy2vir[9] = func -> argVarRegList[5];
            case 5:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(func -> argVarRegList[4]));
//                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Store (curBlock, func -> argVarRegList[4], 8, ptr, 0)));
                regMap[func -> argVarRegList[4]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("%r8"));
                LRURegister[8] = 1;
                phy2vir[8] = func -> argVarRegList[4];
            case 4:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(func -> argVarRegList[3]));
//                curBlock -> head -> prepend(std::shared_ptr<IRInstruction> (new Store (curBlock, func -> argVarRegList[3], 8, ptr, 0)));
                regMap[func -> argVarRegList[3]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("%rcx"));
                LRURegister[2] = 1;
                phy2vir[2] = func -> argVarRegList[3];
            case 3:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(func -> argVarRegList[2]));
                regMap[func -> argVarRegList[2]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("%rdx"));
                LRURegister[3] = 1;
                phy2vir[3] = func -> argVarRegList[2];
            case 2:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(func -> argVarRegList[1]));
                regMap[func -> argVarRegList[1]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("%rsi"));
                LRURegister[4] = 1;
                phy2vir[4] = func -> argVarRegList[1];
            case 1:
                ptr = getSlot(std::dynamic_pointer_cast<VirtualRegister>(func -> argVarRegList[0]));
                regMap[func -> argVarRegList[0]] = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("%rdi"));
                LRURegister[5] = 1;
                phy2vir[5] = func -> argVarRegList[0];
            case 0:
                break;
        }
        for(int i = 0; i < BlockList.size(); ++i) {
            curBlock = BlockList[i];
            for(std::shared_ptr<IRInstruction> inst = curBlock -> head; inst != NULL; inst = inst -> next){
                if(inst -> getType() != "Call"){
                    
                }
            }
            regMap.clear();
            for(int i = 0; i < 16; ++i) {
                if(phy2vir[i] != NULL){
                    getSlot(std::dynamic_pointer_cast<VirtualRegister>(phy2vir[i]));
                }
                LRURegister[i] = 0;
                phy2vir[i] = NULL;
            }
        }
    }
};

#endif /* LRUAllocator_h */
