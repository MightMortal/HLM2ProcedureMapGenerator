//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_POINT_H
#define HLM2PROCEDUREMAPGENERATOR_POINT_H

#include "../../common.h"

const double DOUBLE_ERROR = 0.0000001;

class Point {
public:
    Point(int x, int y) : x(x), y(y) {};

    int x;
    int y;
};

typedef pair<Point, Point> Line;

class Rectangle : public pair<Point, Point> {
public:
    int area() {
        return abs(this->first.x - this->second.x) * abs(this->first.y - this->second.y);
    }
    Rectangle(Point p1, Point p2) : pair(p1, p2) {}

    vector<Line> getWalls();
};

inline int clamp(int val, int min, int max) {
    return val < min ? min : (val > max ? max : val);
}

/**
 * Check is Line 'a' fully-overlapped by 'b'. Works only with vertical and horizontal lines
 * @param a - tested line
 * @param b - main line
 * @return 'true' if Line 'a' is fully-overlapped by 'b'
 */
bool isLineFullyOverlapped(Line &a, Line &b);

/**
 * Check is Line 'a' partially-overlapped by 'b'. Works only with vertical and horizontal lines
 * @param a - tested line
 * @param b - main line
 * @return 'true' if Line 'a' is partially-overlapped by 'b'
 */
bool isLinePartiallyOverlapped(Line &a, Line &b);

Line combineLines(Line a, Line b);

#endif //HLM2PROCEDUREMAPGENERATOR_POINT_H
