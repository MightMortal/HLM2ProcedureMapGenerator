//
// Created by Timofey Lysenko on 13.09.16.
//

#include <fstream>
#include <sstream>
#include <limits>
#include "ObjectManager.h"

ObjectManager::ObjectManager(string objects_path, string sprites_path)
{
    // Parsing objects
    ifstream objects_ifs(objects_path);
    if (!objects_ifs.is_open()) {
        cerr << "Can't open file: " << objects_path << endl;
        throw runtime_error("Can't open file: " + objects_path);
    }

    objects_ifs.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip first line

    string line;
    while (getline(objects_ifs, line)) {
        string token;
        istringstream iss(line);

        int Key, Sprite, Depth, ParentObject, MaskSprite;
        string ObjectName;
        bool Solid, Visible, Persistent;

        getline(iss, token, ',');
        Key = stoi(token);

        getline(iss, ObjectName, ',');

        getline(iss, token, ',');
        Sprite = stoi(token);

        getline(iss, token, ',');
        Depth = stoi(token);

        getline(iss, token, ',');
        ParentObject = stoi(token);

        getline(iss, token, ',');
        MaskSprite = stoi(token);

        getline(iss, token, ',');
        Solid = token == "True";

        getline(iss, token, ',');
        Visible = token == "True";

        getline(iss, token);
        Persistent = token == "True";

        _objects[Key] = new Object(
            Key, ObjectName, Sprite, Depth, ParentObject, MaskSprite, Solid, Visible, Persistent
        );
    }

    objects_ifs.close();

    // Parsing sprites
    ifstream sprites_ifs(sprites_path);
    if (!sprites_ifs.is_open()) {
        cerr << "Can't open file: " << sprites_path << endl;
        throw runtime_error("Can't open file: " + sprites_path);
    }

    sprites_ifs.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip first line

    while (getline(sprites_ifs, line)) {
        string token;
        istringstream iss(line);

        int Key, Width, Height, NumFrames;
        string SpritePath;

        getline(iss, token, ',');
        Key = stoi(token);

        getline(iss, SpritePath, ',');

        getline(iss, token, ',');
        Width = stoi(token);

        getline(iss, token, ',');
        Height = stoi(token);

        getline(iss, token, ',');
        NumFrames = stoi(token);

        _sprites[Key] = new Sprite(
            Key, SpritePath, Width, Height, NumFrames
        );
    }

    sprites_ifs.close();
}

ObjectManager::ObjectManager(string objects_path, string sprites_path, string tiles_path, string walls_path)
    : ObjectManager(objects_path, sprites_path)
{
    // Parsing Tiles
    ifstream tiles_ifs(tiles_path);
    if (!tiles_ifs.is_open()) {
        cerr << "Can't open file: " << objects_path << endl;
        throw runtime_error("Can't open file: " + objects_path);
    }

    tiles_ifs.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip first line

    string line;
    while (getline(tiles_ifs, line)) {
        string token;
        istringstream iss(line);

        int key, property;
        string tileName;

        getline(iss, token, ',');
        key = stoi(token);

        getline(iss, token, ',');
        property = stoi(token);

        getline(iss, tileName, ',');

        _tiles[key] = new Tile(key, property, tileName);
    }

    tiles_ifs.close();

    // Parsing Walls
    ifstream walls_ifs(walls_path);
    if (!walls_ifs.is_open()) {
        cerr << "Can't open file: " << objects_path << endl;
        throw runtime_error("Can't open file: " + objects_path);
    }

    walls_ifs.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip first line

    while (getline(walls_ifs, line)) {
        string token;
        istringstream iss(line);

        int key, property1, property2;
        string tileName;

        getline(iss, token, ',');
        key = stoi(token);

        getline(iss, token, ',');
        property1 = stoi(token);

        getline(iss, token, ',');
        property2 = stoi(token);

        getline(iss, tileName, ',');

        _walls[key] = new Wall(key, property1, property2, tileName);
    }
    walls_ifs.close();
}

ObjectManager::~ObjectManager()
{
    for (map<int, Object *>::iterator it = _objects.begin(); it != _objects.end(); ++it)
        delete it->second;
    _objects.clear();

    for (map<int, Sprite *>::iterator it = _sprites.begin(); it != _sprites.end(); ++it)
        delete it->second;
    _sprites.clear();

    for (auto it = _walls.begin(); it != _walls.end(); ++it)
        delete it->second;
    _walls.clear();

    for (auto it = _tiles.begin(); it != _tiles.end(); ++it)
        delete it->second;
    _tiles.clear();
}

/**
 * Lookup for an object and its sprite
 * @param objKey - key of the object
 * @return <b>std::pair&lt;Object*, Sprite*&gt;</b> - pointers or nullptrs if not found
 */
pair<Object *, Sprite *> ObjectManager::get(int objKey)
{
    pair<Object *, Sprite *> p(nullptr, nullptr);

    auto obj_it = _objects.find(objKey);
    if (obj_it != _objects.end()) {
        p.first = obj_it->second;
        p.second = getSprite(p.first->Sprite());
    }

    return p;
}

Sprite *ObjectManager::getSprite(int spriteKey)
{
    auto spr_it = _sprites.find(spriteKey);
    if (spr_it != _sprites.end())
        return spr_it->second;
    return nullptr;
}

Tile *ObjectManager::getTile(int tileKey)
{
    auto tile_it = _tiles.find(tileKey);
    if (tile_it != _tiles.end())
        return tile_it->second;
    return nullptr;
}

Wall *ObjectManager::getWall(int wallKey)
{
    auto wall_it = _walls.find(wallKey);
    if (wall_it != _walls.end())
        return wall_it->second;
    return nullptr;
}
