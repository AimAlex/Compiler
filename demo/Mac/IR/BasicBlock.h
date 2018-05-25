//
//  BasicBlock.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef BasicBlock_h
#define BasicBlock_h
#include <map>
#include "Register.h"
#include "IRVisitor.h"
class Function;
class IRInstruction;
class BasicBlock : public std::enable_shared_from_this<BasicBlock>{
public:
    std::shared_ptr<IRInstruction> head = NULL;
    std::shared_ptr<IRInstruction> last = NULL;
    bool ended = false;
    std::string hintName;
    std::shared_ptr<Function> parent;
    std::map<std::shared_ptr<Register>, std::shared_ptr<IRInstruction>> phi;
    std::vector<std::shared_ptr<BasicBlock>> successor;
    std::vector<std::shared_ptr<BasicBlock>> predecessor;
    
    std::vector<std::shared_ptr<BasicBlock>> DTChildren;
    
    BasicBlock(std::shared_ptr<Function> func, std::string str) {
        parent = func;
        if(str == ""){
            hintName = "block";
        }
        else{
            hintName = str;
        }
    }
    
    void addSuccessor(std::shared_ptr<BasicBlock> BB) {
        if (BB == NULL) return;
        successor.push_back(BB);
        BB -> predecessor.push_back(shared_from_this());
    }

    void delSuccessor(std::shared_ptr<BasicBlock> BB){
        if(BB == NULL)return;
        successor.erase(find(successor.begin(),successor.end(), BB));
        BB -> predecessor.erase(find(BB -> predecessor.begin(),BB -> predecessor.end(), shared_from_this()));
    }
    
    void visited(std::shared_ptr<IRVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* BasicBlock_h */
