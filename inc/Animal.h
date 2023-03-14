//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_ANIMAL_H
#define ECOSIM_ANIMAL_H

#include <vector>
using namespace std;

struct Point {
private:
    int x;
    int y;
public:
    Point() {
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setX(int x) {
        this->x = x;
    }

    int getX() {
        return x;
    }

    void setY(int y) {
        this->y = y;
    }

    int getY() {
        return y;
    }
};

class Animal {
private:
    //static int id; might need this to keep track of how many animals but idk
    bool isAlive;
    Point location;
    vector<Point> possibleMoves;
    char symbol;

public:

    //Animal();
    Animal(Point point, char symbol);
    ~Animal();

    bool getAliveStatus();
    void setAliveStatus(bool alive);

    Point getLocation();
    void setLocation(Point newLocation);

    vector<Point> getPossibleMoves();
    void setPossibleMoves(vector<Point> possibleMoves);

    virtual char getSymbol() = 0;
    virtual void move() = 0;
};


#endif //ECOSIM_ANIMAL_H
