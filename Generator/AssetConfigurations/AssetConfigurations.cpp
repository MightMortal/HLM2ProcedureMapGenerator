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

const vector<ObjectAssetConfiguration> EnemyObject::enemyObjectConfigurations = {
    // GANG
    ObjectAssetConfiguration(170, 10, -1, -1, 205, 170, 0),         // objEGangMeleeRandom
    ObjectAssetConfiguration(193, 10, -1, -1, 201, 193, 0),         // objEGangRandom
    ObjectAssetConfiguration(184, 10, -1, -1, 201, 184, 0),         // objEGangPatrol
    ObjectAssetConfiguration(186, 10, -1, -1, 208, 186, 0),         // objEGangStatic
    ObjectAssetConfiguration(229, 10, -1, -1, 195, 229, 0),         // objEGangIdlePipe
    ObjectAssetConfiguration(230, 10, -1, -1, 211, 230, 0),         // objEGangIdleKnife
    ObjectAssetConfiguration(231, 10, -1, -1, 210, 231, 0),         // objEGangIdleSmoke
    ObjectAssetConfiguration(941, 10, -1, -1, 202, 941, 0),         // objEGangMeleePatrol
    ObjectAssetConfiguration(1144, 10, -1, -1, 1927, 1144, 0),      // objEGangIdleMoney
    ObjectAssetConfiguration(1289, 10, -1, -1, 2194, 1289, 0),      // objEGangFat
    ObjectAssetConfiguration(2286, 10, -1, -1, 3973, 2286, 0),      // objGangDodger
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
    ObjectAssetConfiguration(1460, 10, -1, -1, 2589, 1460, 0),      // objSoldierHiding
    ObjectAssetConfiguration(2239, 10, -1, -1, 3874, 2239, 0),      // objSoldierBurnt
    ObjectAssetConfiguration(2287, 10, -1, -1, 3977, 2287, 0),      // objSoldierDodger
    ObjectAssetConfiguration(2396, 10, -1, -1, 1118, 2396, 0),      // objSoldierMeleePatrol
    // MAFIA
    ObjectAssetConfiguration(875, 10, -1, -1, 66, 875, 0),          // objEMafiaMeleeRandom
    ObjectAssetConfiguration(876, 10, -1, -1, 70, 876, 0),          // objEMafiaRandom
    ObjectAssetConfiguration(877, 10, -1, -1, 70, 877, 0),          // objEMafiaStatic
    ObjectAssetConfiguration(878, 10, -1, -1, 70, 878, 0),          // objEMafiaPatrol
    ObjectAssetConfiguration(916, 10, -1, -1, 1521, 916, 0),        // objEMafiaIdlePhoneSilencer
    ObjectAssetConfiguration(938, 10, -1, -1, 66, 938, 0),          // objEMafiaMeleePatrol
    ObjectAssetConfiguration(1464, 10, -1, -1, 2596, 1464, 0),      // objEMafiaFat
    ObjectAssetConfiguration(1854, 10, -1, -1, 3226, 1854, 0),      // objFatMafiaLSD
    ObjectAssetConfiguration(2407, 10, -1, -1, 2077, 2407, 0),      // objEMafiaIdleSmoke
    ObjectAssetConfiguration(2408, 10, -1, -1, 2078, 2408, 0),      // objEMafiaIdlePipe
    // POLICE
    ObjectAssetConfiguration(931, 10, -1, -1, 1553, 931, 0),        // objEPoliceMeleeRandom
    ObjectAssetConfiguration(932, 10, -1, -1, 1551, 932, 0),        // objEPoliceRandom
    ObjectAssetConfiguration(933, 10, -1, -1, 1558, 933, 0),        // objEPolicePatrol
    ObjectAssetConfiguration(934, 10, -1, -1, 1558, 934, 0),        // objEPoliceStatic
    ObjectAssetConfiguration(937, 10, -1, -1, 1570, 937, 0),        // objFatPolice
    ObjectAssetConfiguration(939, 10, -1, -1, 1553, 939, 0),        // objEPoliceMeleePatrol
    ObjectAssetConfiguration(2409, 10, -1, -1, 1336, 2409, 0),      // objPoliceIdleTalk
    // DOG
    ObjectAssetConfiguration(1064, 10, -1, -1, 1766, 1064, 0),      // objDogPatrol
    // COLOMBIAN
    ObjectAssetConfiguration(1354, 10, -1, -1, 2292, 1354, 0),      // objColombianMeleeRandom
    ObjectAssetConfiguration(1355, 10, -1, -1, 2290, 1355, 0),      // objColombianMeleePatrol
    ObjectAssetConfiguration(1356, 10, -1, -1, 2291, 1356, 0),      // objColombianRandom
    ObjectAssetConfiguration(1357, 10, -1, -1, 2291, 1357, 0),      // objColombianStatic
    ObjectAssetConfiguration(1358, 10, -1, -1, 2291, 1358, 0),      // objColombianPatrol
    ObjectAssetConfiguration(1359, 10, -1, -1, 2324, 1359, 0),      // objColombianIdlePipe
    ObjectAssetConfiguration(1737, 10, -1, -1, 3009, 1737, 0),      // objColombianHiding
    ObjectAssetConfiguration(1886, 10, -1, -1, 3287, 1886, 0),      // objColombianDodger
    // GUARD
    // PRISONER
    // MISC
    ObjectAssetConfiguration(2221, 10, -1, -1, 3812, 2221, 0),      // objEnemyCrawl
};
