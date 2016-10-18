//
// Created by asp437 on 13.09.16.
//

#ifndef HLM_LEVEL_READER_WALLMAP_H
#define HLM_LEVEL_READER_WALLMAP_H

#include "../../common.h"

class EditorWall {
public:
    int id;
    int x;
    int y;
    int attribute;
    int magic;
};

class WallMap {
public:
    WallMap(string filename);
    vector<EditorWall> walls;
};

#endif //HLM_LEVEL_READER_WALLMAP_H
