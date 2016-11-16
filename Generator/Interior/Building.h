//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_BUILDING_H
#define HLM2PROCEDUREMAPGENERATOR_BUILDING_H

#include "../../common.h"
#include "Room.h"
#include "../BSP/BSP.h"
#include "../../MapEditor/LevelDescriptors/WallMap.h"
#include "../../MapEditor/LevelDescriptors/TileMap.h"

const int LEVEL_MAX_WIDTH = 1088;
const int LEVEL_MAX_HEIGHT = 768;

class Building {
public:
    Building(Rectangle rect);
    ~Building();

    WallMap generateWallMap();
    TileMap generateTileMap();
//private:
    vector<Room> *rooms;
    vector<Line> walls;
    Rectangle rect;
    vector<Line> doorways;

    void generateDoors();
    bool checkConnectivity();
    void reduceNumberOfDoors();
};

#endif //HLM2PROCEDUREMAPGENERATOR_BUILDING_H
