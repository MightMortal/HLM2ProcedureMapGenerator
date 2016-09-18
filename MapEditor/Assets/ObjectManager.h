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
    ObjectManager(string objects_path, string sprites_path);

    virtual ~ObjectManager();

    pair<Object *, Sprite *> get(int objKey);
    Sprite *getSprite(int spriteKey);

private:
    map<int, Object *> _objects;
    map<int, Sprite *> _sprites;
};


#endif //HLM2PROCEDUREMAPGENERATOR_OBJECTMANAGER_H
