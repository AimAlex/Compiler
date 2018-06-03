//
//  Function.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Function_h
#define Function_h
#include <vector>
#include "SymbolType.h"
#include <map>
#include "FunctionType.h"
#include "BasicBlock.h"
#include "IRVisitor.h"
class Return;
class Function : public std::enable_shared_from_this<Function>{
public:
    std::vector<std::shared_ptr<Register>> argVarRegList;
    std::string name;
    std::shared_ptr<BasicBlock> startBlock;
    std::shared_ptr<BasicBlock> exitBlock;
    std::shared_ptr<FunctionType> type;
    int retsize;
    int stackSize;
    std::vector<std::shared_ptr<BasicBlock>> reversePostOrder;
    std::vector<std::shared_ptr<BasicBlock>> reversePreOrder;
    std::vector<std::shared_ptr<BasicBlock>> DTPreOrder;
    std::vector<std::shared_ptr<BasicBlock>> Visited;
    std::vector<std::shared_ptr<Return>> retInstruction;
    std::vector<std::shared_ptr<Function>> calleeSet;
    std::vector<std::shared_ptr<Function>> recursiveCalleeSet;
    
    std::map<std::shared_ptr<Register>, std::shared_ptr<Register>> argStackSlotMap;
    std::vector<std::shared_ptr<Register>> stackSlots;
    std::vector<std::shared_ptr<Register>> usedPhysicalGeneralRegister;
    
    std::string builtinFunctionHackName;
    
    Function(std::shared_ptr<FunctionType> function){
        if(function -> returnType == NULL){
            retsize = 0;
        }
        else{
            retsize = function -> returnType -> getsize();
        }
        name = function -> name;
        type = function;
        stackSize = 0;
//        startBlock = std::shared_ptr<BasicBlock> (new BasicBlock(shared_from_this(), name + "_entry"))
    }
    
    void dfsPreOrder(std::shared_ptr<BasicBlock> node) {
        if (std::find(Visited.begin(), Visited.end(), node) != Visited.end()) return;
        Visited.push_back(node);
        reversePreOrder.push_back(node);
        for(int i = 0; i < node -> successor.size(); ++i){
            dfsPreOrder(node -> successor[i]);
        }
    }
    
    void calcReversePreOrder() {
        reversePreOrder.clear();
        Visited.clear();
        dfsPreOrder(startBlock);
        std::reverse(reversePreOrder.begin(), reversePreOrder.end());
        Visited.clear();
    }
    
    void calcReversePostOrder() {
        reversePostOrder.clear();
        Visited.clear();
        dfsPostOrder(startBlock);
        std::reverse(reversePostOrder.begin(), reversePostOrder.end());
        Visited.clear();
    }
    
    void dfsPostOrder(std::shared_ptr<BasicBlock> node) {
        if (std::find(Visited.begin(), Visited.end(), node) != Visited.end()) return;
        Visited.push_back(node);
        for(int i = 0; i < node -> successor.size(); ++i){
            dfsPostOrder(node -> successor[i]);
        }
        reversePostOrder.push_back(node);
    }
    
    std::vector<std::shared_ptr<BasicBlock>> getReversePreOrder() {
        if (reversePreOrder.size() == 0) calcReversePreOrder();
        return reversePreOrder;
    }
    
    std::vector<std::shared_ptr<BasicBlock>> getReversePostOrder() {
        if (reversePostOrder.size() == 0) calcReversePostOrder();
        return reversePostOrder;
    }
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* Function_h */
