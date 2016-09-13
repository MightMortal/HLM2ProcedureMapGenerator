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

    for (int i = 0; i < 10; ++i) {
        cout << om.objects[i].get()->ObjectName() << endl;
        int key = om.objects[i].get()->Sprite();
        if (key != -1)
            cout << om.spriteMap[key].get()->SpritePath() << endl;
        cout << endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}