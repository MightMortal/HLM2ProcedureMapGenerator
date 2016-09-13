//
// Created by asp437 on 13.09.16.
//

#ifndef HLM_LEVEL_READER_TILES_H
#define HLM_LEVEL_READER_TILES_H

#include "../../common.h"

class Tile
{
public:
    int id;
    int textureX;
    int textureY;
    int x;
    int y;
    int attribute;
};

class TilesMap
{
public:
    TilesMap();
    TilesMap(std::string filename);
private:
    std::vector<Tile> map;
};


#endif //HLM_LEVEL_READER_TILES_H
