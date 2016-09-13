//
// Created by Timofey Lysenko on 13.09.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_OBJECTMANAGER_H
#define HLM2PROCEDUREMAPGENERATOR_OBJECTMANAGER_H

#include <map>
#include <memory>
#include "../../common.h"
#include "Object.h"

const string objects_path = "MapEditor/Assets/csv/objects.csv";

const string sprites_path = "MapEditor/Assets/csv/sprites.csv";

class ObjectManager
{
public:
    vector<unique_ptr<Object>> objects;
    map<int, unique_ptr<Sprite>> spriteMap;

    ObjectManager(string objects_path, string sprites_path);

    virtual ~ObjectManager();
};


#endif //HLM2PROCEDUREMAPGENERATOR_OBJECTMANAGER_H
