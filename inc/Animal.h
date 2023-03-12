//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_ANIMAL_H
#define ECOSIM_ANIMAL_H


#include <vector>
using namespace std;

class Animal {
private:
    //static int id; might need this to keep track of how many animals but idk
    bool isAlive;
    int xCoord;
    int yCoord;

public:

    Animal();
    Animal(int xCoord, int yCoord);
    ~Animal();

//    int getID();
//    void setID(int id);

    bool getAliveStatus();
    void setAliveStatus(bool alive);

    int getXCoord();
    void setXCoord(int xCoord);

    int getYCoord();
    void setYCoord(int yCoord);

    virtual void move() = 0;
};


#endif //ECOSIM_ANIMAL_H
