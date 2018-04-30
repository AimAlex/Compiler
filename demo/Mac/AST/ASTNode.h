#ifndef ASTNode_h
#define ASTNode_h
#include <vector>
#include "ASTVisitor.h"
#include "SymbolTable.h"
#include "VariableType.h"
class ASTNode {
public:
    virtual void accept(std::vector<std::shared_ptr<ASTNode>>){}
    virtual void acceptStr(std::string){}
    virtual void acceptFunction(std::vector<std::shared_ptr<ASTNode>>){}
    virtual void acceptConstructor(std::shared_ptr<ASTNode>){}
    virtual void acceptNum(int){}
    virtual void visited(std::shared_ptr<ASTVisitor>){}
    virtual std::shared_ptr<SymbolType> getType(){return NULL;}
    virtual std::string gettype(){return "";}
};

#endif
