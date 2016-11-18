//
// Created by Aleksandr Parfenov on 12.11.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_BUILDING_H
#define HLM2PROCEDUREMAPGENERATOR_BUILDING_H

#include "../../common.h"
#include "Room.h"
#include "../BSP/BSP.h"
#include "../../MapEditor/LevelDescriptors/WallMap.h"
#include "../../MapEditor/LevelDescriptors/TileMap.h"
#include "../../MapEditor/LevelDescriptors/PlayMap.h"
#include "../../MapEditor/LevelDescriptors/ObjectMap.h"
#include "../AssetConfigurations/AssetConfigurations.h"

const int LEVEL_MAX_WIDTH = 1088;
const int LEVEL_MAX_HEIGHT = 768;

class Building {
public:
    Building(Rectangle rect);
    ~Building();

    WallMap generateWallMap();
    TileMap generateTileMap();
    PlayMap generatePlayMap();
    ObjectMap generateObjectMap();
//private:
    vector<Room> *rooms;
    vector<Line> walls;
    Rectangle rect;
    vector<Line> doorways;
    vector<GameObject> objects;
    vector<Line> windows;

    void generateDoors();
    bool checkConnectivity();
    void reduceNumberOfDoors();
    void generateDoorObjects();
    bool isPlaceEmpty(int x, int y, int w, int h, double angle = 0.0);
    void placeWeapon();
    void placeEnemy();
    void generateWindows();
    bool isWallFree(Line line);
    void placeWallIntoVector(vector<EditorWall> &editorWalls,
                             int x,
                             int y,
                             WallAssetConfiguration configuration);
    void generateFurniture();
    bool getPositionNearWall(Room& room, FurnitureObjectConfiguration& bundleItem, pair<Point, double>& result);
};

#endif //HLM2PROCEDUREMAPGENERATOR_BUILDING_H
