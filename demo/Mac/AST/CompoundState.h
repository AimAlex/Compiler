#ifndef CompoundState_h
#define CompoundState_h
#include <vector>
#include "State.h"
class CompoundState : public State {
public:
    std::vector<std::shared_ptr<State>> stmts;
};

#endif
