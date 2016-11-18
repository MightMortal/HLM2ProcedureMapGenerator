//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "Building.h"

#include <algorithm>

#include "../bsp/BSP.h"

const int minRoomArea = 12000;
const int maxTreeDepth = 9;
const double minRoomAreaMultiplyFactor = 2 / 3;
const double doorsThresholdFactor = 35; // In percents
const int enemyPlacingFactor = 96;
const int wallWidth = 8;
const double stopPlacingFurnitureProbability = 0.7;
const int maxNumberOfBundlesInRoom = 2;
const int numberOfAttemps = 5;

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
                WallAssetConfiguration configuration = WallObject::horizontalWalls[WallObject::BRICK_WALL];
                bool skip = false;
                for (auto doorway = doorways.begin(); doorway != doorways.end(); ++doorway) {
                    if (doorway->first.x == x && doorway->first.y == it->first.y) {
                        skip = true;
                    }
                }
                if (skip)
                    continue;

                for (auto windowLine = windows.begin(); windowLine != windows.end(); ++windowLine) {
                    if (windowLine->first.x == x && windowLine->first.y == it->first.y) {
                        configuration = WallObject::horizontalWalls[WallObject::WOOD_WINDOW];
                        break;
                    }
                }
                placeWallIntoVector(editorWalls, x, it->first.y, configuration);
            }
        } else { // Vertical
            if (it->first.x == rect.first.x || it->first.x == rect.second.x)
                continue;
            for (int y = it->first.y; y <= it->second.y - WALL_ALIGN_FACTOR / 2; y += WALL_ALIGN_FACTOR) {
                // If met doorway, don't place wall segment
                WallAssetConfiguration configuration = WallObject::verticalWalls[WallObject::BRICK_WALL];
                bool skip = false;
                for (auto doorway = doorways.begin(); doorway != doorways.end(); ++doorway) {
                    if (doorway->first.y == y && doorway->first.x == it->first.x) {
                        skip = true;
                    }
                }
                if (skip)
                    continue;

                for (auto windowLine = windows.begin(); windowLine != windows.end(); ++windowLine) {
                    if (windowLine->first.y == y && windowLine->first.x == it->first.x) {
                        configuration = WallObject::verticalWalls[WallObject::WOOD_WINDOW];
                        break;
                    }
                }
                placeWallIntoVector(editorWalls, it->first.x, y, configuration);
            }
        }
    }

    for (int x = rect.first.x; x < rect.second.x; x += WALL_ALIGN_FACTOR) {
        WallAssetConfiguration configuration = WallObject::horizontalWalls[WallObject::BRICK_WALL];
        for (auto windowLine = windows.begin(); windowLine != windows.end(); ++windowLine) {
            if (windowLine->first.y != windowLine->second.y) {
                if (windowLine->first.x == x && windowLine->first.y == rect.first.y) {
                    configuration = WallObject::horizontalWalls[WallObject::WOOD_WINDOW];
                    break;
                }
            }
        }
        placeWallIntoVector(editorWalls, x, rect.first.y, configuration);
        configuration = WallObject::horizontalWalls[WallObject::BRICK_WALL];
        for (auto windowLine = windows.begin(); windowLine != windows.end(); ++windowLine) {
            if (windowLine->first.y != windowLine->second.y) {
                if (windowLine->first.x == x && windowLine->first.y == rect.second.y) {
                    configuration = WallObject::horizontalWalls[WallObject::WOOD_WINDOW];
                    break;
                }
            }
        }
        placeWallIntoVector(editorWalls, x, rect.second.y, configuration);
    }
    for (int y = rect.first.y; y < rect.second.y; y += WALL_ALIGN_FACTOR) {
        WallAssetConfiguration configuration = WallObject::verticalWalls[WallObject::BRICK_WALL];
        for (auto windowLine = windows.begin(); windowLine != windows.end(); ++windowLine) {
            if (windowLine->first.y == windowLine->second.y) {
                if (windowLine->first.y == y && windowLine->first.x == rect.first.x) {
                    configuration = WallObject::verticalWalls[WallObject::WOOD_WINDOW];
                    break;
                }
            }
        }
        placeWallIntoVector(editorWalls, rect.first.x, y, configuration);
        configuration = WallObject::verticalWalls[WallObject::BRICK_WALL];
        for (auto windowLine = windows.begin(); windowLine != windows.end(); ++windowLine) {
            if (windowLine->first.y == windowLine->second.y) {
                if (windowLine->first.y == y && windowLine->first.x == rect.second.x) {
                    configuration = WallObject::verticalWalls[WallObject::WOOD_WINDOW];
                    break;
                }
            }
        }
        placeWallIntoVector(editorWalls, rect.second.x, y, configuration);
    }
    return WallMap(editorWalls);
}

void Building::placeWallIntoVector(vector<EditorWall> &editorWalls,
                                   int x,
                                   int y,
                                   WallAssetConfiguration configuration) {
    EditorWall editorWall;
    editorWall.magic = configuration.magic;
    editorWall.attribute = configuration.attribute;
    editorWall.id = configuration.id;
    editorWall.x = x;
    editorWall.y = y;
    editorWalls.push_back(editorWall);
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

bool Building::isPlaceEmpty(int x, int y, int w, int h, double angle) {
    // AABB Collision checking
    // Read more: http://gdlinks.hut.ru/cdfaq/aabb.shtml
    Rectangle rectangle(Point(x - w / 2, y - h / 2), Point(x + w / 2, y + h / 2));
    Rectangle boundingBox = getBoundingBox(rectangle, angle);
    int width = boundingBox.second.x - boundingBox.first.x;
    int height = boundingBox.second.y - boundingBox.first.y;
    int midX = boundingBox.first.x + width / 2;
    int midY = boundingBox.first.y + height / 2;

    for (auto object = objects.begin(); object != objects.end(); ++object) {
        Rectangle objectRectangle
            (Point(object->x - object->configuration.width / 2, object->y - object->configuration.height / 2),
             Point(object->x + object->configuration.width / 2, object->y + object->configuration.height / 2));
        Rectangle objectBoundingBox = getBoundingBox(objectRectangle, object->angle);
        int objectWidth = objectBoundingBox.second.x - objectBoundingBox.first.x;
        int objectHeight = objectBoundingBox.second.y - objectBoundingBox.first.y;
        int objectMidX = objectBoundingBox.first.x + objectWidth / 2;
        int objectMidY = objectBoundingBox.first.y + objectHeight / 2;

        int widthSum = (width + objectWidth) / 2;
        int heightSum = (height + objectHeight) / 2;
        if (abs(objectMidX - midX) <= widthSum && abs(objectMidY - midY) <= heightSum)
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

void Building::placeEnemy() {
    auto configurationPair = EnemyObject::enemyObjectConfigurations.begin();
    for (auto room = rooms->begin(); room != rooms->end(); ++room) {
        int numberOfEnemies = (int) (sqrt(room->rect.area()) / enemyPlacingFactor);
        for (int i = numberOfEnemies; i > 0; i--) {
            int roomWidth = room->rect.second.x - room->rect.first.x;
            int roomHeight = room->rect.second.y - room->rect.first.y;
            int x = rand() % roomWidth;
            int y = rand() % roomHeight;
            x = clamp(x, EnemyObject::ENEMY_SIZE, roomWidth - EnemyObject::ENEMY_SIZE);
            y = clamp(y, EnemyObject::ENEMY_SIZE, roomHeight - EnemyObject::ENEMY_SIZE);
            EnemyObject enemyObject;
            enemyObject.x = x + room->rect.first.x;
            enemyObject.y = y + room->rect.first.y;
            // Check is the place for the enemy is empty
            if (!isPlaceEmpty(enemyObject.x, enemyObject.y, EnemyObject::ENEMY_SIZE, EnemyObject::ENEMY_SIZE))
                continue;

            enemyObject.angle = 0;
            for (;; ++configurationPair) {
                if (configurationPair == EnemyObject::enemyObjectConfigurations.end())
                    configurationPair = EnemyObject::enemyObjectConfigurations.begin();
                double p = rand() * 1.0 / RAND_MAX;
                if (p < configurationPair->first) {
                    enemyObject.configuration = configurationPair->second.at(rand() % configurationPair->second.size());
                    // Stop loop over configurationPairs
                    break;
                }
            }
            objects.push_back(enemyObject);
        }
    }
}

void Building::generateWindows() {
    for (auto room = rooms->begin(); room != rooms->end(); ++room) {
        // Don't handle corridors
        if (room->type == Room::CORRIDOR)
            continue;
        vector<Line> walls = room->rect.getWalls();
        for (auto roomWall = walls.begin(); roomWall != walls.end(); ++roomWall) {
            if ((rand() * 1.0 / RAND_MAX) <= WINDOW_APPEAR_PROBABILITY) {
                // Pick number of windows to place
                int windowNumber = rand() % MAX_WINDOW_IN_PLACE + 1;

                if (roomWall->first.x == roomWall->second.x) {
                    // Wall is vertical
                    int currentWallLength = roomWall->second.y - roomWall->first.y;
                    if (currentWallLength == 0)
                        continue;
                    int startPoint = rand() % currentWallLength + roomWall->first.y;
                    startPoint = alignValue(startPoint, WINDOW_LENGTH);
                    startPoint = clamp(startPoint, roomWall->first.y, roomWall->second.y);

                    for (int i = 0; i < windowNumber; ++i) {
                        Point p0(roomWall->first.x, startPoint);
                        Point p1(roomWall->first.x, startPoint + WINDOW_LENGTH);
                        Line window(p0, p1);
                        if (isWallFree(window) && window.second.y < roomWall->second.y) {
                            windows.push_back(window);
                        }
                        startPoint += WINDOW_LENGTH;
                    }

                } else {
                    // Wall is horizontal
                    int currentWallLength = roomWall->second.x - roomWall->first.x;
                    if (currentWallLength == 0)
                        continue;
                    int startPoint = rand() % currentWallLength + roomWall->first.x;
                    startPoint = alignValue(startPoint, WINDOW_LENGTH);
                    startPoint = clamp(startPoint, roomWall->first.x, roomWall->second.x);

                    for (int i = 0; i < windowNumber; ++i) {
                        Point p0(startPoint, roomWall->first.y);
                        Point p1(startPoint + WINDOW_LENGTH, roomWall->first.y);
                        Line window(p0, p1);
                        if (isWallFree(window) && window.second.x < roomWall->second.x) {
                            windows.push_back(window);
                        }
                        startPoint += WINDOW_LENGTH;
                    }
                }
            }
        }
    }
}

bool Building::isWallFree(Line line) {
    for (auto doorway = doorways.begin(); doorway != doorways.end(); ++doorway) {
        if (isLinePartiallyOverlapped(*doorway, line)) {
            return false;
        }
    }
    for (auto window = windows.begin(); window != windows.end(); ++window) {
        if (isLinePartiallyOverlapped(*window, line)) {
            return false;
        }
    }
    return true;
}

void Building::generateFurniture() {
    for (auto room = rooms->begin(); room != rooms->end(); ++room) {
        if (room->type == Room::CORRIDOR)
            continue;
        int area = room->rect.area();
        int bundlesLeft = maxNumberOfBundlesInRoom;
        // Place furniture until there are free space in room
        while (area > FurnitureBundleConfiguration::bundleSizeAreas[0] && bundlesLeft > 0) {
            int bundleIndex = rand() % FurnitureBundleObject::bundleObjectConfigurations.size();
            FurnitureBundleConfiguration
                bundleConfiguration = FurnitureBundleObject::bundleObjectConfigurations[bundleIndex];
            // Check is selected bundle fits the free area of the room
            if (area < FurnitureBundleConfiguration::bundleSizeAreas[bundleConfiguration.size])
                continue;
            pair<Point, double> mainObjectPosition;
            Point mainObjectSize;
            bool mainBundleObjectPlaced = false;
            bundlesLeft--;
            int attempsLeft = numberOfAttemps;
            for (auto bundleItem = bundleConfiguration.objectAssetConfigurations.begin();
                 bundleItem != bundleConfiguration.objectAssetConfigurations.end(); ++bundleItem) {
                if (!mainBundleObjectPlaced && bundleItem->position == FurnitureObjectConfiguration::PINNED) {
                    // Skip pinned object if main bundle object not placed
                    continue;
                }
                pair<Point, double> itemPosition;
                bool positionGenerated = false;
                if (bundleItem->position == FurnitureObjectConfiguration::BY_WALL) {
                    positionGenerated = getPositionNearWall(*room, *bundleItem, itemPosition);
                } else if (bundleItem->position
                    == FurnitureObjectConfiguration::PINNED) { // Element is pinned to the first element in the vector
                    positionGenerated =
                        getPinnedPosition(*room, *bundleItem, itemPosition, mainObjectPosition, mainObjectSize);
                } else if (bundleItem->position == FurnitureObjectConfiguration::FLOATING) {
                    positionGenerated = getFloatingPosition(*room, *bundleItem, itemPosition);
                } else if (bundleItem->position == FurnitureObjectConfiguration::ANY) {
                    positionGenerated = getPositionAny(*room, *bundleItem, itemPosition);
                }
                if (positionGenerated && isPlaceEmpty(itemPosition.first.x,
                                                      itemPosition.first.y,
                                                      bundleItem->configuration.width,
                                                      bundleItem->configuration.height)) {
                    FurnitureBundleObject object;
                    object.configuration = bundleItem->configuration;
                    object.x = itemPosition.first.x;
                    object.y = itemPosition.first.y;
                    object.angle = itemPosition.second;
                    objects.push_back(object);
                    if (bundleItem == bundleConfiguration.objectAssetConfigurations.begin()) {
                        // Store position of the main bundle object
                        mainObjectPosition = itemPosition;
                        Rectangle objectRect = Rectangle(Point(0, 0),
                                                         Point(bundleItem->configuration.width,
                                                               bundleItem->configuration.height));
                        Rectangle boundingBox = getBoundingBox(objectRect, object.angle);
                        mainObjectSize = Point(boundingBox.second.x - boundingBox.first.x,
                                               boundingBox.second.y - boundingBox.first.y);
                        mainBundleObjectPlaced = true;
                    }
                    attempsLeft = numberOfAttemps;
                } else {
                    attempsLeft--;
                    if (attempsLeft <= 0) {
                        attempsLeft = numberOfAttemps;
                    } else {
                        --bundleItem; // Try place it one more time
                    }
                }
            }
            area -= FurnitureBundleConfiguration::bundleSizeAreas[bundleConfiguration.size];
        }
    }
}

bool Building::getPositionNearWall(Room &room, FurnitureObjectConfiguration &bundleItem, pair<Point, double> &result) {
    int x = 0;
    int y = 0;
    double angle;
    Rectangle itemRect(Point(0, 0), Point(bundleItem.configuration.width, bundleItem.configuration.height));
    Rectangle boundingBox;
    int boundingBoxWidth;
    int boundingBoxHeight;
    int wallIndex = rand() % 4;
    switch (wallIndex) {
        case 0: // Top wall
            angle = 270 + bundleItem.angle;
            break;
        case 1: // Bottom wall
            angle = 90 + bundleItem.angle;
            break;
        case 2: // Left wall
            angle = bundleItem.angle;
            break;
        case 3: // Right wall
            angle = 180 + bundleItem.angle;
            break;
        default:throw runtime_error("rand() % 4 returns not value in range [0, 3]");
    }
    boundingBox = getBoundingBox(itemRect, angle);
    boundingBoxWidth = boundingBox.second.x - boundingBox.first.x;
    boundingBoxHeight = boundingBox.second.y - boundingBox.first.y;
    Line line;
    switch (wallIndex) {
        case 0: // Top wall
            x = rand() % (room.rect.second.x - room.rect.first.x - boundingBoxWidth);
            x += room.rect.first.x + boundingBoxWidth / 2;
            y = room.rect.first.y + wallWidth + boundingBoxHeight / 2;
            line.first = Point(x - boundingBoxWidth, room.rect.first.y);
            line.second = Point(x + boundingBoxWidth, room.rect.first.y);

            line.first.x = line.first.x - (line.first.x % WALL_ALIGN_FACTOR);
            line.second.x = line.second.x + WALL_ALIGN_FACTOR - (line.second.x % WALL_ALIGN_FACTOR);
            break;
        case 1: // Bottom wall
            x = rand() % (room.rect.second.x - room.rect.first.x - boundingBoxWidth);
            x += room.rect.first.x + boundingBoxWidth / 2;
            y = room.rect.second.y - boundingBoxHeight / 2;
            line.first = Point(x - boundingBoxWidth, room.rect.second.y);
            line.second = Point(x + boundingBoxWidth, room.rect.second.y);

            line.first.x = line.first.x - (line.first.x % WALL_ALIGN_FACTOR);
            line.second.x = line.second.x + WALL_ALIGN_FACTOR - (line.second.x % WALL_ALIGN_FACTOR);
            break;
        case 2: // Left wall
            y = rand() % (room.rect.second.y - room.rect.first.y - boundingBoxHeight);
            y += room.rect.first.y + boundingBoxHeight / 2;
            x = room.rect.first.x + wallWidth + boundingBoxWidth / 2;
            line.first = Point(room.rect.first.x, y - boundingBoxHeight);
            line.second = Point(room.rect.first.x, y + boundingBoxHeight);

            line.first.y = line.first.y - (line.first.y % WALL_ALIGN_FACTOR);
            line.second.y = line.second.y + WALL_ALIGN_FACTOR - (line.second.y % WALL_ALIGN_FACTOR);
            break;
        case 3: // Right wall
            y = rand() % (room.rect.second.y - room.rect.first.y - boundingBoxHeight);
            y += room.rect.first.y + boundingBoxHeight / 2;
            x = room.rect.second.x - boundingBoxWidth / 2;
            line.first = Point(room.rect.second.x, y - boundingBoxHeight);
            line.second = Point(room.rect.second.x, y + boundingBoxHeight);

            line.first.y = line.first.y - (line.first.y % WALL_ALIGN_FACTOR);
            line.second.y = line.second.y + WALL_ALIGN_FACTOR - (line.second.y % WALL_ALIGN_FACTOR);
            break;
        default:throw runtime_error("rand() % 4 returns not value in range [0, 3]");
    }
    if (!isWallFree(line))
        return false;
    if (x <= room.rect.first.x || x + boundingBoxWidth >= room.rect.second.x || y <= room.rect.first.y
        || y + boundingBoxHeight >= room.rect.second.y)
        return false;
    angle = (angle > 360.0) ? (angle - 360) : angle;
    result.first = Point(x, y);
    result.second = angle;
    return true;
};

bool Building::getPinnedPosition(Room &room,
                                 FurnitureObjectConfiguration &bundleItem,
                                 pair<Point, double> &result,
                                 pair<Point, double> mainObjectPosition,
                                 Point mainObjectSize) {
    int side = rand() % 4;
    int x;
    int y;
    double angle;
    switch (side) {
        case 0: // Top side
            x = rand() % mainObjectSize.x;
            y = mainObjectPosition.first.y - 10 - bundleItem.configuration.height;
            angle = 90 + bundleItem.angle;
            x += mainObjectPosition.first.x;
            break;
        case 1: // Bottom side
            x = rand() % mainObjectSize.x;
            y = mainObjectPosition.first.y + mainObjectSize.y + 10;
            angle = 270 + bundleItem.angle;
            x += mainObjectPosition.first.x;
            break;
        case 2: // Left side
            x = mainObjectPosition.first.x - bundleItem.configuration.width - 10;
            y = rand() % mainObjectSize.y;
            angle = 180 + bundleItem.angle;
            y += mainObjectPosition.first.y;
            break;
        case 3: // Right side
            x = mainObjectPosition.first.x + mainObjectSize.x + 10;
            y = rand() % mainObjectSize.y;
            angle = bundleItem.angle;
            y += mainObjectPosition.first.y;
            break;
        default:throw runtime_error("rand() % 4 returns not value in range [0, 3]");
    }
    Rectangle itemRect(Point(0, 0), Point(bundleItem.configuration.width, bundleItem.configuration.height));
    Rectangle boundingBox = getBoundingBox(itemRect, angle);
    int boundingBoxWidth = boundingBox.second.x - boundingBox.first.x;
    int boundingBoxHeight = boundingBox.second.y - boundingBox.first.y;

    if (x <= room.rect.first.x || x + boundingBoxWidth >= room.rect.second.x || y <= room.rect.first.y
        || y + boundingBoxHeight >= room.rect.second.y)
        return false;

    x += bundleItem.configuration.width / 2;
    y += bundleItem.configuration.height / 2;

    result.first = Point(x, y);
    result.second = angle;
    return true;
}

bool Building::getFloatingPosition(Room &room, FurnitureObjectConfiguration &bundleItem, pair<Point, double> &result) {
    int roomWidth = room.rect.second.x - room.rect.first.x;
    int roomHeight = room.rect.second.y - room.rect.first.y;
    if (roomWidth <= WALL_ALIGN_FACTOR * 2 || roomHeight <= WALL_ALIGN_FACTOR * 2)
        return false;
    int x = rand() % (roomWidth - WALL_ALIGN_FACTOR * 2) + WALL_ALIGN_FACTOR * 1;
    int y = rand() % (roomHeight - WALL_ALIGN_FACTOR * 2) + WALL_ALIGN_FACTOR * 1;
    double angle = 90 * (rand() % 4);
    x += room.rect.first.x;
    y += room.rect.first.y;

    Rectangle itemRect(Point(0, 0), Point(bundleItem.configuration.width, bundleItem.configuration.height));
    Rectangle boundingBox = getBoundingBox(itemRect, angle);
    int boundingBoxWidth = boundingBox.second.x - boundingBox.first.x;
    int boundingBoxHeight = boundingBox.second.y - boundingBox.first.y;

    if (x <= room.rect.first.x || x + boundingBoxWidth >= room.rect.second.x || y <= room.rect.first.y
        || y + boundingBoxHeight >= room.rect.second.y)
        return false;

    x += boundingBoxWidth / 2;
    y += boundingBoxHeight / 2;

    result.first = Point(x, y);
    result.second = angle;
    return true;
}

bool Building::getPositionAny(Room &room, FurnitureObjectConfiguration &bundleItem, pair<Point, double> &result) {
    if (rand() % 2)
        return getPositionNearWall(room, bundleItem, result);
    else
        return getFloatingPosition(room, bundleItem, result);
}
