#ifndef MENUSYSTEM_H_
#define MENUSYSTEM_H_
#include "TuringMachine.h"
#include "DenseTuringMachine.h"
#include "SparseTuringMachine.h"
#include "TuringTape.h"

class MenuSystem {
public:
    void menu();
    int maxState{}, maxContent{};
    DenseTuringMachine dtm{maxState, maxContent};
    SparseTuringMachine stm{};
    TuringMachineState x = TuringMachineState(-1, -1, 0, 0, "");
    vector<TuringMachineState> tms;
    TuringTape tape = TuringTape(1);
    string denseOrSparse;
    int state = 0;
    int step_total = 0;
    int tapeLength;

};
#endif /* MENUSYSTEM_H_ */