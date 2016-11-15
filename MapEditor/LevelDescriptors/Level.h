//
// Created by Aleksandr Parfenov on 14.10.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_LEVEL_H
#define HLM2PROCEDUREMAPGENERATOR_LEVEL_H

#include "../../common.h"
#include "ObjectMap.h"
#include "PlayMap.h"
#include "TileMap.h"
#include "WallMap.h"
#include "LevelMetaInformation.h"

class Level {
public:
    Level(string levelPath);
    Level() {}

    LevelMetaInformation metaInformation;
    vector<ObjectMap> objectMaps;
    vector<PlayMap> playMaps;
    vector<TileMap> tileMaps;
    vector<WallMap> wallMaps;
};

#endif //HLM2PROCEDUREMAPGENERATOR_LEVEL_H
