//
//  GraphColor.h
//  antlrcpp-demo
//
//  Created by 李江贝 on 2018/6/5.
//  Copyright © 2018 ANTLR4 Project. All rights reserved.
//

#ifndef GraphColor_h
#define GraphColor_h
class GraphColor{
public:
    class graphNode{
    public:
        std::set<std::shared_ptr<graphNode>> neighbours;
        std::set<std::shared_ptr<graphNode>> sameNodes;
        bool removed = false;
        int degree = 0;
        std::shared_ptr<PhysicalRegister> preColor = NULL;
        std::shared_ptr<Register> color = NULL;
    };
    std::shared_ptr<Function> curFunction;
    std::shared_ptr<IRRoot> irRoot;
    int colorNum;
    std::vector<std::shared_ptr<graphNode>> easyNode;
    std::vector<std::shared_ptr<graphNode>> order;
    std::map<std::shared_ptr<VirtualRegister>,std::shared_ptr<PhysicalRegister>> phyMap;
    std::map<std::shared_ptr<VirtualRegister>, std::shared_ptr<graphNode>> graphMap;
    std::set<std::shared_ptr<graphNode>> nodeList;
    GraphColor(std::shared_ptr<IRRoot> ir){
        irRoot = ir;
    }
    
    void colorProcess(){
        for(std::map<std::string, std::shared_ptr<Function>>::iterator iter = irRoot -> functions.begin(); iter != irRoot -> functions.end(); ++iter) {
            curFunction = iter -> second;
            phyMap.clear();
            graphMap.clear();
            nodeList.clear();
            GraphConstruct();
            ColorNode();
            
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
    
    void delNode(std::shared_ptr<graphNode> node){
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
        easyNode.pop_back();
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
                delNode(niceNode);
            }
            std::shared_ptr<graphNode> badNode = *(nodeList.begin());
            delNode(badNode);
        }
        
        
    }
};

#endif /* GraphColor_h */
