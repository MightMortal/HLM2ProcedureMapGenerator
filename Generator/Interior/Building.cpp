//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "Building.h"

#include <algorithm>

#include "../bsp/BSP.h"

const int minRoomArea = 20000;
const int maxTreeDepth = 9;
const double minRoomAreaMultiplyFactor = 2 / 3;
const double doorsThresholdFactor = 35; // In percents

Building::Building(Rectangle rect) {
    rect.first.x = alignValue(rect.first.x, WALL_ALIGN_FACTOR);
    rect.first.y = alignValue(rect.first.y, WALL_ALIGN_FACTOR);
    rect.second.x = alignValue(rect.second.x, WALL_ALIGN_FACTOR);
    rect.second.y = alignValue(rect.second.y, WALL_ALIGN_FACTOR);
    this->rect = rect;
    Room::generateCorridorFloor();
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
                // If met doorway, don't place wall segment
                bool skip = false;
                for (auto doorway = doorways.begin(); doorway != doorways.end(); ++doorway) {
                    if (doorway->first.x == x && doorway->first.y == it->first.y) {
                        skip = true;
                    }
                }
                if (skip)
                    continue;

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
                // If met doorway, don't place wall segment
                bool skip = false;
                for (auto doorway = doorways.begin(); doorway != doorways.end(); ++doorway) {
                    if (doorway->first.y == y && doorway->first.x == it->first.x) {
                        skip = true;
                    }
                }
                if (skip)
                    continue;

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
                tile.id = RoomFloor::floorTypeConfigurations[floor.type].id;
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

void Building::generateDoors() {
    for (auto room = rooms->begin(); room != rooms->end(); ++room) {
        // Do not handle corridors
        if (room->type == Room::CORRIDOR)
            continue;
        vector<Line> walls = room->rect.getWalls();
        for (auto roomWall = walls.begin(); roomWall != walls.end(); ++roomWall) {
            // Iterate over another rooms to check if room has common wall
            for (auto currentCorridor = rooms->begin(); currentCorridor != rooms->end(); ++currentCorridor) {
                // If checking the same room
                if (&(*room) == &(*currentCorridor))
                    continue;
                vector<Line> currentCorridorWalls = currentCorridor->rect.getWalls();
                for (auto currentCorridorWall = currentCorridorWalls.begin();
                     currentCorridorWall != currentCorridorWalls.end(); ++currentCorridorWall) {
                    // If room and corridor share common wall make a doorway
                    if (isLinePartiallyOverlapped(*roomWall, *currentCorridorWall)) {
                        // Place doorway in the middle of the wall
                        if (roomWall->first.x == roomWall->second.x) {
                            // Wall is vertical
                            int length = roomWall->second.y - roomWall->first.y;
                            int middlePoint = alignValue(roomWall->first.y + length / 2, DOORWAY_LENGTH);
                            middlePoint = clamp(middlePoint, roomWall->first.y, roomWall->second.y);
                            Point p0(roomWall->first.x, middlePoint);
                            Point p1(roomWall->first.x, middlePoint + DOORWAY_LENGTH);
                            doorways.push_back(Line(p0, p1));
                            room->connectedWithCorridor = true;

                        } else {
                            // Wall is horizontal
                            int length = roomWall->second.x - roomWall->first.x;
                            int middlePoint = alignValue(roomWall->first.x + length / 2, DOORWAY_LENGTH);
                            middlePoint = clamp(middlePoint, roomWall->first.x, roomWall->second.x);
                            Point p0(middlePoint, roomWall->first.y);
                            Point p1(middlePoint + DOORWAY_LENGTH, roomWall->first.y);
                            doorways.push_back(Line(p0, p1));
                            room->connectedWithCorridor = true;
                        }
                    }
                }
            }
        }
    }
    reduceNumberOfDoors();
    generateDoorObjects();
}

bool Building::checkConnectivity() {
    vector<bool> isConnected(rooms->size(), false);
    for (int roomIndex = 0; roomIndex < rooms->size(); roomIndex++) {
        if (isConnected[roomIndex])
            continue;
        Room room = rooms->at(roomIndex);
        // Do not handle corridors
        if (room.type == Room::CORRIDOR) {
            isConnected[roomIndex] = true;
            roomIndex = -1; // Restart main loop
            continue;
        }
        vector<Line> walls = room.rect.getWalls();
        for (auto roomWall = walls.begin(); roomWall != walls.end(); ++roomWall) {
            for (unsigned int currentRoomIndex = 0; currentRoomIndex < rooms->size(); currentRoomIndex++) {
                Room currentRoom = rooms->at(currentRoomIndex);
                vector<Line> currentRoomWalls = currentRoom.rect.getWalls();
                for (auto currentRoomWall = currentRoomWalls.begin(); currentRoomWall != currentRoomWalls.end();
                     ++currentRoomWall) {
                    if (isLinePartiallyOverlapped(*roomWall, *currentRoomWall) && isConnected[currentRoomIndex]) {
                        for (auto doorway = doorways.begin(); doorway != doorways.end(); ++doorway) {
                            if (isLineFullyOverlapped(*doorway, *roomWall)
                                && isLineFullyOverlapped(*doorway, *currentRoomWall)) {
                                isConnected[roomIndex] = true;
                                // Stop all internal loops
                                currentRoomIndex = rooms->size() - 1;
                                currentRoomWall = currentRoomWalls.end() - 1;
                                roomWall = walls.end() - 1;
                                roomIndex = -1; // Restart main loop
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    bool result = true;
    for (auto it = isConnected.begin(); it != isConnected.end(); ++it) {
        if (!(*it))
            result = false;
    }
    return result;
}

void Building::reduceNumberOfDoors() {
    int initialNumberOfDoors = doorways.size();
    int targetNumberOfDoors = (int) (initialNumberOfDoors * doorsThresholdFactor / 100.0);
    for (int i = 0; i < doorways.size() && doorways.size() > targetNumberOfDoors; i++) { // For testing only
        Line doorway = doorways[i];
        doorways.erase(doorways.begin() + i);
        if (!checkConnectivity()) {
            doorways.push_back(doorway);
        } else {
            i = -1; // Restart the loop
        }
    }
}

PlayMap Building::generatePlayMap() {
    PlayMap result;
    result.magic1 = 0;
    result.magic2 = -1;
    for (auto object = objects.begin(); object != objects.end(); ++object) {
        PlayObject playObject;
        playObject.id = object->configuration.id;
        playObject.x = object->x;
        playObject.y = object->y;
        playObject.spriteId = object->configuration.spriteId;
        playObject.angle = object->angle;
        playObject.magic = object->configuration.magic;
        result.objects.push_back(playObject);
    }
    return result;
}

ObjectMap Building::generateObjectMap() {
    ObjectMap result;
    for (auto object = objects.begin(); object != objects.end(); ++object) {
        EditorObject editorObject;
        editorObject.id = object->configuration.editorId;
        editorObject.x = object->x;
        editorObject.y = object->y;
        editorObject.spriteId = object->configuration.spriteId;
        editorObject.angle = object->angle;
        editorObject.behaviorId = object->configuration.behaviorId;
        editorObject.magic = object->configuration.magic;
        result.objects.push_back(editorObject);
    }
    return result;
}

void Building::generateDoorObjects() {
    for (auto door = doorways.begin(); door != doorways.end(); ++door) {
        DoorObject doorObject;
        doorObject.x = door->first.x;
        doorObject.y = door->first.y;
        doorObject.angle = 0;
        if (door->first.x == door->second.x) {
            // Wall is vertical
            doorObject.configuration = DoorObject::doorObjectConfigurations[DoorObject::objEditorDoorV];
        } else {
            // Wall is horizontal
            doorObject.configuration = DoorObject::doorObjectConfigurations[DoorObject::objEditorDoorH];
        }
        objects.push_back(doorObject);
    }
}

bool Building::isPlaceEmpty(int x, int y, int w, int h) {
    // AABB Collision checking
    // Read more: http://gdlinks.hut.ru/cdfaq/aabb.shtml
    int xCenter = x + w / 2;
    int yCenter = y + y / 2;
    for (auto object = objects.begin(); object != objects.end(); ++object) {
        int objectXCenter = object->x + object->configuration.width / 2;
        int objectYCenter = object->y + object->configuration.height / 2;
        int widthSum = w + object->configuration.width;
        int heightSum = h + object->configuration.height;
        if (abs(objectXCenter - xCenter) <= widthSum && abs(objectYCenter - yCenter) <= heightSum)
            return false;
    }
    return true;
}

void Building::placeWeapon() {
    for (auto weaponConfiguration = WeaponObject::weaponObjectConfigurations.begin();
         weaponConfiguration != WeaponObject::weaponObjectConfigurations.end(); ++weaponConfiguration) {
        if (rand() % 2) {
            // Place weapon with probability 50%
            int roomIndex = rand() % rooms->size();
            Room room = rooms->at(roomIndex);
            int weaponX = room.rect.first.x + (room.rect.second.x - room.rect.first.x) / 2;
            int weaponY = room.rect.first.y + (room.rect.second.y - room.rect.first.y) / 2;
            if (isPlaceEmpty(weaponX, weaponY, weaponConfiguration->width, weaponConfiguration->height)) {
                WeaponObject weaponObject;
                weaponObject.angle = 0;
                weaponObject.x = weaponX;
                weaponObject.y = weaponY;
                weaponObject.configuration = *weaponConfiguration;
                weaponObject.type = (WeaponObject::WEAPON_TYPE) (weaponConfiguration
                    - WeaponObject::weaponObjectConfigurations.begin());
                objects.push_back(weaponObject);
            }
        }
    }
}
