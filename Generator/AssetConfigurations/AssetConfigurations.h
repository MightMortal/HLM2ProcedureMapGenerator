//
// Created by asleap on 16.11.2016.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_ASSETCONFIGURATIONS_H
#define HLM2PROCEDUREMAPGENERATOR_ASSETCONFIGURATIONS_H

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

    static const vector<RoomFloorAssetConfiguration> floorTypeConfigurations = {
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
    int behaviorId;
    int magic;

    ObjectAssetConfiguration(int id, int width, int height, int behaviorId, int magic)
        : id(id), width(width), height(height), behaviorId(behaviorId), magic(magic) {}
};

/**
 * Describes a door to place on the map
 */
class DoorObject {

public:
    enum DOOR_TYPE {
        objEditorDoorV = 25,
        objEditorDoorH = 26,
        objEditorDoorV2 = 2255,
        objEditorDoorH2 = 2254
    };

    static const vector<ObjectAssetConfiguration> doorObjectConfigurations = {
        ObjectAssetConfiguration(objEditorDoorV, -1, -1, -1, -1),
        ObjectAssetConfiguration(objEditorDoorH, -1, -1, -1, -1),
        ObjectAssetConfiguration(objEditorDoorV2, -1, -1, -1, -1),
        ObjectAssetConfiguration(objEditorDoorH2, -1, -1, -1, -1)
    };

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

    static const vector<ObjectAssetConfiguration> weaponObjectConfigurations = {

    };

    WEAPON_TYPE type;
    int x;
    int y;

};

#endif //HLM2PROCEDUREMAPGENERATOR_ASSETCONFIGURATIONS_H
