#ifndef ReturnState_h
#define ReturnState_h
#include "ASTNode.h"

class ReturnState : public ASTNode {
public:
    std::shared_ptr<ASTNode> value;
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr){
        value = ptr[0];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(this);
    }
};


#endif
