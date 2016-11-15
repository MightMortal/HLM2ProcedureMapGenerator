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
    rect.first.x = alignValue(rect.first.x, WALL_ALIGN_FACTOR);
    rect.first.y = alignValue(rect.first.y, WALL_ALIGN_FACTOR);
    rect.second.x = alignValue(rect.second.x, WALL_ALIGN_FACTOR);
    rect.second.y = alignValue(rect.second.y, WALL_ALIGN_FACTOR);
    this->rect = rect;
    rooms = bsp(rect, minRoomArea, minRoomAreaMultiplyFactor, 1.0, maxTreeDepth);
    sort(rooms->begin(), rooms->end(), [](Room a, Room b) {
        return a.rect.area() > b.rect.area();
    });

    for (auto room = rooms->begin(); room != rooms->end(); ++room) {
        if (room->type == Room::CORRIDOR)
            continue;
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
            if (it->first.y == rect.first.y || it->first.y == rect.second.y)
                continue;
            for (int x = it->first.x; x <= it->second.x - WALL_ALIGN_FACTOR / 2; x += WALL_ALIGN_FACTOR) {
                EditorWall editorWall;
                editorWall.magic = 0;
                editorWall.attribute = 99;
                editorWall.id = 32;
                editorWall.x = x;
                editorWall.y = it->first.y;
                editorWalls.push_back(editorWall);
            }
        } else { // Vertical
            if (it->first.x == rect.first.x || it->first.x == rect.second.x)
                continue;
            for (int y = it->first.y; y <= it->second.y - WALL_ALIGN_FACTOR / 2; y += WALL_ALIGN_FACTOR) {
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
    for (int x = rect.first.x; x < rect.second.x; x += WALL_ALIGN_FACTOR) {
        EditorWall editorWall;
        editorWall.magic = 0;
        editorWall.attribute = 99;
        editorWall.id = 32;
        editorWall.x = x;
        editorWall.y = rect.first.y;
        editorWalls.push_back(editorWall);
        editorWall.x = x;
        editorWall.y = rect.second.y;
        editorWalls.push_back(editorWall);
    }
    for (int y = rect.first.y; y < rect.second.y; y += WALL_ALIGN_FACTOR) {
        EditorWall editorWall;
        editorWall.magic = 0;
        editorWall.attribute = 100;
        editorWall.id = 31;
        editorWall.x = rect.first.x;
        editorWall.y = y;
        editorWalls.push_back(editorWall);
        editorWall.x = rect.second.x;
        editorWall.y = y;
        editorWalls.push_back(editorWall);
    }
    return WallMap(editorWalls);
}

TileMap Building::generateTileMap() {
    vector<EditorTile> editorTiles;
    for (auto room = rooms->begin(); room != rooms->end(); ++room) {
        RoomFloor floor = room->floor;
        for (int x = room->rect.first.x; x < room->rect.second.x; x += TILE_ALIGN_FACTOR) {
            for (int y = room->rect.first.y; y < room->rect.second.y; y += TILE_ALIGN_FACTOR) {
                EditorTile tile;
                tile.id = floor.type;
                tile.x = x;
                tile.y = y;
                tile.textureX = floor.tx;
                tile.textureY = floor.ty;
                tile.attribute = floor.attribute;
                editorTiles.push_back(tile);
            }
        }
    }
    TileMap tileMap;
    tileMap.tiles = editorTiles;
    return tileMap;
}