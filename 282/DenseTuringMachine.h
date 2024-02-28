#ifndef DENSETURINGMACHINE_H_
#define DENSETURINGMACHINE_H_
#include "TuringMachine.h"
#include <vector>


class DenseTuringMachine : public TuringMachine {
public:
    std::vector<std::vector<TuringMachineState> > states;
    DenseTuringMachine(int x, int y);
    //DenseTuringMachine(int x, int y), creates a new DenseTuringMachine in which each TuringMachineState has current state <= x and current content <= y (when x and y are non-negative).
    TuringMachineState* find(int x,int y);
    //TuringMachineState* find(int x, int y), which should return the TuringMachineState that has current state x and current content y or NULL if no such TuringMachineState exist at the time the command is run
    void add(TuringMachineState& s);
    //void add(TuringMachineState s), which should add s to the states that could be found.
    std::vector<TuringMachineState>* getAll();
    //vector<TuringMachineState>* getAll(), which should return a pointer to the vector of all TuringMachineStates, in some order.
};
#endif /* DENSETURINGMACHINE_H_ */
