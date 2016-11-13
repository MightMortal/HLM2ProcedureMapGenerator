//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "Building.h"

#include <algorithm>

#include "../bsp/BSP.h"

const int minRoomArea = 15000;
const int maxTreeDepth = 9;
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

WallMap Building::generateWallMap() {
    vector<EditorWall> editorWalls;
    for (auto it = walls.begin(); it != walls.end(); ++it) {
        if (it->first.x != it->second.x) { // Horizontal
            for (int x = it->first.x; x < it->second.x - 16; x += 32) {
                EditorWall editorWall;
                editorWall.magic = 0;
                editorWall.attribute = 99;
                editorWall.id = 32;
                editorWall.x = x;
                editorWall.y = it->first.y;
                editorWalls.push_back(editorWall);
            }
        } else { // Vertical
            for (int y = it->first.y; y < it->second.y - 16; y += 32) {
                EditorWall editorWall;
                editorWall.magic = 0;
                editorWall.attribute = 100;
                editorWall.id = 31;
                editorWall.x = it->first.x;
                editorWall.y = y;
                editorWalls.push_back(editorWall);
            }
        }
    }
    return WallMap(editorWalls);
}