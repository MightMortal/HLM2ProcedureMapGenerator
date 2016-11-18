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
    bool testA = ((a.first.x >= b.first.x && a.first.x <= b.second.x) || (a.second.x >= b.first.x && a.second.x <= b.second.x))
        && a.first.y == b.first.y && a.second.y == b.second.y;
    bool testB = ((a.first.y >= b.first.y && a.first.y <= b.second.y) || (a.second.y >= b.first.y && a.second.y <= b.second.y))
        && a.first.x == b.first.x && a.second.x == b.second.x;
    return testA || testB;
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

Rectangle getBoundingBox(Rectangle rect, double angle) {
    double angleRadian = angle * M_PI / 180.0;
    int midX = rect.first.x + (rect.second.x - rect.first.x) / 2;
    int midY = rect.first.y + (rect.second.y - rect.first.y) / 2;
    Point p0 = Point(rect.first.x - midX, rect.first.y - midY);
    Point p1 = Point(rect.second.x - midX, rect.first.y - midY);
    Point p2 = Point(rect.second.x - midX, rect.second.y - midY);
    Point p3 = Point(rect.first.x - midX, rect.second.y - midY);
    p0 = Point((int) (p0.x * cos(angleRadian) + p0.y * sin(angleRadian)),
               (int) (-p0.x * sin(angleRadian) + p0.y * cos(angleRadian)));
    p1 = Point((int) (p1.x * cos(angleRadian) + p1.y * sin(angleRadian)),
               (int) (-p1.x * sin(angleRadian) + p1.y * cos(angleRadian)));
    p2 = Point((int) (p2.x * cos(angleRadian) + p2.y * sin(angleRadian)),
               (int) (-p2.x * sin(angleRadian) + p2.y * cos(angleRadian)));
    p3 = Point((int) (p3.x * cos(angleRadian) + p3.y * sin(angleRadian)),
               (int) (-p3.x * sin(angleRadian) + p3.y * cos(angleRadian)));
    Rectangle result(Point(min(min(p0.x, p1.x), min(p2.x, p3.x)) + midX, min(min(p0.y, p1.y), min(p2.y, p3.y)) + midY),
                     Point(max(max(p0.x, p1.x), max(p2.x, p3.x)) + midX, max(max(p0.y, p1.y), max(p2.y, p3.y)) + midY));
    return result;
}
