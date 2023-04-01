//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_PREY_H
#define ECOSIM_PREY_H

#include "Organism.h"

#define PREY_MOVE_POINTS 4

class Prey : public Organism {
private:
    static const char symbol = 'h';

public:

    //-------------------Constructors-------------------//
    Prey(Point point, World* worldptr);
    virtual ~Prey();

    //-------------------Getters/Setters-------------------//
    void setPossibleMoves() override;

    //-------------------Member Functions-------------------//
    void turn() override;
    void move() override;
    void recruit();
};

#endif //ECOSIM_PREY_H
