//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_ROOM_H
#define HLM2PROCEDUREMAPGENERATOR_ROOM_H

#include "../Geometry/Geometry.h"

const int WALL_ALIGN_FACTOR = 32;
const int TILE_ALIGN_FACTOR = 16;

class RoomFloor {
public:
    enum ROOM_FLOOR_TYPE {
        FLOOR_DEFAULT = 2,
        FLOOR_ASPHALT = 3,
        FLOOR_DIRT_BLOOD = 4,
        FLOOR_BATHROOM = 5,
        FLOOR_RUGS = 6,
        FLOOR_TILE = 7,
        FLOOR_STAIRS = 8,
        FLOOR_EDGES = 9,
        FLOOR_CORNERS = 10,
        FLOOR_SAND = 17,
        FLOOR_TRAIN = 47
    };

    ROOM_FLOOR_TYPE type;
    int tx;
    int ty;
    int attribute;
};

class Room {
public:
    enum RoomType {
        DEFAULT,
        LIVING_ROOM,
        CORRIDOR
    };

    Room(Rectangle rect, RoomType type);
//private:
    Rectangle rect;
    RoomType type;
    RoomFloor floor;
};

#endif //HLM2PROCEDUREMAPGENERATOR_ROOM_H
