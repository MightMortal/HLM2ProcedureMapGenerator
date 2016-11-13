//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_ROOM_H
#define HLM2PROCEDUREMAPGENERATOR_ROOM_H

#include "../Geometry/Geometry.h"

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
};

#endif //HLM2PROCEDUREMAPGENERATOR_ROOM_H
