#include <iostream>
#include <QApplication>

#include "MapEditor/GUI/mainwindow.h"
#include "MapEditor/LevelDescriptors/Level.h"
#include "MapEditor/LevelDescriptors/TileMap.h"
#include "MapEditor/LevelDescriptors/WallMap.h"
#include "MapEditor/LevelDescriptors/ObjectMap.h"
#include "MapEditor/Assets/ObjectManager.h"
#include "MapEditor/Assets/Atlas.h"
#include "MapEditor/LevelDescriptors/PlayMap.h"

int main(int argc, char *argv[])
{
    ObjectManager om(OBJECTS_PATH, SPRITES_PATH, TILES_PATH, WALLS_PATH);
    SpritesIndex::init(".");
    SpritesIndex::check(om);

//    ObjectMap objectsMap("test_level/level0.obj");
    PlayMap playMap("test_level/level0.play");
    WallMap wallMap("test_level/level0.wll");
    TileMap tileMap("test_level/level0.tls");

    QApplication a(argc, argv);
    MainWindow window;

    window.fillColor(0, 0, 1088, 768, 0xFFFFFFFF);
    int tx, ty, w, h;

    for (auto editorObject : playMap.objects) {
        Sprite *sprite = om.get(editorObject.id).second;
        if (sprite == nullptr) {
            cout << "Object <" << editorObject.id << "> doesn't have sprite" << endl;
            sprite = om.getSprite(editorObject.spriteId);
        }
        if (sprite != nullptr) {
            string spriteName = sprite->SpritePath().substr(sprite->SpritePath().find_last_of('/') + 1);
            string atlasPath = SpritesIndex::getSpritePath(spriteName);
            string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
            Atlas atlas(atlasPath);
            tx = atlas.sprites[spriteName]->frames.at(0)->getOffsetX();
            ty = atlas.sprites[spriteName]->frames.at(0)->getOffsetY();
            w = atlas.sprites[spriteName]->frames.at(0)->getWidth();
            h = atlas.sprites[spriteName]->frames.at(0)->getHeight();
            window.renderSprite(spritePath + ".png", editorObject.x, editorObject.y, tx, ty, w, h);
        }
    }
    for (auto editorWall : wallMap.walls) {
        Wall *wall = om.getWall(editorWall.id);
        string spriteName = wall->getName().substr(wall->getName().find_last_of('/') + 1);
        string atlasPath = SpritesIndex::getSpritePath(spriteName);
        string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
        Atlas atlas(atlasPath);
        tx = atlas.sprites[spriteName]->frames.at(0)->getOffsetX();
        ty = atlas.sprites[spriteName]->frames.at(0)->getOffsetY();
        w = atlas.sprites[spriteName]->frames.at(0)->getWidth();
        h = atlas.sprites[spriteName]->frames.at(0)->getHeight();
        window.renderSprite(spritePath + ".png", editorWall.x, editorWall.y, tx, ty, w, h);
    }
    for (auto editorTile : tileMap.tiles) {
        Tile *tile = om.getTile(editorTile.id);
        string spriteName = tile->getName().substr(tile->getName().find_last_of('/') + 1);
        string atlasPath = SpritesIndex::getSpritePath(tile->getName());
        string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
        Atlas atlas(atlasPath);
        tx = atlas.sprites[tile->getName()]->frames.at(0)->getOffsetX() + editorTile.textureX;
        ty = atlas.sprites[tile->getName()]->frames.at(0)->getOffsetY() + editorTile.textureY;
        if (editorTile.id == 10)
            w = h = 8;
        else
            w = h = 16;
        window.renderSprite(spritePath + ".png", editorTile.x, editorTile.y, tx, ty, w, h);
    }

    window.show();

    return a.exec();
//    return 0;
}