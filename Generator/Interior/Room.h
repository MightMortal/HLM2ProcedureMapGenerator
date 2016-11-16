//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_ROOM_H
#define HLM2PROCEDUREMAPGENERATOR_ROOM_H

#include "../Geometry/Geometry.h"
#include "../AssetConfigurations/AssetConfigurations.h"

const int WALL_ALIGN_FACTOR = 32;
const int TILE_ALIGN_FACTOR = 16;
const int DOORWAY_LENGTH = 32;


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
