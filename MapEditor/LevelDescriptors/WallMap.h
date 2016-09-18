//
// Created by asp437 on 13.09.16.
//

#ifndef HLM_LEVEL_READER_WALLMAP_H
#define HLM_LEVEL_READER_WALLMAP_H

#include "../../common.h"

class Wall
{
public:
    int id;
    int x;
    int y;
    int attribute;
    int magic;
};

class WallMap
{
public:
    WallMap(string filename);
    vector<Wall> walls;
};


#endif //HLM_LEVEL_READER_WALLMAP_H
