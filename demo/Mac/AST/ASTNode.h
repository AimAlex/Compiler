#ifndef ASTNode_h
#define ASTNode_h
#include <vector>

class ASTNode {
public:
    virtual void accept(std::vector<std::shared_ptr<ASTNode>>){}
    virtual void acceptStr(std::string){}
    virtual void acceptFunction(std::vector<std::shared_ptr<ASTNode>>){}
    virtual void acceptConstructor(std::shared_ptr<ASTNode>){}
    virtual void acceptNum(int){};
};

#endif
