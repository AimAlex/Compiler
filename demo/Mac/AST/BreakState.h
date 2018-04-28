#ifndef BreakState_h
#define BreakState_h
#include "ASTNode.h"

class BreakState : public ASTNode, public std::enable_shared_from_this<BreakState>{
public:
    size_t position;
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif
