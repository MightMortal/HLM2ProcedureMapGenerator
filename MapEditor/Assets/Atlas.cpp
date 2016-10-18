//
// Created by asp437 on 14.09.16.
//

#include "Atlas.h"

#include <fstream>
#include <cstring>
#include <QDir>
#include <QFile>

map<string, string> SpritesIndex::index;

SpriteFrame::SpriteFrame(AtlasSprite &atlasSprite, ifstream &ifs)
    : atlasSprite(atlasSprite) {
    uint32_t inputInteger;

    ifs.read((char *) &inputInteger, sizeof(inputInteger));
    width = inputInteger;
    ifs.read((char *) &inputInteger, sizeof(inputInteger));
    height = inputInteger;

    ifs.read((char *) &offsetX, sizeof(offsetX));
    ifs.read((char *) &offsetY, sizeof(offsetY));
    ifs.read((char *) &uStart, sizeof(uStart));
    ifs.read((char *) &vStart, sizeof(vStart));
    ifs.read((char *) &uEnd, sizeof(uEnd));
    ifs.read((char *) &vEnd, sizeof(vEnd));
}

ostream &operator<<(ostream &os, const SpriteFrame &frame) {
    os << "Frame{offsetX: " << frame.offsetX << " offsetY: " << frame.offsetY << " width: " << frame.width
       << " height: "
       << frame.height << " uStart: " << frame.uStart << " vStart: " << frame.vStart << " uEnd: " << frame.uEnd
       << " vEnd: " << frame.vEnd << "}";
    return os;
}

AtlasSprite::AtlasSprite(Atlas &atlas, ifstream &ifs)
    : atlas(atlas) {
    uint8_t nameLength;
    ifs.read((char *) &nameLength, sizeof(nameLength));
    if (ifs.eof())
        return;

    char nameBuffer[nameLength + 1];
    ifs.read(nameBuffer, nameLength);
    nameBuffer[nameLength] = '\0';
    name = string(nameBuffer);

    uint32_t frameCount;
    ifs.read((char *) &frameCount, sizeof(frameCount));
    for (int i = 0; i < frameCount; i++) {
        if (atlas.getVersion())
            ifs.seekg(4, ios_base::cur);
        frames.push_back(new SpriteFrame(*this, ifs));
    }

}

ostream &operator<<(ostream &os, const AtlasSprite &sprite) {
    os << "AtlasSprite{name: " << sprite.name;
    for (auto it:sprite.frames) {
        os << endl << "\t" << *it;
    }
    os << endl << "}";
    return os;
}

Atlas::Atlas(string filename)
    : path(filename) {

#if defined (__MINGW32__) || defined (_WIN32)
    size_t position = 0;
    while ((position = path.find('/', position)) != string::npos) {
        path.replace(position, 1, "\\");
    }
#endif

    ifstream ifs(filename, ios_base::binary | ios_base::in);
    if (!ifs.is_open()) {
        cerr << "Can't open atlas file " << filename << endl;
        throw runtime_error("Can't open atlas file " + filename);
    }

    int8_t idLen; // one byte integer
    ifs.read((char *) &idLen, sizeof(idLen));

    char magic[idLen];
    ifs.read(magic, sizeof(magic));
    if (idLen != 0xF || strcmp(magic, "AGTEXTUREPACKER") != 0) {
        cerr << "Invalid atlas file " << filename << endl;
        ifs.close();
        throw runtime_error("Invalid atlas file " + filename);
    }

    uint32_t tmpVersion;
    ifs.read((char *) &tmpVersion, sizeof(tmpVersion));
    version = tmpVersion;
    if (version >= 2) {
        ifs.seekg(4, ios_base::cur);
    } else {
        uint32_t tmpWidth, tmpHeight;
        ifs.read((char *) &tmpWidth, sizeof(tmpWidth));
        width = tmpWidth;
        ifs.read((char *) &tmpHeight, sizeof(tmpHeight));
        height = tmpHeight;
    }

    while (!ifs.eof()) {
        AtlasSprite *sprite = new AtlasSprite(*this, ifs);
        if (!ifs.eof())
            sprites[sprite->getName()] = sprite;
    }

    ifs.close();
}

ostream &operator<<(ostream &os, const Atlas &atlas) {
    os << "Atlas{path: " << atlas.path << " version: " << atlas.version << " width: " << atlas.width << " height: "
       << atlas.height;
    for (auto it:atlas.sprites) {
        os << endl << *it.second;
    }
    os << "}";
    return os;
}

void SpritesIndex::init(string path) {
    QDir dir(QString(path.c_str()));
    QFileInfoList fileInfoList = dir.entryInfoList();
    for (auto it = fileInfoList.begin(); it != fileInfoList.end(); ++it) {
        if (it->isDir() && !it->fileName().startsWith(".")) {
            init(it->absoluteFilePath().toStdString());
        } else if (it->isFile() && it->fileName().endsWith(".meta")) {
            Atlas atlas(path + "/" + it->fileName().toStdString());
            for (auto sprite:atlas.sprites) {
                if (index.find(sprite.first) != index.end()) {
                    cerr << "Few atlases with sprite " << sprite.first << ", old path " << index[sprite.first]
                         << ", new path " << path << "/" << it->fileName().toStdString() << endl;
                }
                index[sprite.first] = path + "/" + it->fileName().toStdString();
            }
        }
    }
}

bool SpritesIndex::check(ObjectManager &om) {
    bool result = false;
    for (int i = 0; i < MAX_SPRITE_ID; i++) {
        Sprite *sprite = om.getSprite(i);
        if (sprite != nullptr) {
            string spriteName = sprite->SpritePath().substr(sprite->SpritePath().find_last_of('/') + 1);
            if (index.find(spriteName) == index.end()) {
                cerr << "Can't find path for sprite " << spriteName << endl;
                result = true;
            }
        }
    }
    return result;
}

string SpritesIndex::getSpritePath(string spriteName) {
    if (index.find(spriteName) != index.end())
        return index[spriteName];
    else
        return "";
}
