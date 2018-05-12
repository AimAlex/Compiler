//
//  HeapAllocate.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/12.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef HeapAllocate_h
#define HeapAllocate_h
class HeapAllocate : public IRInstruction {
public:
    std::shared_ptr<IntValue> dest;
    std::shared_ptr<IntValue> allocSize;
};

#endif /* HeapAllocate_h */
