#ifndef ClassDecl_h
#define ClassDecl_h
#include "Decl.h"
#include <vector>
#include "VariableDecl.h"
#include "FunctionDecl.h"
#include "ClassConstructor"
class ClassDecl : public Decl{
public:
    size_t position;
    vector<std::shared_ptr<VariableDecl>> variableMembers;
    vector<std::shared_ptr<FunctionDecl>> functionMembers;
    shared_ptr<ClassConstructor> classconstructor;
    std::string name;
};

#endif
