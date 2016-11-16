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
    ObjectAssetConfiguration(25, 25, 6, 33, 91, 0, 0),
    ObjectAssetConfiguration(26, 26, 32, 4, 92, 0, 0),
    ObjectAssetConfiguration(2255, 2255, 6, 33, 3903, 0, 0),
    ObjectAssetConfiguration(2254, 2254, 32, 4, 3902, 0, 0)
};

const vector<ObjectAssetConfiguration> WeaponObject::weaponObjectConfigurations = {
    ObjectAssetConfiguration(150, 2401, 28, 7, 266, 150, 0),       // objDoubleBarrel
    ObjectAssetConfiguration(173, 2401, 12, 3, 307, 173, 0),       // objKnife
    ObjectAssetConfiguration(174, 2401, 16, 10, 308, 174, 0),      // objChain
    ObjectAssetConfiguration(177, 2401, 27, 9, 304, 177, 0),       // objShotgun
    ObjectAssetConfiguration(178, 2401, 14, 12, 303, 178, 0),      // objUzi
    ObjectAssetConfiguration(179, 2401, 11, 6, 302, 179, 0),       // obj9mm
    ObjectAssetConfiguration(723, 2401, 31, 10, 1197, 723, 0),     // objKalashnikov
    ObjectAssetConfiguration(724, 2401, 31, 13, 1194, 724, 0),     // objM16
    ObjectAssetConfiguration(880, 2401, 13, 6, 1458, 880, 0),      // objSilencer
    ObjectAssetConfiguration(882, 2401, 21, 12, 1459, 882, 0),     // objMP5
    ObjectAssetConfiguration(1055, 2401, 19, 7, 1754, 1055, 0),    // objChainsaw
    ObjectAssetConfiguration(1818, 2401, 30, 17, 3173, 1818, 0),   // objAxe
    ObjectAssetConfiguration(2337, 2401, 14, 8, 4149, 2337, 0),    // objDrill
    ObjectAssetConfiguration(2338, 2401, 14, 8, 4151, 2338, 0),    // objPotFull
    ObjectAssetConfiguration(2343, 2401, 19, 12, 4157, 2343, 0),   // objSilencedUzi
};

