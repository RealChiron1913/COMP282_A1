#include <iostream>
#include <algorithm>
#include "MenuSystem.h"
#include "TuringMachine.h"
#include "DenseTuringMachine.h"
#include "TuringTape.h"


using namespace std;

int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void MenuSystem::menu() {
    string input;
    cout << "How long should the tape be?" << endl;
    cin >> tapeLength;
    if (tapeLength > 0) {
        tape = TuringTape(tapeLength);
    }

    while (true) {
        cout << "1. Create dense Turing machine" << endl;
        cout << "2. Create sparse Turing machine" << endl;
        cout << "3. Add state to Turing machine" << endl;
        cout << "4. Compact Turing machine" << endl;
        cout << "5. Execute Turing machine" << endl;
        cout << "6. Output current information" << endl;
        cout << "Write q or Q to quit" << endl;
        cout << "Enter Option" << endl;
        start:
        cin >> input;
        if (input == "q" || input == "Q") {
            return;
        }
        else if (input == "1") {
            cout << "What is the maximum state and what is the maximum content?" << endl;
            op1:
            cin >> maxState >> maxContent;
            if (maxState >= -1 && maxContent >= -1) {
                dtm = DenseTuringMachine(maxState, maxContent);
            }else{
                cout << "Enter Option" << endl;
                goto op1;
            }
            denseOrSparse = "dense";

        }
        else if (input == "2") {
            stm = SparseTuringMachine();
            denseOrSparse = "sparse";
        }

        else if (input == "3") {
            if (denseOrSparse.empty()) {
                cout << "Enter Option"<< endl;
                goto start;
            }
            int currentState, currentContent, nextState, nextContent;
            string moveDirection;
            cout << "What state do you wish to add?" << endl;
            cin >> currentState >> currentContent >> nextState >> nextContent >> moveDirection;
            TuringMachineState tms_new(currentState, currentContent, nextState, nextContent, moveDirection);
            tms.push_back(tms_new);
            if (denseOrSparse == "dense") {
                dtm.add(tms_new);
                tms = *dtm.getAll();
            }
            if (denseOrSparse == "sparse") {
                stm.add(tms_new);
                tms = *stm.getAll();
            }
        }

        else if (input == "4") {
            if (denseOrSparse.empty()) {
                cout << "Enter Option"<< endl;
                goto start;
            }
            vector<TuringMachineState> sortTms = tms;
            vector<int> order;
            vector<int> states;
            vector<int> contents;

            for (auto & sortTm : sortTms) {
                states.push_back(sortTm.getCurrentState());
                states.push_back(sortTm.getNextState());
            }

            sort(states.begin(), states.end());

            for (int k = 0; k < states.size(); k++) {
                if (k == 0){
                    order.push_back(0);
                }
                else if (states[k] > states[k-1]) {
                    order.push_back(order[k-1] + 1);
                }else {
                    order.push_back(order[k-1]);
                }
            }

            for (auto & sortTm : sortTms) {
                sortTm.setCurrentState(order[binarySearch(states, sortTm.getCurrentState())]);
                sortTm.setNextState(order[binarySearch(states, sortTm.getNextState())]);
            }
            maxState = order[order.size() - 1];
            states.clear();
            order.clear();

            for (auto & sortTm : sortTms) {
                contents.push_back(sortTm.getCurrentContent());
                contents.push_back(sortTm.getNextContent());
            }

            sort(contents.begin(), contents.end());

            for (int k = 0; k < contents.size(); k++) {
                if (k == 0){
                    order.push_back(0);
                }
                else if (contents[k] > contents[k-1]) {
                    order.push_back(order[k-1] + 1);
                }else {
                    order.push_back(order[k-1]);
                }
            }

            for (auto & sortTm : sortTms) {
                sortTm.setCurrentContent(order[binarySearch(contents, sortTm.getCurrentContent())]);
                sortTm.setNextContent(order[binarySearch(contents, sortTm.getNextContent())]);
            }
            maxContent = order[order.size() - 1];
            contents.clear();

            dtm = DenseTuringMachine(maxState, maxContent);
            for (TuringMachineState k: sortTms) {
                dtm.add(k);
            }
            tms = *dtm.getAll();
            denseOrSparse = "dense";
        }

        else if (input == "5") {
            if (denseOrSparse.empty()) {
                cout << "Enter Option"<< endl;
                goto start;
            }
            cout << "How many steps do you wish to execute?" << endl;
            int step_add;
            cin >> step_add;
            step_total = step_total + step_add;
            int i = step_total - step_add + 1;
            while (i <= step_total || step_add == -1) {
                if (denseOrSparse == "dense") {
                    if (dtm.find(state, tape.getContent()) == NULL) {
                        cout << "In step " << i << ", there is no Turing machine state with state " << state
                             << " and content " << tape.getContent() << endl;
                        break;
                    }
                    x= *dtm.find(state, tape.getContent());

                } else if (denseOrSparse == "sparse") {
                    if (stm.find(state, tape.getContent()) == NULL) {
                        cout << "In step " << i << ", there is no Turing machine state with state " << state
                             << " and content " << tape.getContent() << endl;
                        break;
                    }
                    x = *stm.find(state, tape.getContent());
                }
                if (tape.getPosition() < 0) {
                    cout << "In step " << i << ", the position is " << tape.getPosition()
                                               << ", but that is outside the tape." << endl;
                    break;
                }
                if (tape.getPosition() > tapeLength && tapeLength != -1) {
                    cout << "In step " << i << ", the position is " << tape.getPosition()
                                               << ", but that is outside the tape." << endl;
                    break;
                }

                tape.setContent(x.getNextContent());
                state = x.getNextState();
                if (x.getMoveDirection() == "->") {
                    tape.moveRight();
                }
                if (x.getMoveDirection() == "<-") {
                    tape.moveLeft();
                }
                i++;
            }
        }
        else if (input == "6") {
            cout << "The current state is " << state << "." << endl;
            cout << "The current position is " << tape.getPosition() << "." << endl;
            cout << "The content of the tape is " << tape << "." << endl;
            cout << "The Turing machine has states: ";
            for (auto s: tms) {
                cout << "<" << s << ">";
            }
            cout << endl;
        }
        else{
            cout << "Enter Option" << endl;
            goto start;
        }
    }

}