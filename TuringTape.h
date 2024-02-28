#ifndef TURINGTAPE_H_
#define TURINGTAPE_H_

#include <ostream>
#include <vector>

class TuringTape {
public:
    std::vector<int> tape;
    int n;
    int position = 0;
    int maxPosition = 0;
    TuringTape(int n);
    bool moveRight();
    bool moveLeft();
    int getContent();
    void setContent(int c);
    int getPosition();
    friend std::ostream& operator<<(std::ostream& out,const TuringTape& s);
};
#endif /* TURINGTAPE_H_ */