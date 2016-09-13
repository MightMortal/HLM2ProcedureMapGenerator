#include <iostream>

#include "MapEditor/Assets/ObjectManager.h"

int main()
{
    ObjectManager om(objects_path, sprites_path);

    for (int i = 0; i < 10; ++i) {
        cout << om.objects[i].get()->ObjectName() << endl;
        int key = om.objects[i].get()->Sprite();
        if (key != -1)
            cout << om.spriteMap[key].get()->SpritePath() << endl;
        cout << endl;
    }

    return 0;
}