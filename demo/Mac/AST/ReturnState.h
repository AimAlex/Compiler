#ifndef ReturnState_h
#define ReturnState_h
#include "ASTNode.h"

class ReturnState : public ASTNode, public std::enable_shared_from_this<ReturnState>{
public:
    std::shared_ptr<ASTNode> value;
    size_t position;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr){
        value = ptr[0];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};


#endif
