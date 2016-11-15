//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "Room.h"

Room::Room(Rectangle rect, Room::RoomType type) : rect(rect), type(type) {
    floor.type = RoomFloor::FLOOR_DEFAULT;
    if (type == CORRIDOR)
        floor.tx = 32;
    else
        floor.tx = 0;
    floor.ty = 0;
    floor.attribute = 1001;
}
