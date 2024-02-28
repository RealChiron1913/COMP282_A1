#ifndef TURINGMACHINESTATE_H_
#define TURINGMACHINESTATE_H_

#include <string>

using namespace std;

class TuringMachineState {

public:
    TuringMachineState(int current_state, int current_content, int next_state, int next_content, const string& move_direction);
    int getCurrentState();
    int getCurrentContent();
    int getNextState();
    int getNextContent();
    string getMoveDirection();

    int current_state;
    int current_content;
    int next_state;
    int next_content;
    string move_direction;

    friend ostream& operator<<(ostream& os, TuringMachineState& tms);
    friend istream& operator>>(istream& is, TuringMachineState& tms);
    friend bool operator==( TuringMachineState& tms1,  TuringMachineState& tms2);
    friend bool operator>( TuringMachineState& tms1,  TuringMachineState& tms2);
    friend bool operator<( TuringMachineState& tms1,  TuringMachineState& tms2);

};

#endif
