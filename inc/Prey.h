//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_PREY_H
#define ECOSIM_PREY_H


#include "Animal.h"

class Prey : public Animal {
private:
    vector<vector<int>> possibleMoves;

public:

    Prey();
    Prey(int xCoord, int yCoord);
    ~Prey();

    void move() override;

};


#endif //ECOSIM_PREY_H
