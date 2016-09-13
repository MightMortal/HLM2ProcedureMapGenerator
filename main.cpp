#include <iostream>

#include "MapEditor/AssetDescriptors/Level.h"
#include "MapEditor/AssetDescriptors/TilesMap.h"
#include "MapEditor/AssetDescriptors/WallMap.h"
#include "MapEditor/AssetDescriptors/ObjectsMap.h"

int main() {
    Level lv("test_level/level.hlm");
    TilesMap tls("test_level/level0.tls");
    WallMap wll("test_level/level0.wll");
    ObjectsMap obj("test_level/level0.obj");

    return 0;
}