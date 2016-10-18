#include <iostream>
#include <QApplication>

#include "MapEditor/GUI/mainwindow.h"
#include "MapEditor/LevelDescriptors/LevelMetaInformation.h"
#include "MapEditor/LevelDescriptors/TileMap.h"
#include "MapEditor/LevelDescriptors/WallMap.h"
#include "MapEditor/LevelDescriptors/ObjectMap.h"
#include "MapEditor/Assets/ObjectManager.h"
#include "MapEditor/Assets/Atlas.h"
#include "MapEditor/LevelDescriptors/PlayMap.h"

int main(int argc, char *argv[]) {
    ObjectManager om(OBJECTS_PATH, SPRITES_PATH, TILES_PATH, WALLS_PATH);
    SpritesIndex::init(".");
    SpritesIndex::check(om);

    // Level level("test_level");

    QApplication a(argc, argv);
    MainWindow window(om);

    window.fillColor(0, 0, 1088, 768, 0xFFFFFFFF);

    // window.renderLevel(level);

    window.show();

    return a.exec();
}