#include "TuringMachineState.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int TuringMachineState::getCurrentState() {
    return current_state;
}
int TuringMachineState::getCurrentContent()  {
    return current_content;
}
int TuringMachineState::getNextState()  {
    return next_state;
}
int TuringMachineState::getNextContent()  {
    return next_content;
}
string TuringMachineState::getMoveDirection() {
    return move_direction;
}

TuringMachineState::TuringMachineState(int current_state, int current_content, int next_state, int next_content,
                                       const string& move_direction) : current_state(current_state), current_content(current_content), next_state(next_state), next_content(next_content), move_direction(move_direction) {}


ostream& operator<<(ostream& os, TuringMachineState& tms) {
    os << tms.getCurrentState() << " "
    << tms.getCurrentContent() << " "
    << tms.getNextState() << " "
    << tms.getNextContent() << " "
    << tms.getMoveDirection();
    return os;
}

istream& operator>>(istream& is, TuringMachineState& tms) {
    is >> tms.current_state
    >> tms.current_content
    >> tms.next_state
    >> tms.next_content
    >> tms.move_direction;
    return is;
}

bool operator==( TuringMachineState& tms1,  TuringMachineState& tms2) {
    return tms1.getCurrentState() == tms2.getCurrentState() &&
    tms1.getCurrentContent() == tms2.getCurrentContent();
}

bool operator>( TuringMachineState& tms1,  TuringMachineState& tms2) {
    if (tms1.getCurrentState()>tms2.getCurrentState()) {
        return true;
    } else if (tms1.getCurrentState()==tms2.getCurrentState()) {
        if (tms1.getCurrentContent()>tms2.getCurrentContent()) {
            return true;
        }
    }
    return false;
}

bool operator<( TuringMachineState& tms1,  TuringMachineState& tms2) {
    if (tms1.getCurrentState()<tms2.getCurrentState()) {
        return true;
    } else if (tms1.getCurrentState()==tms2.getCurrentState()) {
        if (tms1.getCurrentContent()<tms2.getCurrentContent()) {
            return true;
        }
    }
    return false;
}




