//
// Created by Kaitlyn Archambault on 2023-03-30.
//

#include "Point.h"


Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) { }

bool operator==(const Point& a, const Point&b) {

    return ((a.x == b.x) && (a.y == b.y));
}
