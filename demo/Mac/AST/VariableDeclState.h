#ifndef VariableDeclState_h
#define VariableDeclState_h

#include "ASTNode.h"
#include "VariableDecl.h"
class VariableDeclState : public ASTNode {
public:
    std::shared_ptr<VariableDecl> decl;
};

#endif
