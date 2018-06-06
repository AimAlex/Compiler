//
//  GraphColor.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/5.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef GraphColor_h
#define GraphColor_h
class graphNode{
public:
    std::set<std::shared_ptr<graphNode>> neighbours;
    std::set<std::shared_ptr<graphNode>> sameNodes;
    bool removed = false;
    int degree = 0;
    std::shared_ptr<PhysicalRegister> preColor = NULL;
    std::shared_ptr<Register> color = NULL;
};
class GraphColor{
public:
    std::shared_ptr<Function> curFunction;
    std::shared_ptr<IRRoot> irRoot;
    int colorNum;
    std::vector<std::shared_ptr<graphNode>> easyNode;
    std::vector<std::shared_ptr<graphNode>> order;
    std::set<std::shared_ptr<PhysicalRegister>> usedColor;
    std::vector<std::shared_ptr<PhysicalRegister>> physicalList;
    std::map<std::shared_ptr<VirtualRegister>,std::shared_ptr<PhysicalRegister>> phyMap;
    std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<graphNode>> graphMap;
    std::set<std::shared_ptr<graphNode>> nodeList;
    std::map<std::shared_ptr<graphNode>, std::shared_ptr<StackSlot>> slots;
    GraphColor(std::shared_ptr<IRRoot> ir){
        irRoot = ir;
        physicalList.push_back(std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r12")));
        physicalList.push_back(std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r13")));
        physicalList.push_back(std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r14")));
        physicalList.push_back(std::shared_ptr<PhysicalRegister>(new PhysicalRegister("r15")));
        colorNum = 4;
    }
    
    void colorProcess(){
        for(std::map<std::string, std::shared_ptr<Function>>::iterator iter = irRoot -> functions.begin(); iter != irRoot -> functions.end(); ++iter) {
            curFunction = iter -> second;
            phyMap.clear();
            graphMap.clear();
            nodeList.clear();
            order.clear();
            easyNode.clear();
            GraphConstruct();
            ColorNode();
            allocReg();
            for(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<graphNode>>::iterator iter = graphMap.begin(); iter != graphMap.end(); ++iter){
                curFunction -> graphMap[iter -> first] = iter -> second;
            }
        }
        
        for(std::map<std::string, std::shared_ptr<ClassRoot>>::iterator iter = irRoot -> classList.begin(); iter != irRoot -> classList.end(); ++iter){
            for(std::map<std::string, std::shared_ptr<Function>>::iterator iter2 = iter -> second -> functions.begin(); iter2 != iter -> second -> functions.end(); ++iter2){
                curFunction = iter2 -> second;
                phyMap.clear();
                graphMap.clear();
                nodeList.clear();
                order.clear();
                easyNode.clear();
                GraphConstruct();
                ColorNode();
                allocReg();
                for(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<graphNode>>::iterator iter = graphMap.begin(); iter != graphMap.end(); ++iter){
                    curFunction -> graphMap[iter -> first] = iter -> second;
                }
            }
            if(iter -> second -> constructor != NULL){
                curFunction = iter -> second -> constructor;
                phyMap.clear();
                graphMap.clear();
                nodeList.clear();
                order.clear();
                easyNode.clear();
                GraphConstruct();
                ColorNode();
                allocReg();
                for(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<graphNode>>::iterator iter = graphMap.begin(); iter != graphMap.end(); ++iter){
                    curFunction -> graphMap[iter -> first] = iter -> second;
                }
            }
        }
    }
    
    std::shared_ptr<graphNode> getNode(std::shared_ptr<VirtualRegister> reg){
        
        std::shared_ptr<graphNode> node = graphMap[reg];
        if(node == NULL){
            node = std::shared_ptr<graphNode>(new graphNode);
            graphMap[reg] = node;
        }
        return node;
    }
    
    void linkReg(std::shared_ptr<VirtualRegister> reg1, std::shared_ptr<VirtualRegister> reg2){
        linkNode(getNode(reg1), getNode(reg2));
    }
    
    void linkNode(std::shared_ptr<graphNode> node1, std::shared_ptr<graphNode> node2){
        node1 -> neighbours.insert(node2);
        node2 -> neighbours.insert(node1);
    }
    
    void GraphConstruct(){
        std::vector<std::shared_ptr<Register>> parList(curFunction -> argVarRegList);
        for(int i = 0; i < parList.size(); ++i) {
            getNode(std::dynamic_pointer_cast<VirtualRegister>(parList[i]));
        }
        for(int i = 0; i < parList.size(); ++i) {
            for(int j = 0; j < parList.size(); ++j){
                if(parList[i] != parList[j]){
                    linkReg(std::dynamic_pointer_cast<VirtualRegister>(parList[i]), std::dynamic_pointer_cast<VirtualRegister>(parList[j]));
                }
            }
        }
        std::vector<std::shared_ptr<BasicBlock>> BlockList(curFunction -> getReversePreOrder());
        for(int i = 0; i < BlockList.size(); ++i){
            for(std::shared_ptr<IRInstruction> inst = BlockList[i] -> head; inst != NULL; inst = inst -> next){
                std::shared_ptr<Register> modifyReg = inst -> getDefRegister();
                if(modifyReg == NULL || modifyReg -> getType() != "VirtualRegister"){
                    continue;
                }
                std::shared_ptr<graphNode> modifyNode = getNode(std::dynamic_pointer_cast<VirtualRegister>(modifyReg));
                for(std::set<std::shared_ptr<Register>>::iterator iter = inst -> liveOut.begin(); iter != inst -> liveOut.end(); ++iter){
                    if(*iter != modifyReg) {
                        linkReg(std::dynamic_pointer_cast<VirtualRegister>(*iter), std::dynamic_pointer_cast<VirtualRegister>(modifyReg));
                    }
                }
            }
        }
        for(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<graphNode>>::iterator iter = graphMap.begin(); iter != graphMap.end(); ++iter){
            iter -> second -> degree = iter -> second -> neighbours.size();
            nodeList.insert(iter -> second);
        }
    }
    
    void delNode(std::shared_ptr<graphNode> node, bool iseasy){
        if(node -> removed) return;
        for(std::set<std::shared_ptr<graphNode>>::iterator iter = node -> neighbours.begin(); iter != node -> neighbours.end(); ++iter){
            if(!((*iter) -> removed)){
                (*iter) -> degree --;
                if((*iter) -> degree < colorNum && (std::find(easyNode.begin(), easyNode.end(), (*iter))   == easyNode.end())){
                    easyNode.push_back(*iter);
                }
            }
        }
        node -> removed = true;
        nodeList.erase(node);
            for(std::vector<std::shared_ptr<graphNode>>::iterator iter = easyNode.begin(); iter != easyNode.end(); ++iter){
                if(*iter == node){
                    easyNode.erase(iter);
                    break;
                }
            }
        order.push_back(node);
    }
    void ColorNode(){
        for(std::set<std::shared_ptr<graphNode>>::iterator iter = nodeList.begin(); iter != nodeList.end(); ++iter){
            if((*iter) -> degree < colorNum){
                easyNode.push_back(*iter);
            }
        }
        
        while(!nodeList.empty()){
            while(!easyNode.empty()){
                std::shared_ptr<graphNode> niceNode = easyNode[easyNode.size() - 1];
//                order.push_back(niceNode);
                delNode(niceNode, 1);
            }
            if(!nodeList.empty()){
                std::shared_ptr<graphNode> badNode = *(nodeList.begin());
                delNode(badNode, 0);
            }
        }
        
        while(!order.empty()){
            std::shared_ptr<graphNode> colorNode = order[order.size() - 1];
            order.pop_back();
            usedColor.clear();
            for(std::set<std::shared_ptr<graphNode>>::iterator iter = colorNode -> neighbours.begin(); iter != colorNode -> neighbours.end(); ++iter){
                if(!(*iter) -> removed && (*iter) -> color -> getType() == "PhysicalRegister"){
                    usedColor.insert(std::dynamic_pointer_cast<PhysicalRegister>((*iter) -> color));
                }
            }
            
            for(std::set<std::shared_ptr<graphNode>>::iterator iter = colorNode -> sameNodes.begin(); iter != colorNode -> sameNodes.end(); ++iter){
                std::shared_ptr<Register> color = (*iter) -> color;
                if(color -> getType() == "PhysicalRegister" && usedColor.find(std::dynamic_pointer_cast<PhysicalRegister>(color)) == usedColor.end()){
                    colorNode -> color = color;
                    break;
                }
            }
            
            if(colorNode -> color == NULL){
                for(int t = 0; t < physicalList.size(); ++t){
                    if(usedColor.find(physicalList[t]) == usedColor.end()){
                        colorNode -> color = physicalList[t];
                    }
                }
                
                if(colorNode -> color == NULL){
                    colorNode -> color = getSlot(colorNode);
                }
            }
            colorNode -> removed = false;
        }
    }
    
    std::shared_ptr<StackSlot> getSlot(std::shared_ptr<graphNode> node){
        if(slots.find(node) == slots.end()) {
            bool ispar = 1;
            for(std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<graphNode>>::iterator iter = graphMap.begin(); iter != graphMap.end();++iter){
                if(iter -> second == node){
                    for(int i = 0; i < curFunction -> argVarRegList.size(); ++i){
                        if(curFunction -> argVarRegList[i] == iter -> first && i >= 6){
                            slots[node] = std::shared_ptr<StackSlot>(new StackSlot(curFunction, "",-(curFunction -> argVarRegList.size() - 1 - i) * 8 - 8));
                            ispar = 0;
                        }
                    }
                }
            }
            if(ispar){
                slots[node] = std::shared_ptr<StackSlot> (new StackSlot(curFunction, "", curFunction -> stackSize));
            
                curFunction -> stackSize += 8;
            }
            //            //std::cout<<"hhh"<<std::endl;
        }
        return slots.find(node) -> second;
    }
    
    void allocReg(){
        for(int i = 0; i < curFunction -> argVarRegList.size(); ++i){
            std::shared_ptr<Register>alloc = graphMap[std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[i])] -> color;
            curFunction -> argVarRegList[i] = alloc;
            if(i >= 6){
                std::shared_ptr<StackSlot> slot(new StackSlot(curFunction, "",-(curFunction -> argVarRegList.size() - 1 - i) * 8 - 8));
//                curFunction -> argVarRegList[i] = slot;
                getNode(std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[i])) -> color = slot;
//                slots[graphMap[std::dynamic_pointer_cast<VirtualRegister>(curFunction -> argVarRegList[i])]] = slot;
                                                curFunction -> parSlots.push_back(slot);
                
            }
        }
        std::vector<std::shared_ptr<BasicBlock>> BlockList(curFunction -> getReversePreOrder());
        for(int i = 0; i < BlockList.size(); ++i) {
            for(std::shared_ptr<IRInstruction> inst = BlockList[i] -> head; inst != NULL; inst = inst -> next){
                std::vector<std::shared_ptr<Register>> usedRegs(inst -> getRegister());
                if(inst -> getType() == "Call"){
                    std::vector<std::shared_ptr<Register>> para((std::dynamic_pointer_cast<Call>(inst)) -> args);
                    for (int t = 0; t < para.size(); ++t) {
                        std::shared_ptr<Register> val = para[t];
//                        std::cout<<val -> getType()<<std::endl;
                        if (val -> getType() ==  "VirtualRegister"){
                            (std::dynamic_pointer_cast<Call>(inst)) -> args[t] = graphMap[std::dynamic_pointer_cast<VirtualRegister>(val)] -> color;
                        }
                    }
                    inst -> refreshRegister(phyMap);
                }
                else{
                    if(!usedRegs.empty()){
                        phyMap.clear();
                        bool flag = false;
                        for(int t = 0; t < usedRegs.size(); ++t){
                            if(usedRegs[t]-> getType() == "VirtualRegister"){
                                std::shared_ptr<PhysicalRegister> allocReg = NULL;
                                std::shared_ptr<Register> color = graphMap[std::dynamic_pointer_cast<VirtualRegister>(usedRegs[t])] -> color;
                                if(color -> getType() == "PhysicalRegister"){
                                    allocReg = std::dynamic_pointer_cast<PhysicalRegister>(color);
                                }
                                else if(color -> getType() == "StackSlot"){
                                    if(flag){
                                        allocReg = std::shared_ptr<PhysicalRegister> (new PhysicalRegister("rbx"));
                                    }
                                    else{
                                        allocReg = std::shared_ptr<PhysicalRegister> (new PhysicalRegister("rsi"));
                                    }
                                    flag = true;
                                    inst -> prepend(std::shared_ptr<IRInstruction>(new Load(BlockList[i], allocReg, INTSIZE, color, 0)));
                                }
                                phyMap[std::dynamic_pointer_cast<VirtualRegister>(usedRegs[t])] = allocReg;
                            }
                        }
                        inst -> refreshRegister(phyMap);
                    }
                }
                std::shared_ptr<Register> defReg = inst -> getDefRegister();
                if(defReg != NULL && defReg -> getType() == "VirtualRegister"){
                    std::shared_ptr<PhysicalRegister> allocReg = NULL;
                    std::shared_ptr<Register> color = graphMap[std::dynamic_pointer_cast<VirtualRegister>(defReg)] -> color;
                    if(color->getType() ==  "PhysicalRegister"){
                        allocReg = std::dynamic_pointer_cast<PhysicalRegister>(color);
                        inst -> setDefRegister(allocReg);
                    }
                    else if(color-> getType() == "StackSlot"){
                        allocReg = std::shared_ptr<PhysicalRegister>(new PhysicalRegister("rbx"));
                        inst -> next -> prepend (std::shared_ptr<IRInstruction>(new Store(BlockList[i], allocReg, 8, color, 0)));
                        inst -> setDefRegister(allocReg);
                        inst = inst -> next;
                    }
                }
            }
        }
    }
};

#endif /* GraphColor_h */
