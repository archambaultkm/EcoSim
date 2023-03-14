//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Predator.h"

//--------------------------------Constructors--------------------------------//

//Predator::Predator():Animal(),
//hunger(0)
//{}

Predator::Predator(Point point) : Animal(point, symbol),
hunger(0)
{}

Predator::~Predator() {}

//------------------------------Getters/Setters--------------------------------//

int Predator::getHunger() {
    return hunger;
}

void Predator::setHunger(int hunger) {
    this->hunger = hunger;
}

char Predator::getSymbol() {
    return symbol;
}

//------------------------------Class Methods--------------------------------//

void Predator::move() {
    //pick a random spot out of the possibleMoves vector
}