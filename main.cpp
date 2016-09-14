#include <iostream>
#include <QApplication>

#include "MapEditor/GUI/mainwindow.h"
#include "MapEditor/LevelDescriptors/Level.h"
#include "MapEditor/LevelDescriptors/TilesMap.h"
#include "MapEditor/LevelDescriptors/WallMap.h"
#include "MapEditor/LevelDescriptors/ObjectsMap.h"
#include "MapEditor/Assets/ObjectManager.h"

int main(int argc, char *argv[])
{
    ObjectManager om(objects_path, sprites_path);

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
    return 0;
}