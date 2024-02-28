#ifndef TURINGMACHINESTATE_H_
#define TURINGMACHINESTATE_H_

#include <string>

using namespace std;

class TuringMachineState {

public:
    TuringMachineState(int current_state, int current_content, int next_state, int next_content, string move_direction);
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

    void setCurrentState(int x);
    void setCurrentContent(int x);
    void setNextState(int x);
    void setNextContent(int x);

    bool operator==(const TuringMachineState &rhs) const;


    friend ostream& operator<<(ostream& os, TuringMachineState& tms);
    friend istream& operator>>(istream& is, TuringMachineState& tms);

    bool operator<(const TuringMachineState &rhs) const;

    bool operator>(const TuringMachineState &rhs) const;


};

#endif
