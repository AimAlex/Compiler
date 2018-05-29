//
//  IRVisitor.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/5/25.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef IRVisitor_h
#define IRVisitor_h
class IRRoot;
class BasicBlock;
class Function;
class BinaryOperation;
class UnaryOperation;
class IntComparison;
class IntImmediate;
class Branch;
class Return;
class Jump;
class VirtualRegister;
class Move;
class Load;
class Jump;
class Store;
class Return;
class StaticString;
class StaticSpace;
class HeapAllocate;
class Call;
class ClassRoot;

class IRVisitor{
public:
    virtual void visit(std::shared_ptr<IRRoot> node) = 0;
    virtual void visit(std::shared_ptr<BasicBlock> node) = 0;
    virtual void visit(std::shared_ptr<Function> node) = 0;
    
    virtual void visit(std::shared_ptr<BinaryOperation> node) = 0;
    virtual void visit(std::shared_ptr<UnaryOperation> node) = 0;
    virtual void visit(std::shared_ptr<IntComparison> node) = 0;
    virtual void visit(std::shared_ptr<IntImmediate> node) = 0;
//    void visit(Call node);
//    void visit(SystemCall node);
//    void visit(PhiInstruction node);
//
    virtual void visit(std::shared_ptr<Branch> node) = 0;
    virtual void visit(std::shared_ptr<Return> node) = 0;
    virtual void visit(std::shared_ptr<Jump> node) = 0;

    virtual void visit(std::shared_ptr<VirtualRegister> node) = 0;
//    void visit(PhysicalRegister node);
//    void visit(StackSlot node);
    virtual void visit(std::shared_ptr<HeapAllocate> node) = 0;
    virtual void visit(std::shared_ptr<Load> node) = 0;
    virtual void visit(std::shared_ptr<Store> node) = 0;
    virtual void visit(std::shared_ptr<Move> node) = 0;

    virtual void visit(std::shared_ptr<StaticSpace> node) = 0;
    virtual void visit(std::shared_ptr<StaticString> node) = 0;
    virtual void visit(std::shared_ptr<Call> node) = 0;
    virtual void visit(std::shared_ptr<ClassRoot> node) = 0;
};

#endif /* IRVisitor_h */
