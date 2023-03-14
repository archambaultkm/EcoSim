//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_PREDATOR_H
#define ECOSIM_PREDATOR_H


#include "Animal.h"

class Predator : public Animal {
private:
    int hunger;
    static const char symbol = 'x';

public:

    //Predator();
    Predator(Point point);
    ~Predator();

    int getHunger();
    void setHunger(int hunger);

    char getSymbol() override;

    void move() override;

};


#endif //ECOSIM_PREDATOR_H
