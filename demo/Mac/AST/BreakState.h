#ifndef BreakState_h
#define BreakState_h
#include "ASTNode.h"

class BreakState : public ASTNode{
public:
    size_t position;
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(this);
    }
};

#endif
