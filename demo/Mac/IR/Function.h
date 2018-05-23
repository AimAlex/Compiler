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
class Return;
class Function : public std::enable_shared_from_this<Function>{
public:
    std::vector<std::shared_ptr<Register>> argVarRegList;
    std::string name;
    std::shared_ptr<BasicBlock> startBlock;
    std::shared_ptr<BasicBlock> exitBlock;
    std::shared_ptr<FunctionType> type;
    int retsize;
    
    std::vector<std::shared_ptr<BasicBlock>> reversePostOrder;
    std::vector<std::shared_ptr<BasicBlock>> reversePreOrder;
    std::vector<std::shared_ptr<BasicBlock>> DTPreOrder;
    std::vector<std::shared_ptr<BasicBlock>> visited;
    std::vector<std::shared_ptr<Return>> retInstruction;
    std::vector<std::shared_ptr<Function>> calleeSet;
    std::vector<std::shared_ptr<Function>> recursiveCalleeSet;
    
    std::map<std::shared_ptr<Register>, std::shared_ptr<Register>> argStackSlotMap;
    std::vector<std::shared_ptr<Register>> stackSlots;
    std::vector<std::shared_ptr<Register>> usedPhysicalGeneralRegister;
    
    std::string builtinFunctionHackName;
    
    Function(std::shared_ptr<FunctionType> function){
        retsize = function -> returnType -> getsize();
        name = function -> name;
        type = function;
//        startBlock = std::shared_ptr<BasicBlock> (new BasicBlock(shared_from_this(), name + "_entry"))
    }
    
    void dfsPreOrder(std::shared_ptr<BasicBlock> node) {
        if (std::find(visited.begin(), visited.end(), node) != visited.end()) return;
        visited.push_back(node);
        reversePreOrder.push_back(node);
        for(int i = 0; i < node -> successor.size(); ++i){
            dfsPreOrder(node -> successor[i]);
        }
    }
    
    void calcReversePreOrder() {
        reversePreOrder.clear();
        visited.clear();
        dfsPreOrder(startBlock);
        std::reverse(reversePreOrder.begin(), reversePreOrder.end());
        visited.clear();
    }
    
    std::vector<std::shared_ptr<BasicBlock>> getReversePreOrder() {
        if (reversePreOrder.size() == 0) calcReversePreOrder();
        return reversePreOrder;
    }
};

#endif /* Function_h */
