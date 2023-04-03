//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_PREY_H
#define ECOSIM_PREY_H

#include "Organism.h"

#define PREY_MOVE_POINTS 4
#define PREY_TURNS_TO_REPRODUCE 3

class Prey : public Organism {
private:
    static const char symbol = PREY_SYMBOL;

public:

    //-------------------Constructors-------------------//
    Prey(Point point, World* worldptr);
    virtual ~Prey();

    //-------------------Getters/Setters-------------------//
    void setPossibleMoves() override;

    //-------------------Member Functions-------------------//
    void turn() override;
    void move() override;
    void reproduce() override;

    friend ostream& operator<<(ostream &output, const Prey& prey);
};

#endif //ECOSIM_PREY_H
