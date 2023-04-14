//
// Created by Kaitlyn Archambault on 2023-03-30.
//

#ifndef ECOSIM_POINT_H
#define ECOSIM_POINT_H

#include <vector>

struct Point {
public:
    int x;
    int y;
    Point();
    Point(int x, int y);
    friend bool operator ==(const Point& a, const Point& b);
};

typedef std::vector<Point> PointVector;

#endif //ECOSIM_POINT_H
