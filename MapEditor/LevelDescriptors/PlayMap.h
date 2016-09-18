//
// Created by Aleksandr Parfenov on 18.09.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_PLAYMAP_H
#define HLM2PROCEDUREMAPGENERATOR_PLAYMAP_H

#include "../../common.h"

class PlayObject
{
public:
    int id;
    int x;
    int y;
    int spriteId;
    double angle;
    int magic;
};

class PlayMap
{
public:
    PlayMap(string filename);
    vector<PlayObject> objects;
    int magic1;
    int magic2;
};


#endif //HLM2PROCEDUREMAPGENERATOR_PLAYMAP_H
