//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "BSP.h"

const double CONTINUITY_PROBABILITY_DECREASE_FACTOR = 0.1;

int alignValue(int value, int step) {
    int valueAlignOffset = value % step;
    if (valueAlignOffset < step / 2)
        value -= valueAlignOffset;
    else
        value += step - valueAlignOffset;
    return value;
}

vector<Room> *bsp(Rectangle rect,
                  int minRoomArea,
                  double minRoomAreaMultiplyFactor,
                  double continuityProbability,
                  int maxTreeDepth) {
    vector<Room> *result = new vector<Room>;
    if (maxTreeDepth <= 0 || rand() / RAND_MAX > continuityProbability) {
        result->push_back(Room(rect, Room::DEFAULT));
        return result;
    }

    if (rand() % 2) {
        // Horizontal
        int height = abs(rect.first.y - rect.second.y);
        int divisionLine = rand() % height;

        int minDivisionLine = (int) (sqrt(minRoomArea) - minRoomAreaMultiplyFactor * sqrt(minRoomArea));
        int minDivisionLineAlignOffset = minDivisionLine % WALL_ALIGN_FACTOR;
        minDivisionLine += WALL_ALIGN_FACTOR - minDivisionLineAlignOffset;

        int maxDivisionLine = height - minDivisionLine;
        if (maxDivisionLine < minDivisionLine) {
            result->push_back(Room(rect, Room::DEFAULT));
            return result;
        }

        divisionLine = alignValue(divisionLine, WALL_ALIGN_FACTOR);
        divisionLine = clamp(divisionLine, minDivisionLine, maxDivisionLine);

        Rectangle rectTop(rect.first, Point(rect.second.x, divisionLine + rect.first.y));
        Rectangle rectBottom(Point(rect.first.x, divisionLine + rect.first.y), rect.second);
        if (rectTop.area() < minRoomArea || rectBottom.area() < minRoomArea) {
            result->push_back(Room(rect, Room::DEFAULT));
            return result;
        }

        double continuityProbabilityTop =
            continuityProbability
                * (1.0 - ((rand() / RAND_MAX) * CONTINUITY_PROBABILITY_DECREASE_FACTOR * continuityProbability));
        vector<Room>
            *resultTop =
            bsp(rectTop, minRoomArea, minRoomAreaMultiplyFactor, continuityProbabilityTop, maxTreeDepth - 1);
        result->insert(result->end(), resultTop->begin(), resultTop->end());
        delete resultTop;

        double continuityProbabilityBottom =
            continuityProbability
                * (1.0 - ((rand() / RAND_MAX) * CONTINUITY_PROBABILITY_DECREASE_FACTOR * continuityProbability));
        vector<Room> *resultBottom =
            bsp(rectBottom, minRoomArea, minRoomAreaMultiplyFactor, continuityProbabilityBottom, maxTreeDepth - 1);
        result->insert(result->end(), resultBottom->begin(), resultBottom->end());
        delete resultBottom;
    } else {
        // Vertical
        int width = abs(rect.first.x - rect.second.x);
        int divisionLine = rand() % width;

        int minDivisionLine = (int) (sqrt(minRoomArea) - minRoomAreaMultiplyFactor * sqrt(minRoomArea));
        int minDivisionLineAlignOffset = minDivisionLine % WALL_ALIGN_FACTOR;
        minDivisionLine += WALL_ALIGN_FACTOR - minDivisionLineAlignOffset;

        int maxDivisionLine = width - minDivisionLine;
        if (maxDivisionLine < minDivisionLine) {
            result->push_back(Room(rect, Room::DEFAULT));
            return result;
        }

        divisionLine = alignValue(divisionLine, WALL_ALIGN_FACTOR);
        divisionLine = clamp(divisionLine, minDivisionLine, maxDivisionLine);

        Rectangle rectLeft(rect.first, Point(divisionLine + rect.first.x, rect.second.y));
        Rectangle rectRight(Point(divisionLine + rect.first.x, rect.first.y), rect.second);
        if (rectLeft.area() < minRoomArea || rectRight.area() < minRoomArea) {
            result->push_back(Room(rect, Room::DEFAULT));
            return result;
        }

        double continuityProbabilityLeft =
            continuityProbability
                * (1.0 - ((rand() / RAND_MAX) * CONTINUITY_PROBABILITY_DECREASE_FACTOR * continuityProbability));
        vector<Room> *resultLeft =
            bsp(rectLeft, minRoomArea, minRoomAreaMultiplyFactor, continuityProbabilityLeft, maxTreeDepth - 1);
        result->insert(result->end(), resultLeft->begin(), resultLeft->end());
        delete resultLeft;

        double continuityProbabilityRight =
            continuityProbability
                * (1.0 - ((rand() / RAND_MAX) * CONTINUITY_PROBABILITY_DECREASE_FACTOR * continuityProbability));
        vector<Room> *resultRight =
            bsp(rectRight, minRoomArea, minRoomAreaMultiplyFactor, continuityProbabilityRight, maxTreeDepth - 1);
        result->insert(result->end(), resultRight->begin(), resultRight->end());
        delete resultRight;
    }
    return result;
}