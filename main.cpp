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

Level bsp_test() {
    srand(time(0));
    int width = LEVEL_MAX_WIDTH;
    int height = (int) (LEVEL_MAX_HEIGHT * (2.5 / 3.0));
    Building building(Rectangle(Point(0, 0), Point(width, height)));
    building.generateDoors();
    for (auto it = building.rooms->begin(); it != building.rooms->end(); ++it) {
        cout << "Type: " << it->type << endl;
        cout << "LeftUpper: (" << it->rect.first.x << ", " << it->rect.first.y << "), RightBottom: ("
             << it->rect.second.x << ", " << it->rect.second.y << ")" << endl;
    }
    for (auto it = building.walls.begin(); it != building.walls.end(); ++it) {
        cout << "Wall from (" << it->first.x << ", " << it->first.y << ") to ("
             << it->second.x << ", " << it->second.y << ")" << endl;
    }
    Level level;
    level.wallMaps.push_back(building.generateWallMap());
    level.tileMaps.push_back(building.generateTileMap());
    return level;
}

int main(int argc, char *argv[]) {
    Level level = bsp_test();
    level.wallMaps[0].save("level0.wll");
    level.tileMaps[0].save("level0.tls");
    ObjectManager om(OBJECTS_PATH, SPRITES_PATH, TILES_PATH, WALLS_PATH);
    SpritesIndex::init(".");
    SpritesIndex::check(om);

    // Level level("test_level");

    QApplication a(argc, argv);
    MainWindow window(om);

    window.fillColor(0, 0, 1088, 768, 0xFFFFFFFF);

    // window.renderLevel(level);
//    window.renderLevel(Level())
    window.renderTiles(level.tileMaps[0].tiles);
    window.renderWalls(level.wallMaps[0].walls);

    window.show();

    return a.exec();
}