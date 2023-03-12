//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_PREDATOR_H
#define ECOSIM_PREDATOR_H


#include "Animal.h"

class Predator : public Animal {
private:
    int hunger;
    vector<vector<int>> possibleMoves;

public:

    Predator();
    Predator(int xCoord, int yCoord);
    ~Predator();

    int getHunger();
    void setHunger(int hunger);

    vector<vector<int>> getPossibleMoves();
    void setPossibleMoves(vector<vector<int>> possibleMoves);

    void move() override;

};


#endif //ECOSIM_PREDATOR_H
