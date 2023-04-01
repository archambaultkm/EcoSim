//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Predator.h"

//--------------------------------Constructors--------------------------------//

Predator::Predator(Point point, World* worldptr) : Organism(point, worldptr, symbol),
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

void Predator::setPossibleMoves() {

    //TODO let them move diagonally too
    PointVector possibleMoves;

    possibleMoves.push_back(*new Point(location.getX()-1, location.getY()));
    possibleMoves.push_back(*new Point(location.getX()+1, location.getY()));
    possibleMoves.push_back(*new Point(location.getX(), location.getY()-1));
    possibleMoves.push_back(*new Point(location.getX(), location.getY()+1));

    this->possibleMoves = possibleMoves;
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