#ifndef ASTNode_h
#define ASTNode_h
#include <vector>
class ASTNode {
public:
    virtual void accept(std::vector<std::shared_ptr<ASTNode>>) = 0;
    virtual void acceptStr(std::string);
};

#endif
