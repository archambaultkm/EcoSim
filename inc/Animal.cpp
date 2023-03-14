//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Animal.h"

//--------------------------------Constructors--------------------------------//
//
//Animal::Animal():
//isAlive(true), location(0,0)
//{}

Animal::Animal(Point point, char symbol):
isAlive(true), location(point), symbol(symbol)
{}

Animal::~Animal(){
    //could maybe echo "animal [ID] has died" idk
}

//------------------------------Getters/Setters--------------------------------//

bool Animal::getAliveStatus() {
    return isAlive;
}

void Animal::setAliveStatus(bool alive) {
    this->isAlive = alive;
}

Point Animal::getLocation() {
    return location;
}

void Animal::setLocation(Point point) {
    this->location = point;
}

vector<Point> Animal::getPossibleMoves() {
    return possibleMoves;
}

//this probably isn't how I want to do this, I'll need a method anyway to calculate it (but maybe not)
void Animal::setPossibleMoves(vector<Point> possibleMoves) {
    this->possibleMoves = possibleMoves;
}