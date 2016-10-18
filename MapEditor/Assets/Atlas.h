//
// Created by asp437 on 14.09.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_ATLAS_H
#define HLM2PROCEDUREMAPGENERATOR_ATLAS_H

#include <map>
#include <ostream>

#include "ObjectManager.h"
#include "../../common.h"

class Atlas;
class AtlasSprite;

class SpriteFrame {
public:
    SpriteFrame(AtlasSprite &atlasSprite, ifstream &ifs);

    AtlasSprite &getAtlasSprite() const { return atlasSprite; }

    int getOffsetX() const { return offsetX; }

    int getOffsetY() const { return offsetY; }

    int getWidth() const { return width; }

    int getHeight() const { return height; }

    double getUStart() const { return uStart; }

    double getVStart() const { return vStart; }

    double getUEnd() const { return uEnd; }

    double getVEnd() const { return vEnd; }

    friend ostream &operator<<(ostream &os, const SpriteFrame &frame);
private:
    AtlasSprite &atlasSprite;
    int offsetX;
    int offsetY;
    int width;
    int height;
    float uStart;
    float vStart;
    float uEnd;
    float vEnd;
};

class AtlasSprite {
public:
    AtlasSprite(Atlas &atlas, ifstream &ifs);

    Atlas &getAtlas() const { return atlas; }

    const string &getName() const { return name; }

    friend ostream &operator<<(ostream &os, const AtlasSprite &sprite);

    vector<SpriteFrame *> frames;
private:
    Atlas &atlas;
    string name;
};

class Atlas {
public:
    Atlas(string filename);

    const string &getPath() const { return path; }

    unsigned int getWidth() const { return width; }

    unsigned int getHeight() const { return height; }

    unsigned int getVersion() const { return version; }

    friend ostream &operator<<(ostream &os, const Atlas &atlas);

    map<string, AtlasSprite *> sprites;
private:
    string path;
    unsigned int version;
    unsigned int width;
    unsigned int height;
};

class SpritesIndex {
public:
    static void init(string path);
    static bool check(ObjectManager &om);
    static string getSpritePath(string spriteName);
private:
    static const int MAX_SPRITE_ID = 4500;
    static map<string, string> index;
};

#endif //HLM2PROCEDUREMAPGENERATOR_ATLAS_H
