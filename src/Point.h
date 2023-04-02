//
// Created by Kaitlyn Archambault on 2023-03-30.
//

#ifndef ECOSIM_POINT_H
#define ECOSIM_POINT_H

#include <vector>

//TODO is this a class or a struct?
class Point {
private:
    int x;
    int y;

public:
    Point();
    Point(int x, int y);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    friend bool operator ==(const Point& a, const Point& b);
};

typedef std::vector<Point> PointVector; //or PointList?

#endif //ECOSIM_POINT_H
