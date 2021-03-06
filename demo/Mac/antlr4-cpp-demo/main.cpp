/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <iostream>

#include "antlr4-runtime.h"
#include "MLexer.h"
#include "MParser.h"
#include "ASTListener.h"
#include "ASTPrinter.h"
#include "ASTClass.h"
#include "ASTFunction.h"
#include "SemanticCheck.h"
#include "IRBuilder.h"
#include "IRPrinter.h"
#include "IRPrepare.h"
#include "NASMPrinter.h"
#include "DeadNASM.h"
#include "LivenessAnalysis.h"
#include "GraphColor.h"
#include "X86Printer.h"
#include "GraphAllocate.h"
using namespace antlrcpptest;
using namespace antlr4;

int main(int , const char ** ) {
    ANTLRFileStream file("./test.mx");
//    ANTLRFileStream file("/Users/aimalex/Desktop/Compiler/Mcode/sample.mx");
    ANTLRInputStream input(file);
    MLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    
    tokens.fill();

    
    MParser parser(&tokens);
    tree::ParseTree *tree = parser.program();
    
    
    tree::ParseTreeWalker walker = *new tree::ParseTreeWalker();
    auto listener = std::make_shared<ASTListener>();
    walker.walk(listener.get(), tree);
//    auto printer = std::make_shared<ASTPrinter>();
//    (listener->getProgram()) -> visited(printer);
    auto classer = std::make_shared<ASTClass>();
    (listener -> getProgram()) -> visited(classer);
    auto functioner = std::make_shared<ASTFunction>();
    (listener -> getProgram()) -> visited(functioner);
    auto checker = std::make_shared<SemanticCheck>();
    (listener -> getProgram()) -> visited(checker);
    auto Prepare = std::make_shared<IRPrepare>();
    (listener -> getProgram()) -> visited(Prepare);
    auto Builder = std::make_shared<IRBuilder>();
    (listener -> getProgram()) -> visited(Builder);
//    auto IRPrint = std::make_shared<IRPrinter>();
//    (Builder -> getRoot()) -> visited(IRPrint);
    auto liveness = LivenessAnalysis(Builder -> getRoot());
    liveness.livenessRoot();
    auto colorGraph = GraphColor(Builder -> getRoot());
    colorGraph.colorProcess();
//    auto IRPrint2 = std::make_shared<IRPrinter>();
//    (Builder -> getRoot()) -> visited(IRPrint2);
//    auto DeadIR = std::make_shared<DeadNASM>();
//    (Builder -> getRoot()) -> visited(DeadIR);
//    auto NASMPrint = std::make_shared<NASMPrinter>();
//    (Builder -> getRoot()) -> visited(NASMPrint);
    auto Allocate = std::make_shared<GraphAllocate>();
    (Builder -> getRoot()) -> visited(Allocate);
    auto x86Printer = std::make_shared<X86Printer>();
        (Builder -> getRoot()) -> visited(x86Printer);
    return 0;
}
