//
// Created by Timofey Lysenko on 13.09.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_OBJECTMANAGER_H
#define HLM2PROCEDUREMAPGENERATOR_OBJECTMANAGER_H

#include <map>
#include <memory>
#include "../../common.h"
#include "Object.h"
#include "Sprite.h"
#include "Wall.h"
#include "Tile.h"

const string OBJECTS_PATH = "MapEditor/Assets/csv/objects.csv";

const string SPRITES_PATH = "MapEditor/Assets/csv/sprites.csv";

const string TILES_PATH = "MapEditor/Assets/csv/tiles.csv";

const string WALLS_PATH = "MapEditor/Assets/csv/walls.csv";

class ObjectManager {
public:
    ObjectManager(string objects_path, string sprites_path);
    ObjectManager(string objects_path, string sprites_path, string tiles_path, string walls_path);

    virtual ~ObjectManager();

    pair<Object *, Sprite *> get(int objKey);
    Sprite *getSprite(int spriteKey);
    Tile *getTile(int tileKey);
    Wall *getWall(int wallKey);
private:
    map<int, Object *> _objects;
    map<int, Sprite *> _sprites;
    map<int, Tile *> _tiles;
    map<int, Wall *> _walls;
};

#endif //HLM2PROCEDUREMAPGENERATOR_OBJECTMANAGER_H
