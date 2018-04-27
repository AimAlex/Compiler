#ifndef ContinueState_h
#define ContinueState_h
#include "ASTNode.h"

class ContinueState : public ASTNode {
public:
    size_t position;
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(this);
    }
};

#endif
