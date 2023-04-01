//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Organism.h"

//--------------------------------Constructors--------------------------------//

Organism::Organism():
isAlive(true), location(0,0)
{}

Organism::Organism(Point point, char symbol):
isAlive(true), location(point), symbol(symbol)
{}

Organism::~Organism(){
    //could maybe echo "animal [ID] has died" idk
}

//------------------------------Getters/Setters--------------------------------//
bool Organism::getAliveStatus() {
    return isAlive;
}

void Organism::setAliveStatus(bool alive) {
    this->isAlive = alive;
}

Point Organism::getLocation() {
    return location;
}

void Organism::setLocation(Point point) {
    this->location = point;
}

PointVector Organism::getPossibleMoves() {
    return possibleMoves;
}

//this probably isn't how I want to do this, I'll need a method anyway to calculate it (but maybe not)
void Organism::setPossibleMoves(PointVector possibleMoves) {
    this->possibleMoves = possibleMoves;
}