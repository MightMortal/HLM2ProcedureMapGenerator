//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_BUILDING_H
#define HLM2PROCEDUREMAPGENERATOR_BUILDING_H

#include "../../common.h"
#include "Room.h"
#include "../../MapEditor/LevelDescriptors/WallMap.h"

class Building {
public:
    Building(Rectangle rect);
    ~Building();

    WallMap generateWallMap();
//private:
    vector<Room> *rooms;
    vector<Line> walls;
};

#endif //HLM2PROCEDUREMAPGENERATOR_BUILDING_H
