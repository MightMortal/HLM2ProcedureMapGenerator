//
// Created by asp437 on 13.09.16.
//

#ifndef HLM_LEVEL_READER_OBJECTSMAP_H
#define HLM_LEVEL_READER_OBJECTSMAP_H

#include "../../common.h"

class EditorObject
{
public:
    int id;
    int x;
    int y;
    int spriteId;
    double angle;
    int behaviorId;
    int magic;
};

class ObjectsMap
{
public:
    ObjectsMap(string filename);
private:
    vector<EditorObject> objectsMap;
};


#endif //HLM_LEVEL_READER_OBJECTSMAP_H
