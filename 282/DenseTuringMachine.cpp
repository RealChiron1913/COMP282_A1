#include "DenseTuringMachine.h"
#include <vector>
#include <iostream>

DenseTuringMachine::DenseTuringMachine(int x, int y) {
    for (int i=0; i<=x; i++) {
        std::vector<TuringMachineState> v;
        for (int j=0; j<=y; j++) {
            TuringMachineState tms(0,0,0,0,"");
            v.push_back(tms);
        }
        states.push_back(v);
    }

}

TuringMachineState *DenseTuringMachine::find(int x, int y) {
    if (x<states.size()&&y<states[x].size()) {
        if (states[x][y].getCurrentState()!=0 && states[x][y].getCurrentContent()!=0) {
            return &states[x][y];
        }
    }
    return nullptr;
}

void DenseTuringMachine::add(TuringMachineState &s) {
    if (s.getCurrentState()<states.size()&&s.getCurrentContent()<states[s.getCurrentState()].size()) {
        states[s.getCurrentState()][s.getCurrentContent()]=s;
    }
}

std::vector<TuringMachineState> *DenseTuringMachine::getAll() {
    std::vector<TuringMachineState> *v = new std::vector<TuringMachineState>();
    for (int i=0; i<states.size(); i++) {
        for (int j=0; j<states[i].size(); j++) {
            if(states[i][j].getCurrentState()!=0 && states[i][j].getCurrentContent()!=0){
                v->push_back(states[i][j]);
            }
        }
    }
    return v;
}


bool compareState(TuringMachineState s1, TuringMachineState s2) {
	return (s1.getCurrentState()<s2.getCurrentState())||(s1.getCurrentState()==s2.getCurrentState())&&s1.getCurrentContent()<s2.getCurrentContent();
}


void checkTuringMachine(TuringMachine* t) {
	TuringMachineState s1(1,2,3,4,"->");
	t->add(s1);
	TuringMachineState s2(5,6,7,8,"<-");

	t->add(s2);
	cout << *t->find(1,2);
	cout << *t->find(1,1)<<endl;
	cout << (t->find(1,3)==NULL)<<endl;
	vector<TuringMachineState> vec=*t->getAll();
	sort(vec.begin(),vec.end(),compareState);
	for (auto s: *t->getAll()) cout << s;
}

int main() {
    DenseTuringMachine t(10, 10);
    checkTuringMachine(&t);
    return 0;
}