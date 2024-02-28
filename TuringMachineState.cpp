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
                                       string move_direction) : current_state(current_state), current_content(current_content), next_state(next_state), next_content(next_content), move_direction(move_direction) {}


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

bool TuringMachineState::operator==(const TuringMachineState &rhs) const {
    return current_state == rhs.current_state &&
           current_content == rhs.current_content;
}


bool TuringMachineState::operator<(const TuringMachineState &rhs) const {
    if (current_state < rhs.current_state)
        return true;
    if (rhs.current_state < current_state)
        return false;
    return current_content < rhs.current_content;
}

bool TuringMachineState::operator>(const TuringMachineState &rhs) const {
    return rhs < *this;
}

void TuringMachineState::setCurrentState(int x) {
    current_state = x;
}

void TuringMachineState::setCurrentContent(int x) {
    current_content = x;

}

void TuringMachineState::setNextState(int x) {
    next_state = x;

}

void TuringMachineState::setNextContent(int x) {
    next_content = x;

}