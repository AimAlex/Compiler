//
//  NullLiteral.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/4/20.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef NullLiteral_h
#define NullLiteral_h
#include "ASTNode.h"

class NullLiteral : public ASTNode, public std::enable_shared_from_this<NullLiteral>{
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif /* NullLiteral_h */
