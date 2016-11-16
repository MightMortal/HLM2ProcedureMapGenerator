//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "Room.h"

bool Room::corridorFloorConfigured = false;
RoomFloor Room::corridorFloor;
const int ROOM_FLOOR_TYPES = 4; // Use only first 4 typesx

Room::Room(Rectangle rect, Room::RoomType type) : rect(rect), type(type), connectedWithCorridor(type == CORRIDOR) {
    if (type == CORRIDOR && corridorFloorConfigured) {
        floor = corridorFloor;
    } else {
        floor.type = (RoomFloor::ROOM_FLOOR_TYPE) (rand() % ROOM_FLOOR_TYPES);
        floor.tx = alignValue((rand() % RoomFloor::floorTypeConfigurations[floor.type].width), TILE_ALIGN_FACTOR);
        floor.ty = alignValue((rand() % RoomFloor::floorTypeConfigurations[floor.type].height), TILE_ALIGN_FACTOR);
        floor.tx = clamp(floor.tx, 0, RoomFloor::floorTypeConfigurations[floor.type].width - TILE_ALIGN_FACTOR);
        floor.ty = clamp(floor.ty, 0, RoomFloor::floorTypeConfigurations[floor.type].height - TILE_ALIGN_FACTOR);
        floor.attribute = RoomFloor::floorTypeConfigurations[floor.type].attribute;
    }
}

void Room::generateCorridorFloor() {
    RoomFloor floor;
    floor.type = (RoomFloor::ROOM_FLOOR_TYPE) (rand() % ROOM_FLOOR_TYPES);
    floor.tx = alignValue((rand() % RoomFloor::floorTypeConfigurations[floor.type].width), TILE_ALIGN_FACTOR);
    floor.ty = alignValue((rand() % RoomFloor::floorTypeConfigurations[floor.type].height), TILE_ALIGN_FACTOR);
    floor.tx = clamp(floor.tx, 0, RoomFloor::floorTypeConfigurations[floor.type].width - TILE_ALIGN_FACTOR);
    floor.ty = clamp(floor.ty, 0, RoomFloor::floorTypeConfigurations[floor.type].height - TILE_ALIGN_FACTOR);
    floor.attribute = RoomFloor::floorTypeConfigurations[floor.type].attribute;
    corridorFloor = floor;
    corridorFloorConfigured = true;
}