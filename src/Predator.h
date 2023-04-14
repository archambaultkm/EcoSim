//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_PREDATOR_H
#define ECOSIM_PREDATOR_H

#include "Organism.h"

#define PREDATOR_MOVE_POINTS 8
#define TURNS_TO_STARVE 3
#define PREDATOR_TURNS_TO_REPRODUCE 8

class Predator : public Organism {
private:
    const static char symbol = PREDATOR_SYMBOL;
    int hunger;

public:

    //-------------------Constructors-------------------//
    Predator(Point point, World* worldptr);
    virtual ~Predator();

    //-------------------Getters/Setters-------------------//
    void setPossibleMoves() override;
    //-------------------Class Methods-------------------//
    void turn() override;
    void move() override;
    void reproduce() override;
    void eat(Point point);
};


#endif //ECOSIM_PREDATOR_H
