//
//  MemberAccess.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef MemberAccess_h
#define MemberAccess_h
#include "ASTNode.h"
class MemberAccess : public ASTNode, public std::enable_shared_from_this<MemberAccess>{
public:
    std::shared_ptr <ASTNode> record;
    std::string member;
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> vec){
        record = vec[0];
    }
    void acceptStr(std::string str){
        member = str;
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
    bool needMemoryAccess(){
        return true;
    }
};

#endif /* MemberAccess_h */
