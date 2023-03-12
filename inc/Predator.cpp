//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Predator.h"

//--------------------------------Constructors--------------------------------//

Predator::Predator():Animal(),
hunger(0)
{}

Predator::Predator(int xCoord, int yCoord) : Animal(xCoord, yCoord),
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

vector<vector<int>> Predator::getPossibleMoves() {
    return possibleMoves;
}

//this probably isn't how I want to do this, I'll need a method anyway to calculate it (but maybe not)
void Predator::setPossibleMoves(vector<vector<int>> possibleMoves) {
    this->possibleMoves = possibleMoves;
}

//------------------------------Class Methods--------------------------------//

void Predator::move() {
    //pick a random spot out of the possibleMoves vector
}