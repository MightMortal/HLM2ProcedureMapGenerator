//
// Created by Aleksandr Parfenov on 16.11.16.
//

#include "AssetConfigurations.h"

const vector<RoomFloorAssetConfiguration> RoomFloor::floorTypeConfigurations = {
    RoomFloorAssetConfiguration(2, 1001, 192, 208),     // Default
    RoomFloorAssetConfiguration(5, 1001, 160, 128),     // Bathroom
    RoomFloorAssetConfiguration(6, 1001, 192, 176),     // Rugs
    RoomFloorAssetConfiguration(7, 1001, 112, 176),     // Tile
    RoomFloorAssetConfiguration(47, 1001, 128, 128),    // Train
    RoomFloorAssetConfiguration(8, 1001, 128, 128),     // Stairs
    RoomFloorAssetConfiguration(3, 1001, 112, 64),      // Asphalt
    RoomFloorAssetConfiguration(17, 1001, 192, 64),     // Sand
    RoomFloorAssetConfiguration(4, 1001, 160, 224),     // Dirt Blood
    RoomFloorAssetConfiguration(9, 1000, 192, 224),     // Edges
    RoomFloorAssetConfiguration(10, -99, 40, 32),       // Corners
};

const vector<ObjectAssetConfiguration> DoorObject::doorObjectConfigurations = {
    ObjectAssetConfiguration(25, 6, 33, 91, 0, 0),
    ObjectAssetConfiguration(26, 32, 4, 92, 0, 0),
    ObjectAssetConfiguration(2255, 6, 33, 3903, 0, 0),
    ObjectAssetConfiguration(2254, 32, 4, 3902, 0, 0)
};

const vector<ObjectAssetConfiguration> WeaponObject::weaponObjectConfigurations;