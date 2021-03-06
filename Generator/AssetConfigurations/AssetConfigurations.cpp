//
// Created by Aleksandr Parfenov on 16.11.16.
//

#include "AssetConfigurations.h"

const double EnemyObject::MELEE_RANDOM_PROBABILITY = 0.7;
const double EnemyObject::RANDOM_PROBABILITY = 0.6;
const double EnemyObject::PATROL_PROBABILITY = 0.5;
const double EnemyObject::STATIC_PROBABILITY = 0.6;
const double EnemyObject::MELEE_PATROL_PROBABILITY = 0.7;
const double EnemyObject::FAT_PROBABILITY = 0.4;
const double EnemyObject::DODGER_PROBABILITY = 0.3;
const double EnemyObject::IDLE_PROBABILITY = 0.5;
const double EnemyObject::DOG_PROBABILITY = 0.5;

const vector<WallAssetConfiguration> WallObject::horizontalWalls = {
    WallAssetConfiguration(986, 1649, 0),  // SUBWAY_WALL
    WallAssetConfiguration(7, 62, 0),      // WALL
    WallAssetConfiguration(32, 99, 0),    // BRICK_WALL
    WallAssetConfiguration(34, 98, 0),     // SOFT_WALL
    WallAssetConfiguration(1272, 2148, 0), // SEWER_WALL
    WallAssetConfiguration(102, 176, 0),   // PORCH_WALL
    WallAssetConfiguration(677, 1131, 0),  // WOOD_WALL
    WallAssetConfiguration(683, 1925, 0),  // WOOD_WINDOW
    WallAssetConfiguration(1511, 2656, 0), // RENOVATION_WALL
};

const vector<WallAssetConfiguration> WallObject::verticalWalls = {
    WallAssetConfiguration(1742, 2996, 0),  // SUBWAY_WALL
    WallAssetConfiguration(8, 63, 0),      // WALL
    WallAssetConfiguration(31, 100, 0),    // BRICK_WALL
    WallAssetConfiguration(33, 97, 0),     // SOFT_WALL
    WallAssetConfiguration(1271, 2149, 0), // SEWER_WALL
    WallAssetConfiguration(101, 177, 0),   // PORCH_WALL
    WallAssetConfiguration(675, 1132, 0),  // WOOD_WALL
    WallAssetConfiguration(682, 1143, 0),  // WOOD_WINDOW
    WallAssetConfiguration(1512, 2657, 0), // RENOVATION_WALL
};

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

/**
 *  Enemy configurations
 */
const vector<pair<double, vector<ObjectAssetConfiguration>>> EnemyObject::enemyObjectConfigurations = {
    make_pair(EnemyObject::MELEE_RANDOM_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(170, 10, ENEMY_SIZE, ENEMY_SIZE, 205, 170, 0),             // objEGangMeleeRandom
//        ObjectAssetConfiguration(672, 10, ENEMY_SIZE, ENEMY_SIZE, 1118, 672, 0),            // objSoldierMeleeRandom
          ObjectAssetConfiguration(875, 10, ENEMY_SIZE, ENEMY_SIZE, 66, 875, 0),              // objEMafiaMeleeRandom
//        ObjectAssetConfiguration(931, 10, ENEMY_SIZE, ENEMY_SIZE, 1553, 931, 0),            // objEPoliceMeleeRandom
          ObjectAssetConfiguration(1354, 10, ENEMY_SIZE, ENEMY_SIZE, 2292, 1354, 0)           // objColombianMeleeRandom
    })),

    make_pair(EnemyObject::RANDOM_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(183, 10, ENEMY_SIZE, ENEMY_SIZE, 201, 183, 0),             // objEGangRandom
//        ObjectAssetConfiguration(674, 10, ENEMY_SIZE, ENEMY_SIZE, 1117, 674, 0),            // objSoldierRandom
          ObjectAssetConfiguration(876, 10, ENEMY_SIZE, ENEMY_SIZE, 70, 876, 0),              // objEMafiaRandom
//        ObjectAssetConfiguration(932, 10, ENEMY_SIZE, ENEMY_SIZE, 1551, 932, 0),            // objEPoliceRandom
          ObjectAssetConfiguration(1356, 10, ENEMY_SIZE, ENEMY_SIZE, 2291, 1356, 0)           // objColombianRandom
    })),

    make_pair(EnemyObject::PATROL_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(184, 10, ENEMY_SIZE, ENEMY_SIZE, 201, 184, 0),             // objEGangPatrol
//        ObjectAssetConfiguration(696, 10, ENEMY_SIZE, ENEMY_SIZE, 1117, 696, 0),            // objSoldierPatrol
          ObjectAssetConfiguration(878, 10, ENEMY_SIZE, ENEMY_SIZE, 70, 878, 0),              // objEMafiaPatrol
//        ObjectAssetConfiguration(933, 10, ENEMY_SIZE, ENEMY_SIZE, 1558, 933, 0),            // objEPolicePatrol
          ObjectAssetConfiguration(1358, 10, ENEMY_SIZE, ENEMY_SIZE, 2291, 1358, 0)           // objColombianPatrol
    })),

    make_pair(EnemyObject::STATIC_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(186, 10, ENEMY_SIZE, ENEMY_SIZE, 208, 186, 0),             // objEGangStatic
//        ObjectAssetConfiguration(697, 10, ENEMY_SIZE, ENEMY_SIZE, 1117, 697, 0),            // objSoldierStatic
          ObjectAssetConfiguration(877, 10, ENEMY_SIZE, ENEMY_SIZE, 70, 877, 0),              // objEMafiaStatic
//        ObjectAssetConfiguration(934, 10, ENEMY_SIZE, ENEMY_SIZE, 1558, 934, 0),            // objEPoliceStatic
          ObjectAssetConfiguration(1357, 10, ENEMY_SIZE, ENEMY_SIZE, 2291, 1357, 0)           // objColombianStatic
    })),

    make_pair(EnemyObject::MELEE_PATROL_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(941, 10, ENEMY_SIZE, ENEMY_SIZE, 202, 941, 0),             // objEGangMeleePatrol
//        ObjectAssetConfiguration(2396, 10, ENEMY_SIZE, ENEMY_SIZE, 1118, 2396, 0),          // objSoldierMeleePatrol
          ObjectAssetConfiguration(938, 10, ENEMY_SIZE, ENEMY_SIZE, 66, 938, 0),              // objEMafiaMeleePatrol
//        ObjectAssetConfiguration(939, 10, ENEMY_SIZE, ENEMY_SIZE, 1553, 939, 0),            // objEPoliceMeleePatrol
          ObjectAssetConfiguration(1355, 10, ENEMY_SIZE, ENEMY_SIZE, 2290, 1355, 0)           // objColombianMeleePatrol
    })),

    make_pair(EnemyObject::FAT_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(1289, 10, ENEMY_SIZE, ENEMY_SIZE, 2194, 1289, 0),          // objEGangFat
//        ObjectAssetConfiguration(698, 10, ENEMY_SIZE, ENEMY_SIZE, 1163, 698, 0),            // objSoldierFatKnife
//        ObjectAssetConfiguration(704, 10, ENEMY_SIZE, ENEMY_SIZE, 1161, 704, 0),            // objSoldierFatGun
          ObjectAssetConfiguration(1464, 10, ENEMY_SIZE, ENEMY_SIZE, 2596, 1464, 0),          // objEMafiaFat
          ObjectAssetConfiguration(937, 10, ENEMY_SIZE, ENEMY_SIZE, 1570, 937, 0)             // objFatPolice
    })),

    make_pair(EnemyObject::DODGER_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(2286, 10, ENEMY_SIZE, ENEMY_SIZE, 3973, 2286, 0),          // objGangDodger
//        ObjectAssetConfiguration(2287, 10, ENEMY_SIZE, ENEMY_SIZE, 3977, 2287, 0),          // objSoldierDodger
          ObjectAssetConfiguration(1886, 10, ENEMY_SIZE, ENEMY_SIZE, 3287, 1886, 0)           // objColombianDodger
    })),

    make_pair(EnemyObject::IDLE_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(229, 10, ENEMY_SIZE, ENEMY_SIZE, 195, 229, 0),         // objEGangIdlePipe
          ObjectAssetConfiguration(230, 10, ENEMY_SIZE, ENEMY_SIZE, 211, 230, 0),         // objEGangIdleKnife
          ObjectAssetConfiguration(231, 10, ENEMY_SIZE, ENEMY_SIZE, 210, 231, 0),         // objEGangIdleSmoke
          ObjectAssetConfiguration(2407, 10, ENEMY_SIZE, ENEMY_SIZE, 2077, 2407, 0),      // objEMafiaIdleSmoke
          ObjectAssetConfiguration(2408, 10, ENEMY_SIZE, ENEMY_SIZE, 2078, 2408, 0),      // objEMafiaIdlePipe
//        ObjectAssetConfiguration(2409, 10, ENEMY_SIZE, ENEMY_SIZE, 1336, 2409, 0),      // objPoliceIdleTalk
          ObjectAssetConfiguration(1359, 10, ENEMY_SIZE, ENEMY_SIZE, 2324, 1359, 0)       // objColombianIdlePipe
    })),

    make_pair(EnemyObject::DOG_PROBABILITY, vector<ObjectAssetConfiguration>({
          ObjectAssetConfiguration(1064, 10, ENEMY_SIZE, ENEMY_SIZE, 1766, 1064, 0),      // objDogPatrol
    }))
};

const vector<FurnitureBundleConfiguration> FurnitureBundleObject::bundleObjectConfigurations = {
    // TV_SET
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::SMALL, FurnitureBundleConfiguration::TV_SET,
                                 vector<FurnitureObjectConfiguration>({
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(215, 11, 24, 30, 374, 215, 0)),           // sprElisTVBig, main
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::PINNED, 180.0, ObjectAssetConfiguration(104, 11, 24, 30, 178, 104, 0)),           // sprELisArmChair
    })),

    // BAR
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::BIG, FurnitureBundleConfiguration::BAR,
                                vector<FurnitureObjectConfiguration>({
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::FLOATING, 0.0, ObjectAssetConfiguration(261, 11, 95, 160, 418, 261, 0)),     // sprElisBarFans
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::PINNED, 0.0, ObjectAssetConfiguration(1139, 11, 18, 15, 1918, 1139, 0)),     // sprELisBarStool
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::PINNED, 0.0, ObjectAssetConfiguration(1139, 11, 18, 15, 1918, 1139, 0)),     // sprELisBarStool
    })),

    // BEDROOM
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::BIG, FurnitureBundleConfiguration::BEDROOM,
                                 vector<FurnitureObjectConfiguration>({
        // No main
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 180.0, ObjectAssetConfiguration(1942, 11, 51, 34, 3360, 1942, 0)),    // sprELisBedNormal
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(123, 11, 11, 49, 237, 123, 0)),    // sprElisCloset
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(1902, 11, 24, 24, 3304, 1902, 0)),    // sprELisDresser

    })),

    // STUFF
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::MEDIUM, FurnitureBundleConfiguration::STUFF,
                                 vector<FurnitureObjectConfiguration>({
        // No main
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::ANY, 90.0, ObjectAssetConfiguration(96, 11, 22, 17, 170, 96, 0)),     // sprElisBoxes
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(122, 11, 35, 20, 223, 122, 0)),    // sprElisCabinBooze
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(119, 11, 49, 17, 227, 119, 0)),    // sprElisDeskPictures
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(289, 11, 60, 60, 447, 289, 0)),     // sprElisHugePlant
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::ANY, 90.0, ObjectAssetConfiguration(96, 11, 22, 17, 170, 96, 0)),     // sprElisBoxes
    })),

    // TABLE_STOOLS
    // FurnitureBundleConfiguration(FurnitureBundleConfiguration::SMALL, FurnitureBundleConfiguration::TABLE_STOOLS,
    //                              vector<FurnitureObjectConfiguration>({
    //     // FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(1667, 11, 86, 82, 2842, 1667, 0)),  // sprELisFancyOfficeMeetingTable1
    //     FurnitureObjectConfiguration(FurnitureObjectConfiguration::ANY, 0.0, ObjectAssetConfiguration(258, 11, 70, 70, 415, 258, 0)),    // sprElisFansTable
    // })),

    // COUCH
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::MEDIUM, FurnitureBundleConfiguration::COUCH,
                                 vector<FurnitureObjectConfiguration>({
        // FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(207, 11, 64, 28, 361, 207, 0)),  // sprElisCouchBeige
        // FurnitureObjectConfiguration(FurnitureObjectConfiguration::PINNED, 270.0, ObjectAssetConfiguration(122, 11, 35, 20, 223, 122, 0)),    // sprElisCabinBooze
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(1104, 11, 120, 26, 1875, 1104, 0)),    // sprELisFansCouch2
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::PINNED, 0.0, ObjectAssetConfiguration(258, 11, 70, 70, 415, 258, 0)),    // sprElisFansTable
    })),

    // KITCHEN
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::MEDIUM, FurnitureBundleConfiguration::KITCHEN,
                                 vector<FurnitureObjectConfiguration>({
        // No main
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(71, 11, 30, 30, 125, 71, 0)),  // sprELisCounterKitchen
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(72, 11, 30, 30, 147, 72, 0)),   // sprELisCupboardKitchen
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(74, 11, 24, 40, 149, 74, 0)),   // sprELisFridge
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(214, 11, 30, 25, 373, 214, 0)),  // sprElisKitchenSink
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(853, 11, 22, 23, 1376, 853, 0)),  // sprElisStove
    })),

    // STUDY
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::MEDIUM, FurnitureBundleConfiguration::STUDY,
                                 vector<FurnitureObjectConfiguration>({
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::FLOATING, 90.0, ObjectAssetConfiguration(113, 11, 60, 50, 220, 113, 0)),      // sprElisDeskKidParty, main
        // FurnitureObjectConfiguration(FurnitureObjectConfiguration::PINNED, 180.0, ObjectAssetConfiguration(104, 11, 24, 30, 178, 104, 0)),           // sprELisArmChair
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::PINNED, 270.0, ObjectAssetConfiguration(103, 11, 20, 28, 179, 103, 0)),    // sprElisChairWood
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(1901, 11, 16, 52, 3303, 1901,0)),          // sprElisBookshelfBig2
        // FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(95, 11, 20, 17, 168, 95, 0)),          // sprElisGlobe
    })),

    // LAUNDRY
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::MEDIUM, FurnitureBundleConfiguration::KITCHEN,
                                 vector<FurnitureObjectConfiguration>({
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 90.0, ObjectAssetConfiguration(227, 11, 22, 35, 387, 227, 0)),  // sprElisLaundryMachine
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(140, 11, 30, 26, 253, 140, 0)),  // sprElisLaundryBasket
    })),

    // RESTROOM
    FurnitureBundleConfiguration(FurnitureBundleConfiguration::SMALL, FurnitureBundleConfiguration::LAUNDRY,
                                 vector<FurnitureObjectConfiguration>({
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(73, 11, 24, 24, 148, 73, 0)),  // sprELisSink
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(134, 11, 24, 24, 247, 134, 0)),  // sprElisToilet
        FurnitureObjectConfiguration(FurnitureObjectConfiguration::BY_WALL, 0.0, ObjectAssetConfiguration(86, 11, 50, 40, 161, 86, 0)),  // sprELisTrashbagOpen
    })),

};

const vector<int> FurnitureBundleConfiguration::bundleSizeAreas = {
    5000,           // SMALL
    10000,           // MEDIUM
    20500            // BIG
};
