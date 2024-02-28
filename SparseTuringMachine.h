#ifndef SPARSETURINGMACHINE_H_
#define SPARSETURINGMACHINE_H_
#include "TuringMachine.h"
#include <vector>
class SparseTuringMachine : public TuringMachine {
public:
    SparseTuringMachine();
    std::vector<TuringMachineState> stm;

    TuringMachineState* find(int x,int y);
    void add(TuringMachineState& s);
    std::vector<TuringMachineState>* getAll();
};
#endif /* SPARSETURINGMACHINE_H_ */
