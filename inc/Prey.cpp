//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Prey.h"

//--------------------------------Constructors--------------------------------//

//Prey::Prey():Animal()
//{}

Prey::Prey(Point point) : Animal(point, symbol)
{}

Prey::~Prey() {}

//------------------------------Getters/Setters--------------------------------//

//------------------------------Class Methods--------------------------------//

void Prey::move() {
    //pick a random spot out of the possibleMoves vector
}

char Prey::getSymbol() {
    return symbol;
}