//
//  IRPrinter.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/25.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRPrinter_h
#define IRPrinter_h
#include "IRVisitor.h"
class IRPrinter : public IRVisitor, public std::enable_shared_from_this<IRPrinter>{
public:
    void visit(std::shared_ptr<IRRoot> node){
        std::cout<<"hhh"<<std::endl;
    }
    
    void visit(std::shared_ptr<BasicBlock> node){
        
    }
    
    void visit(std::shared_ptr<Function> node){
        
    }
    
    void visit(std::shared_ptr<BinaryOperation> node){}
    void visit(std::shared_ptr<UnaryOperation> node){}
    void visit(std::shared_ptr<IntComparison> node){}
    void visit(std::shared_ptr<IntImmediate> node){}
    //    void visit(Call node);
    //    void visit(SystemCall node);
    //    void visit(PhiInstruction node);
    //
    void visit(std::shared_ptr<Branch> node){}
    void visit(std::shared_ptr<Return> node){}
    void visit(std::shared_ptr<Jump> node){}
    
    void visit(std::shared_ptr<VirtualRegister> node){}
    //    void visit(PhysicalRegister node);
    //    void visit(StackSlot node);
    void visit(std::shared_ptr<HeapAllocate> node){}
    void visit(std::shared_ptr<Load> node){}
    void visit(std::shared_ptr<Store> node){}
    void visit(std::shared_ptr<Move> node){}
    
    void visit(std::shared_ptr<StaticSpace> node){}
    void visit(std::shared_ptr<StaticString> node){}
};

#endif /* IRPrinter_h */
