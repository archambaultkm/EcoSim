//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_PREY_H
#define ECOSIM_PREY_H


#include "Animal.h"

class Prey : public Animal {
private:

    static const char symbol = 'o';

public:

    Prey();
    Prey(Point point);
    ~Prey();

    char getSymbol() override;

    void move() override;
};


#endif //ECOSIM_PREY_H
