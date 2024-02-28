
#include "TuringTape.h"

TuringTape::TuringTape(int n) : n(n) {
    for (int i = 0; i < n; i++) {
        tape.push_back(0);
    }
    if (n == -1) {
        tape.push_back(0);
    }
}

bool TuringTape::moveRight() {
    position++;
    if (position > maxPosition) {
        maxPosition = position;
        if (n == -1) {
            tape.push_back(0);
        }
    }
    if (position < 0 || position > tape.size()) {
        return false;
    }
    return true;
}

bool TuringTape::moveLeft() {
    position--;
    if (position < 0 || position > tape.size()) {
        return false;
    }
    return true;
}

int TuringTape::getContent() {
    if (position < 0 || position > tape.size()) {
        return 0;
    }
    return tape[position];
}

void TuringTape::setContent(int c) {
    if (position < 0 || position > tape.size()) {
        return;
    }
    tape[position] = c;
}

int TuringTape::getPosition() {
    return position;
}

std::ostream &operator<<(std::ostream &out, const TuringTape &s) {
//    for (int i = 0; i < s.tape.size(); i++) {
//        out << s.tape[i];
//    }
//    return out;
    for (int i = 0; i <= s.maxPosition; i++) {
        out << s.tape[i];
    }
    return out;
}





