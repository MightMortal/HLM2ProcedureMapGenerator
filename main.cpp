#include <iostream>
#include <QApplication>
#include <ctime>

#include "MapEditor/GUI/mainwindow.h"
#include "MapEditor/LevelDescriptors/LevelMetaInformation.h"
#include "MapEditor/LevelDescriptors/TileMap.h"
#include "MapEditor/LevelDescriptors/WallMap.h"
#include "MapEditor/LevelDescriptors/ObjectMap.h"
#include "MapEditor/Assets/ObjectManager.h"
#include "MapEditor/Assets/Atlas.h"
#include "MapEditor/LevelDescriptors/PlayMap.h"
#include "Generator/Interior/Building.h"

const int LEVEL_MAX_WIDTH = 1088;
const int LEVEL_MAX_HEIGHT = 768;

WallMap bsp_test() {
    srand(time(0));
    Building building(Rectangle(Point(0, 0), Point(LEVEL_MAX_WIDTH * (2.0 / 3.0), LEVEL_MAX_HEIGHT * (2.0 / 3.0))));
    for (auto it = building.rooms->begin(); it != building.rooms->end(); ++it) {
        cout << "Type: " << it->type << endl;
        cout << "LeftUpper: (" << it->rect.first.x << ", " << it->rect.first.y << "), RightBottom: ("
             << it->rect.second.x << ", " << it->rect.second.y << ")" << endl;
    }
    for (auto it = building.walls.begin(); it != building.walls.end(); ++it) {
        cout << "Wall from (" << it->first.x << ", " << it->first.y << ") to ("
             << it->second.x << ", " << it->second.y << ")" << endl;
    }
    return building.generateWallMap();
}

int main(int argc, char *argv[]) {
    WallMap wallMap = bsp_test();
    wallMap.save("test.wll");
    ObjectManager om(OBJECTS_PATH, SPRITES_PATH, TILES_PATH, WALLS_PATH);
    SpritesIndex::init(".");
    SpritesIndex::check(om);

    // Level level("test_level");

    QApplication a(argc, argv);
    MainWindow window(om);

    window.fillColor(0, 0, 1088, 768, 0xFFFFFFFF);

    // window.renderLevel(level);
//    window.renderLevel(Level())
    window.renderWalls(wallMap.walls);

    window.show();

    return a.exec();
}