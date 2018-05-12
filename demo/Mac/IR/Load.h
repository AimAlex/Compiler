//
//  Load.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef Load_h
#define Load_h
class Load : public IRInstruction {
public:
    std::shared_ptr <IntValue> dest;
    int size;
    std::shared_ptr <IntValue> address;
    int offset;
    bool isStaticData;
    bool isLoadAddress;
};

#endif /* Load_h */
