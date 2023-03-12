//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Animal.h"

//--------------------------------Constructors--------------------------------//

Animal::Animal():
isAlive(true), xCoord(0), yCoord(0)
{}

Animal::Animal(int xCoord, int yCoord):
isAlive(true), xCoord(xCoord), yCoord(yCoord)
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

int Animal::getXCoord() {
    return xCoord;
}

void Animal::setXCoord(int xCoord) {
    this->xCoord = xCoord;
}

int Animal::getYCoord() {
    return yCoord;
}

void Animal::setYCoord(int yCoord) {
    this->yCoord = yCoord;
}