#ifndef ContinueState_h
#define ContinueState_h
#include "ASTNode.h"

class ContinueState : public ASTNode, public std::enable_shared_from_this<ContinueState> {
public:
    size_t position;
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif
