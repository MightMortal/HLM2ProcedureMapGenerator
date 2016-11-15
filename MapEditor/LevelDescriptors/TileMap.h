//
// Created by asp437 on 13.09.16.
//

#ifndef HLM_LEVEL_READER_TILES_H
#define HLM_LEVEL_READER_TILES_H

#include "../../common.h"

class EditorTile {
public:
    int id;
    int textureX;
    int textureY;
    int x;
    int y;
    int attribute;
};

class TileMap {
public:
    TileMap();
    TileMap(std::string filename);
    void save(string filename);

    std::vector<EditorTile> tiles;
};

#endif //HLM_LEVEL_READER_TILES_H
