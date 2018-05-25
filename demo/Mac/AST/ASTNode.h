#ifndef ASTNode_h
#define ASTNode_h
#include <vector>
#include "ASTVisitor.h"
#include "SymbolTable.h"
#include "VariableType.h"
#include "BasicBlock.h"
#include "Register.h"
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
    std::shared_ptr<SymbolType> exprType;
    bool isLvalue;
    virtual bool isLogicalExpression(){return false;}
    virtual bool needMemoryAccess(){return false;}
    
    std::shared_ptr<BasicBlock> ifTrue = NULL;
    std::shared_ptr<BasicBlock> ifFalse = NULL;
    
    std::shared_ptr<Register> intValue;
    std::shared_ptr<Register> addressValue;
    int addressOffset;
};

#endif
