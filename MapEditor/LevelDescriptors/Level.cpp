//
// Created by Aleksandr Parfenov on 14.10.16.
//

#include "Level.h"

Level::Level(string levelPath)
    :
    metaInformation(levelPath + "/level.hlm") {
    for (int i = 0; i <= metaInformation._floorNumber; i++) {
        string fileName = "/level" + to_string(i);
        playMaps.push_back(PlayMap(levelPath + fileName + ".play"));
        wallMaps.push_back(WallMap(levelPath + fileName + ".wll"));
        tileMaps.push_back(TileMap(levelPath + fileName + ".tls"));
        objectMaps.push_back(ObjectMap(levelPath + fileName + ".obj"));
    }
}

void Level::save(string levelPath) {
    wallMaps[0].save(levelPath + "/level0.wll");
    tileMaps[0].save(levelPath + "/level0.tls");
    objectMaps[0].save(levelPath + "/level0.obj");
    playMaps[0].save(levelPath + "/level0.play");
}