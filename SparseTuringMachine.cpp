//
// Created by Gubin Zhao on 2023/4/24.
//

#include "SparseTuringMachine.h"

SparseTuringMachine::SparseTuringMachine() {
    stm = std::vector<TuringMachineState>();
}

TuringMachineState *SparseTuringMachine::find(int x, int y) {
    for (auto & state : stm) {
        if (state.getCurrentState()==x && state.getCurrentContent()==y) {
            return &state;
        }
    }
    return NULL;
}

void SparseTuringMachine::add(TuringMachineState &s) {
    stm.push_back(s);
}

std::vector<TuringMachineState> *SparseTuringMachine::getAll() {
    return &stm;
}
