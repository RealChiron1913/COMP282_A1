#ifndef DENSETURINGMACHINE_H_
#define DENSETURINGMACHINE_H_
#include "TuringMachine.h"
#include <iostream>
#include "TuringMachineState.h"
#include <vector>


class DenseTuringMachine : public TuringMachine {
public:
    std::vector<TuringMachineState>  states;
    std::vector<vector<TuringMachineState>> state_map;
    int maxState{0}, maxContent{0};
    int m,n;
    DenseTuringMachine(int x, int y);
    TuringMachineState* find(int x,int y);
    void add(TuringMachineState& s);
    std::vector<TuringMachineState>* getAll();

};
#endif /* DENSETURINGMACHINE_H_ */
