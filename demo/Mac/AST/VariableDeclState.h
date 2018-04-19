#ifndef VariableDeclState_h
#define VariableDeclState_h

#include "State.h"
#include "VariableDecl.h"
class VariableDeclState : public State {
public:
    std::shared_ptr<VariableDecl> decl;
};

#endif
