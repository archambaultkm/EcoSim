//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Predator.h"

//--------------------------------Constructors--------------------------------//

Predator::Predator():Organism(),
hunger(0)
{}

Predator::Predator(Point point) : Organism(point, symbol),
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

void Predator::turn() {
    move();
    //if there's an adjacent human
    //eat
}

void Predator::move() {
    //pick a random spot out of the possibleMoves vector
}

void Predator::eat() {
    hunger = 0;
}

bool Predator::isStarving() {
    return hunger >= TURNS_TO_STARVE;
}