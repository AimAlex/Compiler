//
//  VirtualRegister.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef VirtualRegister_h
#define VirtualRegister_h
class VirtualRegister : public Register {
public:
    std::string hintName;
    int ssaId = -1;
    std::shared_ptr<IntValue> oldName = NULL;
    std::shared_ptr<IntValue> physicalRegister = NULL;
};

#endif /* VirtualRegister_h */
