//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "Building.h"

#include <algorithm>

#include "../bsp/BSP.h"

const int minRoomArea = 50000;
const int maxTreeDepth = 5;
const double minRoomAreaMultiplyFactor = 2 / 3;

Building::Building(Rectangle rect) {
    rooms = bsp(rect, minRoomArea, minRoomAreaMultiplyFactor, 1.0, maxTreeDepth);
    sort(rooms->begin(), rooms->end(), [](Room a, Room b) {
        return a.rect.area() > b.rect.area();
    });

    for (auto room = rooms->begin(); room != rooms->end(); ++room) {
        vector<Line> roomWalls = room->rect.getWalls();
        for (auto roomWall = roomWalls.begin(); roomWall != roomWalls.end(); ++roomWall) {
            vector<Line> newWalls;
            bool isProcessed = false;
            for (auto levelWall = walls.begin(); levelWall != walls.end(); ++levelWall) {
                if (isLineFullyOverlapped(*roomWall, *levelWall)) {
                    isProcessed = true;
                    break;
                }
                if (isLineFullyOverlapped(*levelWall, *roomWall)) {
                    levelWall = walls.erase(levelWall);
                    newWalls.push_back(*roomWall);
                    isProcessed = true;
                    break;
                }
                if (isLinePartiallyOverlapped(*levelWall, *roomWall)) {
                    newWalls.push_back(combineLines(*levelWall, *roomWall));
                    break;
                }
            }
            if (!isProcessed) {
                newWalls.push_back(*roomWall);
            }
            walls.insert(walls.end(), newWalls.begin(), newWalls.end());
        }
    }
}

Building::~Building() {
    delete rooms;
}