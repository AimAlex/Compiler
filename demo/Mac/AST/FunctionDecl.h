#ifndef FunctionDecl_h
#define FunctionDecl_h
#include "Decl.h"
#include <vector>
#include "VariableDecl.h"
#include "CompoundState.h"
class FunctionDecl : public Decl{
public:
    size_t position;
    std::string name;
    std::vector<std::shared_ptr<VariableDecl>> parameterList;
    std::shared_ptr<CompoundState> body;
//    FunctionType functiontype;
    FunctionDecl(){}
};

#endif
