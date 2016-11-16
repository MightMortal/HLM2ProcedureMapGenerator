//
// Created by Aleksandr Parfenov on 16.11.16.
//

#include "AssetConfigurations.h"

const vector<RoomFloorAssetConfiguration> RoomFloor::floorTypeConfigurations = {
    RoomFloorAssetConfiguration(2, 1001, 192, 208),                 // Default
    RoomFloorAssetConfiguration(5, 1001, 160, 128),                 // Bathroom
    RoomFloorAssetConfiguration(6, 1001, 192, 176),                 // Rugs
    RoomFloorAssetConfiguration(7, 1001, 112, 176),                 // Tile
    RoomFloorAssetConfiguration(47, 1001, 128, 128),                // Train
    RoomFloorAssetConfiguration(8, 1001, 128, 128),                 // Stairs
    RoomFloorAssetConfiguration(3, 1001, 112, 64),                  // Asphalt
    RoomFloorAssetConfiguration(17, 1001, 192, 64),                 // Sand
    RoomFloorAssetConfiguration(4, 1001, 160, 224),                 // Dirt Blood
    RoomFloorAssetConfiguration(9, 1000, 192, 224),                 // Edges
    RoomFloorAssetConfiguration(10, -99, 40, 32),                   // Corners
};

const vector<ObjectAssetConfiguration> DoorObject::doorObjectConfigurations = {
    ObjectAssetConfiguration(25, 25, 6, 33, 91, 0, 0),
    ObjectAssetConfiguration(26, 26, 32, 4, 92, 0, 0),
    ObjectAssetConfiguration(2255, 2255, 6, 33, 3903, 0, 0),
    ObjectAssetConfiguration(2254, 2254, 32, 4, 3902, 0, 0)
};

const vector<ObjectAssetConfiguration> WeaponObject::weaponObjectConfigurations = {
    ObjectAssetConfiguration(150, 2401, -1, -1, 266, 150, 0),       // objDoubleBarrel
    ObjectAssetConfiguration(173, 2401, -1, -1, 307, 173, 0),       // objKnife
    ObjectAssetConfiguration(174, 2401, -1, -1, 308, 174, 0),       // objChain
    ObjectAssetConfiguration(177, 2401, -1, -1, 304, 177, 0),       // objShotgun
    ObjectAssetConfiguration(178, 2401, -1, -1, 303, 178, 0),       // objUzi
    ObjectAssetConfiguration(179, 2401, -1, -1, 302, 179, 0),       // obj9mm
    ObjectAssetConfiguration(723, 2401, -1, -1, 1197, 723, 0),      // objKalashnikov
    ObjectAssetConfiguration(724, 2401, -1, -1, 1194, 724, 0),      // objM16
    ObjectAssetConfiguration(880, 2401, -1, -1, 1458, 880, 0),      // objSilencer
    ObjectAssetConfiguration(882, 2401, -1, -1, 1459, 882, 0),      // objMP5
    ObjectAssetConfiguration(1055, 2401, -1, -1, 1754, 1055, 0),    // objChainsaw
    ObjectAssetConfiguration(1818, 2401, -1, -1, 3173, 1818, 0),    // objAxe
    ObjectAssetConfiguration(2337, 2401, -1, -1, 4149, 2337, 0),    // objDrill
    ObjectAssetConfiguration(2338, 2401, -1, -1, 4151, 2338, 0),    // objPotFull
    ObjectAssetConfiguration(2343, 2401, -1, -1, 4157, 2343, 0),    // objSilencedUzi
};

const vector<ObjectAssetConfiguration> EnemyObject::enemyObjectConfigurations = {
    // GANG
    ObjectAssetConfiguration(170, 10, -1, -1, 205, 170, 0),         // objEGangMeleeRandom
    ObjectAssetConfiguration(193, 10, -1, -1, 201, 193, 0),         // objEGangRandom
    ObjectAssetConfiguration(184, 10, -1, -1, 201, 184, 0),         // objEGangPatrol
    ObjectAssetConfiguration(186, 10, -1, -1, 208, 186, 0),         // objEGangStatic
    ObjectAssetConfiguration(229, 10, -1, -1, 195, 229, 0),         // objEGangIdlePipe
    ObjectAssetConfiguration(230, 10, -1, -1, 211, 230, 0),         // objEGangIdleKnife
    ObjectAssetConfiguration(231, 10, -1, -1, 210, 231, 0),         // objEGangIdleSmoke
    // SOLDIER
    ObjectAssetConfiguration(672, 10, -1, -1, 1118, 672, 0),        // objSoldierMeleeRandom
    ObjectAssetConfiguration(674, 10, -1, -1, 1117, 674, 0),        // objSoldierRandom
    ObjectAssetConfiguration(696, 10, -1, -1, 1117, 696, 0),        // objSoldierPatrol
    ObjectAssetConfiguration(697, 10, -1, -1, 1117, 697, 0),        // objSoldierStatic
    ObjectAssetConfiguration(698, 10, -1, -1, 1163, 698, 0),        // objSoldierFatKnife
    ObjectAssetConfiguration(704, 10, -1, -1, 1161, 704, 0),        // objSoldierFatGun
    ObjectAssetConfiguration(706, 10, -1, -1, 1178, 706, 0),        // objSoldierIdlePonchoSmoke
    ObjectAssetConfiguration(707, 10, -1, -1, 1177, 707, 0),        // objPoncho
    ObjectAssetConfiguration(708, 10, -1, -1, 1179, 708, 0),        // objSoldierIdleRain
    ObjectAssetConfiguration(773, 10, -1, -1, 1279, 773, 0),        // objSoldierBurn

};
