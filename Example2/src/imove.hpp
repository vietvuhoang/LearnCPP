#ifndef _IMOVE_HPP_
#define _IMOVE_HPP_

#include <iostream>

class IMove {
public:
    virtual void move() = 0;
};

class MoveUp : public IMove {
public:
    void move() {
        std::cout << "Move UP" << std::endl;
    }
};

inline IMove* createMover() {
    return new MoveUp();
}

#endif 
