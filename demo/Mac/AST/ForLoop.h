#ifndef ForLoop_h
#define ForLoop_h
#include "ASTNode.h"
#include "VariableDecl.h"
#include <vector>
class ForLoop : public ASTNode{
public:
    size_t position;
    std::shared_ptr<ASTNode> initWithDecl;
    std::shared_ptr<ASTNode> init;
    std::shared_ptr<ASTNode> cond;
    std::shared_ptr<ASTNode> step;
    std::shared_ptr<ASTNode> body;
    void accept(std::vector<std::shared_ptr<ASTNode>> ptr) {
        init = ptr[0];
        cond = ptr[1];
        step = ptr[2];
        body = ptr[3];
        initWithDecl = ptr[4];
    }
    void visited(std::shared_ptr<ASTVisitor> visitor){
        visitor -> visit(std::shared_ptr<ForLoop>(this));
    }
};
#endif
