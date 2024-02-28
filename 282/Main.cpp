#include <iostream>
#include "TuringMachineState.h"
#include <vector>
#include "DenseTuringMachine.h"
#include "TuringTape.h"
#include "SparseTuringMachine.h"
#include "MenuSystem.h"
#include "TuringMachine.h"


using namespace std;

void checkFirst() {
	TuringMachineState t1(1,2,3,4,"->");
	TuringMachineState t2(5,6,7,8,"<-");
	cout<<t1.getCurrentState()<<" "<<t1.getCurrentContent()<<" "<<t1.getNextState()<<" "<<t1.getNextContent()<<" "<<t1.getMoveDirection()<<endl;
	cout<<t2.getCurrentState()<<" "<<t2.getCurrentContent()<<" "<<t2.getNextState()<<" "<<t2.getNextContent()<<" "<<t2.getMoveDirection()<<endl;
}
void checkSecond() {
	TuringMachineState t1(1,2,3,4,"->");
	cout <<t1<<endl;
	TuringMachineState t2(5,6,7,8,"<-");
	cout <<t2<<endl;
	cin >> t1;
	cin >> t2;
	cout<<t1.getCurrentState()<<" "<<t1.getCurrentContent()<<" "<<t1.getNextState()<<" "<<t1.getNextContent()<<" "<<t1.getMoveDirection()<<endl;
	cout<<t2.getCurrentState()<<" "<<t2.getCurrentContent()<<" "<<t2.getNextState()<<" "<<t2.getNextContent()<<" "<<t2.getMoveDirection()<<endl;
}
void testAll(vector<TuringMachineState> vec) {
	for (auto s: vec) {
		for (auto t:vec) {
			cout << (s<t)<<(s>t)<<(s==t)<<endl;
		}
	}
}

void checkThird() {
	vector<TuringMachineState> vec;
	vec.push_back(TuringMachineState(1,2,3,4,"->"));
	vec.push_back(TuringMachineState(2,1,7,8,"<-"));
	vec.push_back(TuringMachineState(2,1,3,4,"->"));
	vec.push_back(TuringMachineState(1,1,10,10,"<-"));
	testAll(vec);
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
void checkTape(TuringTape t) {
	cout<<t.moveLeft();
	for (int i=0;i<10;i++) {
		cout<<t.moveRight();
		t.setContent(i);
	}
	for (int i=0;i<10;i++) {
		cout<<t.moveLeft();
		cout<<t.getContent();
	}
}

void checkFifth() {
	TuringTape t(10);
	checkTape(t);
}

void checkMenu() {
	MenuSystem m;
	m.menu();
}


void checkSeventh() {
	SparseTuringMachine s;
	checkTuringMachine(&s);
	checkMenu();
}

void checkEigth() {
	TuringTape t(-1);
	checkTape(t);

	DenseTuringMachine d(-1,-1);
	checkTuringMachine(&d);

	checkMenu();
}


int main() {
	int task;
	cin >> task;
	if (task==1) checkFirst();
	if (task==2) checkSecond();
	if (task==3) checkThird();
	if (task==4) {
		DenseTuringMachine d(10,10);
		checkTuringMachine(&d);
	}
	if (task==5) checkFifth();
	if (task==6) checkMenu();
	if (task==7) checkSeventh();
	if (task==8) checkEigth();
	cin >> task;

}
