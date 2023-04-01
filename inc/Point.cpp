//
// Created by Kaitlyn Archambault on 2023-03-30.
//

#include "Point.h"


Point::Point() { }

Point::Point(int x, int y) : x(x), y(y) { }

int Point::getX() {
    return x;
}

void Point::setX(int x) {
    this->x = x;
}

int Point::getY() {
    return y;
}

void Point::setY(int y) {
    this->y = y;
}

bool operator==(const Point& a, const Point&b) {

    return ((a.x == b.x) && (a.y == b.y));
}
