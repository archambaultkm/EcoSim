//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_PREDATOR_H
#define ECOSIM_PREDATOR_H

#include "Organism.h"

#define PREDATOR_MOVE_POINTS 8
#define TURNS_TO_STARVE 3

class Predator : public Organism {
private:
    int hunger;
    const static char symbol = 'z';

public:

    //-------------------Constructors-------------------//
    Predator(Point point, World* worldptr);
    virtual ~Predator();

    //-------------------Getters/Setters-------------------//
    int getHunger();
    void setHunger(int hunger);
    bool isStarving();
    void setPossibleMoves() override;
    //-------------------Member Functions-------------------//
    void turn() override;
    void move() override;
    void eat(Point point);
};


#endif //ECOSIM_PREDATOR_H
