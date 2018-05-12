//
//  Store.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Store_h
#define Store_h
class Store : public IRInstruction {
public:
    int size;
    std::shared_ptr<IntValue> address;
    int offset;
    std::shared_ptr<IntValue> value;
    bool isStaticData;
};

#endif /* Store_h */
