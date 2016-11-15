//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_ROOM_H
#define HLM2PROCEDUREMAPGENERATOR_ROOM_H

#include "../Geometry/Geometry.h"

const int WALL_ALIGN_FACTOR = 32;
const int TILE_ALIGN_FACTOR = 16;
const int DOORWAY_LENGTH = 32;

struct RoomFloorAssetConfiguration {
    int id;
    int attribute;
    int width;
    int height;
    RoomFloorAssetConfiguration(int _id, int _attribute, int _width, int _height)
        : id(_id), attribute(_attribute), width(_width), height(_height) {}
};

class RoomFloor {
public:
    enum ROOM_FLOOR_TYPE {
        FLOOR_DEFAULT = 0,
        FLOOR_BATHROOM,
        FLOOR_RUGS,
        FLOOR_TILE,
        FLOOR_TRAIN,
        FLOOR_STAIRS,
        FLOOR_ASPHALT,
        FLOOR_SAND,
        FLOOR_DIRT_BLOOD,
        FLOOR_EDGES,
        FLOOR_CORNERS,
        FLOOR_TYPES_LENGTH
    };

    static const vector<RoomFloorAssetConfiguration> floorTypeConfigurations;

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

    static void generateCorridorFloor();

    static RoomFloor corridorFloor;
    static bool corridorFloorConfigured;
//private:
    Rectangle rect;
    RoomType type;
    RoomFloor floor;
    bool connectedWithCorridor;
};

#endif //HLM2PROCEDUREMAPGENERATOR_ROOM_H
