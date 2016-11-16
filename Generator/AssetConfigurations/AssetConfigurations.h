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
    int width;
    int height;
    int spriteId;
    int behaviorId;
    int magic;

    ObjectAssetConfiguration(int id, int width, int height, int spriteId, int behaviorId, int magic)
        : id(id), width(width), height(height), spriteId(spriteId), behaviorId(behaviorId), magic(magic) {}
};

/**
 * Describes a door to place on the map
 */
class DoorObject {

public:
    enum DOOR_TYPE {
        objEditorDoorV = 0,
        objEditorDoorH,
        objEditorDoorV2,
        objEditorDoorH2
    };

    static const vector<ObjectAssetConfiguration> doorObjectConfigurations;

    DOOR_TYPE type;
    int x;
    int y;

};

/**
 * Describes a weapon do place on the map
 */
class WeaponObject {

public:
    enum WEAPON_TYPE {

    };

    static const vector<ObjectAssetConfiguration> weaponObjectConfigurations;

    WEAPON_TYPE type;
    int x;
    int y;

};

#endif //HLM2PROCEDUREMAPGENERATOR_ASSETCONFIGURATIONS_H
