#ifndef IfState_h
#define IfState_h

#include "ASTNode.h"
class IfState : public ASTNode, public std::enable_shared_from_this<IfState>{
public:
    size_t position;
    std::shared_ptr <ASTNode> cond;
    std::shared_ptr <ASTNode> then;
    std::shared_ptr<ASTNode> otherwise;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr){
        cond = ptr[0];
        then = ptr[1];
        otherwise = ptr[2];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif
