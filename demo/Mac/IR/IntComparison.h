//
//  IntComparison.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IntComparison_h
#define IntComparison_h
class IntComparison : public IRInstruction {
public:
    enum Comparison{
        EQ, NE, GT, GE, LT, LE
    }
    std::shared_ptr<IntValue> dest;
    Comparison cond;
    std::shared_ptr<IntValue> lhs;
    std::shared_ptr<IntValue> rhs;
};

#endif /* IntComparison_h */
