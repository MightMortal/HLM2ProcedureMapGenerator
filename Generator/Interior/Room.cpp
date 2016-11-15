//
// Created by Aleksandr Parfenov on 12.11.16.
//

#include "Room.h"

bool Room::corridorFloorConfigured = false;
RoomFloor Room::corridorFloor;
const int ROOM_FLOOR_TYPES = 4; // Use only first 4 types

const vector<RoomFloorAssetConfiguration> RoomFloor::floorTypeConfigurations = {
    RoomFloorAssetConfiguration(2, 1001, 192, 208), // Default
    RoomFloorAssetConfiguration(5, 1001, 160, 128), // Bathroom
    RoomFloorAssetConfiguration(6, 1001, 192, 176), // Rugs
    RoomFloorAssetConfiguration(7, 1001, 112, 176), // Tile
    RoomFloorAssetConfiguration(47, 1001, 128, 128), // Train
    RoomFloorAssetConfiguration(8, 1001, 128, 128), // Stairs
    RoomFloorAssetConfiguration(3, 1001, 112, 64), // Asphalt
    RoomFloorAssetConfiguration(17, 1001, 192, 64), // Sand
    RoomFloorAssetConfiguration(4, 1001, 160, 224), // Dirt Blood
    RoomFloorAssetConfiguration(9, 1000, 192, 224), // Edges
    RoomFloorAssetConfiguration(10, -99, 40, 32), // Corners
};

Room::Room(Rectangle rect, Room::RoomType type) : rect(rect), type(type) {
    if (type == CORRIDOR && corridorFloorConfigured) {
        floor = corridorFloor;
    } else {
        floor.type = (RoomFloor::ROOM_FLOOR_TYPE) (rand() % ROOM_FLOOR_TYPES);
        floor.tx = alignValue((rand() % RoomFloor::floorTypeConfigurations[floor.type].width), TILE_ALIGN_FACTOR);
        floor.ty = alignValue((rand() % RoomFloor::floorTypeConfigurations[floor.type].height), TILE_ALIGN_FACTOR);
        floor.attribute = RoomFloor::floorTypeConfigurations[floor.type].attribute;
    }
}

void Room::generateCorridorFloor() {
    RoomFloor floor;
    floor.type = (RoomFloor::ROOM_FLOOR_TYPE) (rand() % ROOM_FLOOR_TYPES);
    floor.tx = alignValue((rand() % RoomFloor::floorTypeConfigurations[floor.type].width), TILE_ALIGN_FACTOR);
    floor.ty = alignValue((rand() % RoomFloor::floorTypeConfigurations[floor.type].height), TILE_ALIGN_FACTOR);
    floor.attribute = RoomFloor::floorTypeConfigurations[floor.type].attribute;
    corridorFloor = floor;
    corridorFloorConfigured = true;
}