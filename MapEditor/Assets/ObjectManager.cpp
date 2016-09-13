//
// Created by Timofey Lysenko on 13.09.16.
//

#include <fstream>
#include <sstream>
#include <limits>
#include "ObjectManager.h"

ObjectManager::ObjectManager(string objects_path, string sprites_path)
{
    ifstream objects_ifs(objects_path);
    ifstream sprites_ifs(sprites_path);

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

        objects.push_back(unique_ptr<Object>(new Object(
            Key, ObjectName, Sprite, Depth, ParentObject, MaskSprite, Solid, Visible, Persistent
        )));
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

//        spriteMap.insert(pair<int, Sprite>(Key, Sprite(
//            Key, SpritePath, Width, Height, NumFrames
//        )));
        spriteMap[Key] = unique_ptr<Sprite>(new Sprite(
            Key, SpritePath, Width, Height, NumFrames
        ));
    }

    objects_ifs.close();
    sprites_ifs.close();
}

ObjectManager::~ObjectManager()
{
    for (auto &ptr : objects)
        ptr.reset();

    for (auto &entry : spriteMap)
        entry.second.reset();
}
