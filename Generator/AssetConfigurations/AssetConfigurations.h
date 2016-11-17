//
// Created by asleap on 16.11.2016.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_ASSETCONFIGURATIONS_H
#define HLM2PROCEDUREMAPGENERATOR_ASSETCONFIGURATIONS_H

#include "../../common.h"

/**
 * Describes a separate floor tile configuration
 */
struct RoomFloorAssetConfiguration {
    int id;
    int attribute;
    int width;
    int height;
    RoomFloorAssetConfiguration(int _id, int _attribute, int _width, int _height)
        : id(_id), attribute(_attribute), width(_width), height(_height) {}
};

/**
 * Describes a floor
 */
class RoomFloor {
public:
    enum ROOM_FLOOR_TYPE {
        FLOOR_DEFAULT = 0,
        FLOOR_BATHROOM,
        FLOOR_RUGS,
        FLOOR_TILE,
        FLOOR_TRAIN,
        FLOOR_STAIRS,
        FLOOR_ASPHALT,
        FLOOR_SAND,
        FLOOR_DIRT_BLOOD,
        FLOOR_EDGES,
        FLOOR_CORNERS,
        FLOOR_TYPES_LENGTH
    };

    static const vector<RoomFloorAssetConfiguration> floorTypeConfigurations;

    ROOM_FLOOR_TYPE type;
    int tx;
    int ty;
    int attribute;
};

/**
 * Describes a separate object tile configurations
 */
struct ObjectAssetConfiguration {
    int id;
    int editorId;
    int width;
    int height;
    int spriteId;
    int behaviorId;
    int magic;

    ObjectAssetConfiguration(int id, int editorId, int width, int height, int spriteId, int behaviorId, int magic)
        : id(id),
          editorId(editorId),
          width(width),
          height(height),
          spriteId(spriteId),
          behaviorId(behaviorId),
          magic(magic) {}
};

/**
 * Describes a object placed on the map
 */
class GameObject {
public:
    GameObject() : configuration(0, 0, 0, 0, 0, 0, 0) {}
    int x;
    int y;
    double angle;
    ObjectAssetConfiguration configuration;
};

/**
 * Describes a door to place on the map
 */
class DoorObject : public GameObject {
public:
    enum DOOR_TYPE {
        objEditorDoorV = 0,
        objEditorDoorH,
        objEditorDoorV2,
        objEditorDoorH2
    };
    DoorObject() {}

    static const vector<ObjectAssetConfiguration> doorObjectConfigurations;

    DOOR_TYPE type;
};

/**
 * Describes a weapon to place on the map
 */
class WeaponObject : public GameObject {
public:
    enum WEAPON_TYPE {
        objDoubleBarrel,
        objKnife,
        objChain,
        objShotgun,
        objUzi,
        obj9mm,
        objKalashnikov,
        objM16,
        objSilencer,
        objMP5,
        objChainsaw,
        objAxe,
        objDrill,
        objPotFull, // SUPER COOL
        objSilencedUzi,
    };

    static const vector<ObjectAssetConfiguration> weaponObjectConfigurations;

    WEAPON_TYPE type;
};

class EnemyObject : public GameObject {

public:
//    enum ENEMY_TYPE {
//        // GANG
//            objEGangMeleeRandom,
//        objEGangRandom,
//        objEGangPatrol,
//        objEGangStatic,
//        objEGangIdlePipe,
//        objEGangIdleKnife,
//        objEGangIdleSmoke,
//        objEGangMeleePatrol,
//        objEGangFat,
//        objGangDodger,
//        // SOLDIER
//            objSoldierMeleeRandom,
//        objSoldierRandom,
//        objSoldierPatrol,
//        objSoldierStatic,
//        objSoldierFatKnife,
//        objSoldierFatGun,
//        objSoldierDodger,
//        objSoldierMeleePatrol,
//        // MAFIA
//            bjEMafiaMeleeRandom,
//        objEMafiaRandom,
//        objEMafiaStatic,
//        objEMafiaPatrol,
//        objEMafiaMeleePatrol,
//        objEMafiaFat,
//        objEMafiaIdleSmoke,
//        objEMafiaIdlePipe,
//        // POLICE
//            objEPoliceMeleeRandom,
//        objEPoliceRandom,
//        objEPolicePatrol,
//        objEPoliceStatic,
//        objFatPolice,
//        objEPoliceMeleePatrol,
//        objPoliceIdleTalk,
//        // DOG
//            objDogPatrol,
//        // COLOMBIAN
//            objColombianMeleeRandom,
//        objColombianMeleePatrol,
//        objColombianRandom,
//        objColombianStatic,
//        objColombianPatrol,
//        objColombianIdlePipe,
//        objColombianDodger,
//        // GUARD
//        // PRISONER
//        // MISC
//            ENEMY_TYPE_LENGTH
//    };

//    enum ENEMY_GROUP {
//        GANG,
//        SOLDIER,
//        MAFIA,
//        POLICE,
//        DOG,
//        COLOMBIAN
//    };

//    enum ENEMY_KIND {
//        MELEE_RANDOM,
//        RANDOM,
//        PATROL,
//        STATIC,
//        MELEE_PATROL,
//        FAT,
//        DODGER,
//        IDLE,
//        DOG
//    };

//    static const vector<ObjectAssetConfiguration> enemyObjectConfigurations;

    static const double MELEE_RANDOM_PROBABILITY;
    static const double RANDOM_PROBABILITY;
    static const double PATROL_PROBABILITY;
    static const double STATIC_PROBABILITY;
    static const double MELEE_PATROL_PROBABILITY;
    static const double FAT_PROBABILITY;
    static const double DODGER_PROBABILITY;
    static const double IDLE_PROBABILITY;
    static const double DOG_PROBABILITY;
    static const int ENEMY_SIZE = 48;

    static const vector<pair<double, vector<ObjectAssetConfiguration>>> enemyObjectConfigurations2;

//    ENEMY_TYPE type;
//    ENEMY_GROUP group;
};

#endif //HLM2PROCEDUREMAPGENERATOR_ASSETCONFIGURATIONS_H
