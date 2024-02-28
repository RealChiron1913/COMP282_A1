#include "DenseTuringMachine.h"
#include "TuringMachineState.h"
#include <vector>

DenseTuringMachine::DenseTuringMachine(int x, int y): m(x), n(y){

//填充x*y的表
    if (x != -1&&y != -1) {
        for (int i=0;i<=x;i++) {
            std::vector<TuringMachineState> temp;
            for (int j=0;j<=y;j++) {
                temp.emplace_back(-1,-1,-1,-1,"");
            }
            state_map.push_back(temp);
        }
    }
    if (x == -1 && y != -1){
        std::vector<TuringMachineState> temp;
        for (int j=0;j<=y;j++) {
            temp.emplace_back(-1,-1,-1,-1,"");
        }
        state_map.push_back(temp);
        maxContent = y;
    }
    if (y == -1 && x != -1){
        for (int i=0;i<=x;i++) {
            std::vector<TuringMachineState> temp;
            temp.emplace_back(-1,-1,-1,-1,"");
            state_map.push_back(temp);
        }
        maxState = x;
    }
    if (x == -1 && y == -1){
        std::vector<TuringMachineState> temp;
        temp.emplace_back(-1,-1,-1,-1,"");
        state_map.push_back(temp);
    }
}

TuringMachineState *DenseTuringMachine::find(int x, int y) {
//    cout << state_map.size() << " " << state_map[0].size() << endl;
    if (x>=state_map.size()||y>=state_map[0].size()||x<0||y<0) {
        return NULL;
    }
    if (state_map[x][y].getCurrentState()==-1&&state_map[x][y].getCurrentContent()==-1) {
        return NULL;
    }
    else {return &state_map[x][y];}
}

void DenseTuringMachine::add(TuringMachineState &s) {
    if (s.getCurrentState()>maxState && m == -1) {
        for (int i=maxState;i<s.getCurrentState();i++) {
            std::vector<TuringMachineState> temp;
            for (int j=0;j<=maxContent;j++) {
                temp.emplace_back(-1,-1,-1,-1,"");
            }
            state_map.push_back(temp);
        }
        maxState=s.getCurrentState();
    }
    if (s.getCurrentContent()>maxContent && n == -1) {
        for (int i=0;i<=maxState;i++) {
            for (int j=maxContent;j<s.getCurrentContent();j++) {
                state_map[i].emplace_back(-1,-1,-1,-1,"");
            }
        }
        maxContent=s.getCurrentContent();
    }

    if (s.getCurrentState()>=state_map.size()||s.getCurrentContent()>=state_map[0].size()) {
        return;
    }
    state_map[s.getCurrentState()][s.getCurrentContent()]=s;
}


std::vector<TuringMachineState> *DenseTuringMachine::getAll() {
    auto *temp = new std::vector<TuringMachineState>();
    for (auto & i : state_map) {
        for (auto & j : i) {
            if (j.getCurrentState()!=-1&&j.getCurrentContent()!=-1) {
                temp->push_back(j);
            }
        }
    }
    return temp;
}

