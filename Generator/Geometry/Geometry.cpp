//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "Geometry.h"

vector<Line> Rectangle::getWalls() {
    vector<Line> result;
    result.push_back(Line(Point(first.x, first.y), Point(second.x, first.y)));
    result.push_back(Line(Point(second.x, first.y), Point(second.x, second.y)));
    result.push_back(Line(Point(first.x, second.y), Point(second.x, second.y)));
    result.push_back(Line(Point(first.x, first.y), Point(first.x, second.y)));
    return result;
};

bool isLineFullyOverlapped(Line &a, Line &b) {
    bool aHorizontal = (a.first.x - a.second.x) != 0;
    bool bHorizontal = (b.first.x - b.second.x) != 0;
    if (aHorizontal != bHorizontal)
        return false;
    if (aHorizontal) {
        return a.first.x >= b.first.x && a.second.x <= b.second.x && a.first.y == b.first.y && a.second.y == b.second.y;
    } else {
        return a.first.y >= b.first.y && a.second.y <= b.second.y && a.first.x == b.first.x && a.second.x == b.second.x;
    }
}

bool isLinePartiallyOverlapped(Line &a, Line &b) {
    bool aHorizontal = (a.first.x - a.second.x) != 0;
    bool bHorizontal = (b.first.x - b.second.x) != 0;
    if (aHorizontal != bHorizontal)
        return false;
    if (aHorizontal) {
        return
            (a.first.x >= b.first.x && a.first.x <= b.second.x || a.second.x <= b.second.x && a.first.x >= b.second.x)
                && a.first.y == b.first.y && a.second.y == b.second.y;
    } else {
        return
            (a.first.y >= b.first.y && a.first.y <= b.second.y || a.second.y <= b.second.y && a.first.y >= b.second.y)
                && a.second.x == b.second.x;
    }
}

Line combineLines(Line a, Line b) {
    bool aHorizontal = (a.first.x - a.second.x) != 0;
    bool bHorizontal = (b.first.x - b.second.x) != 0;
    if (aHorizontal) {
        if (a.first.x < b.first.x)
            return Line(Point(a.first.x, a.first.y), Point(b.second.x, b.second.y));
        else
            return Line(Point(b.first.x, b.first.y), Point(a.second.x, a.second.y));
    } else {
        if (a.first.y < b.first.y)
            return Line(Point(a.first.x, a.first.y), Point(b.second.x, b.second.y));
        else
            return Line(Point(b.first.x, b.first.y), Point(a.second.x, a.second.y));
    }
}

int alignValue(int value, int step) {
    int valueAlignOffset = value % step;
    if (valueAlignOffset < step / 2)
        value -= valueAlignOffset;
    else
        value += step - valueAlignOffset;
    return value;
}
