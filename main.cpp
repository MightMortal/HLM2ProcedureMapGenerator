#include <iostream>
#include <QApplication>
#include <set>

#include "MapEditor/GUI/mainwindow.h"
#include "MapEditor/LevelDescriptors/Level.h"
#include "MapEditor/LevelDescriptors/TilesMap.h"
#include "MapEditor/LevelDescriptors/WallMap.h"
#include "MapEditor/LevelDescriptors/ObjectMap.h"
#include "MapEditor/Assets/ObjectManager.h"
#include "MapEditor/Assets/Atlas.h"

int main(int argc, char *argv[])
{
    ObjectManager om(objects_path, sprites_path);
    SpritesIndex::init(".");
    SpritesIndex::check(om);

    ObjectMap objectsMap("test_level/level0.obj");

    QApplication a(argc, argv);
    MainWindow window;

    for (auto editorObject : objectsMap.objects) {
        Sprite *sprite = om.get(editorObject.id).second;
        if (sprite == nullptr) {
            cout << "Object <" << editorObject.id << "> doesn't have sprite" << endl;
            sprite = om.getSprite(editorObject.spriteId);
        }
        if (sprite != nullptr) {
            int tx, ty, w, h;
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

    window.show();

    return a.exec();
//    return 0;
}