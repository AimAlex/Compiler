//
//  LivenessAnalysis.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/5.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef LivenessAnalysis_h
#define LivenessAnalysis_h
#include "IRBuilder.h"
class LivenessAnalysis : public std::enable_shared_from_this<LivenessAnalysis> {
public:
    std::shared_ptr<IRRoot> irRoot;
    LivenessAnalysis(std::shared_ptr<IRRoot> ir){
        irRoot = ir;
    }
    void livenessRoot(){
        for(std::map<std::string, std::shared_ptr<Function>>::iterator iter = irRoot -> functions.begin(); iter != irRoot -> functions.end(); ++iter) {
            AnalysisProcess(iter -> second);
        }
        for(std::map<std::string, std::shared_ptr<ClassRoot>>::iterator iter = irRoot -> classList.begin(); iter != irRoot -> classList.end(); ++iter){
            for(std::map<std::string, std::shared_ptr<Function>>::iterator iter2 = iter -> second -> functions.begin(); iter2 != iter -> second -> functions.end(); ++iter2){
                AnalysisProcess(iter2 -> second);
            }
        }
    }
    void AnalysisProcess(std::shared_ptr<Function> func){
        std::vector<std::shared_ptr<BasicBlock>> BlockList(func -> getReversePreOrder());
        for(int i = 0; i < BlockList.size(); ++i){
            for(std::shared_ptr<IRInstruction> inst = BlockList[i] -> head; inst != NULL; inst = inst -> next){
                inst -> liveIn.clear();
                inst -> liveOut.clear();
            }
        }
        std::set<std::shared_ptr<Register>> livein;
        std::set<std::shared_ptr<Register>> liveout;
        
        bool ifChange = 1;
        while(ifChange){
            ifChange = 0;
            for(int i = 0; i < BlockList.size(); ++i) {
                for(std::shared_ptr<IRInstruction> inst = BlockList[i] -> last; inst != NULL; inst = inst -> prev){
                    livein.clear();
                    liveout.clear();
                    for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> liveIn.begin(); iter != inst -> liveIn.end(); ++iter){
                        livein.insert(*iter);
                    }
                    inst -> liveIn.clear();
                    for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> liveOut.begin(); iter != inst -> liveOut.end(); ++iter){
                        liveout.insert(*iter);
                    }
                    inst -> liveOut.clear();
                    
                    if(inst -> getType() == "Branch"){
                        inst = std::dynamic_pointer_cast<Branch>(inst);
                        if(inst -> getThen() -> head != NULL){
                            for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> getThen() -> head -> liveIn.begin(); iter != inst -> getThen() -> head -> liveIn.end(); ++iter){
                                inst -> liveOut.insert(*iter);
                            }
                        }
                        if(inst -> getElse() -> head != NULL){
                            for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> getElse() -> head -> liveIn.begin(); iter != inst -> getElse() -> head -> liveIn.end(); ++iter){
                                inst -> liveOut.insert(*iter);
                            }
                        }
                    }
                    else if(inst -> getType() == "Jump"){
                        inst = std::dynamic_pointer_cast<Jump>(inst);
                        if(inst ->  getTarget() -> head != NULL){
                            for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> getTarget() -> head -> liveIn.begin(); iter != inst -> getTarget() -> head -> liveIn.end(); ++iter){
                                inst -> liveOut.insert(*iter);
                            }
                        }
                    }
                    else if(inst -> getType() != "Return"){
                        for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> next -> liveIn.begin(); iter != inst -> next -> liveIn.end(); ++iter){
                                inst -> liveOut.insert(*iter);
                        }
                    }
                    std::vector<std::shared_ptr<Register>> vec(inst -> getRegister());
                    for(int i = 0; i < vec.size(); ++i) {
                        inst -> liveIn.insert(vec[i]);
                    }
                    for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> liveOut.begin(); iter != inst -> liveOut.end(); ++iter){
                        inst -> liveIn.insert(*iter);
                    }
                    std::shared_ptr<Register> modifyRegister = inst -> getDefRegister();
                    
                    if(modifyRegister != NULL && modifyRegister -> getType() == "VirtualRegister"){
                        int isused = 0;
                        for(int i = 0; i < vec.size(); ++i) {
                            if(vec[i] == modifyRegister){
                                isused = 1;
                                break;
                            }
                        }
                        if(isused == 0){
                            inst -> liveIn.erase(modifyRegister);
                        }
                    }
                    
                    for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> liveOut.begin(); iter != inst -> liveOut.end(); ++iter){
                        if(liveout.find(*iter) == liveout.end()){
                            ifChange = 1;
                            break;
                        }
                    }
                    for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> liveIn.begin(); iter != inst -> liveIn.end(); ++iter){
                        if(livein.find(*iter) == livein.end()){
                            ifChange = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
};

#endif /* LivenessAnalysis_h */
