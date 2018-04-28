#ifndef WhileLoop_h
#define WhileLoop_h
#include "ASTNode.h"

class WhileLoop : public ASTNode, public std::enable_shared_from_this<WhileLoop> {
public:
    size_t Position;
    std::shared_ptr<ASTNode> cond;
    std::shared_ptr<ASTNode> body;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr) {
        cond = ptr[0];
        body = ptr[1];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(shared_from_this());
    }
};

#endif
