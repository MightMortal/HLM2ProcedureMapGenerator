cmake_minimum_required(VERSION 3.6)
project(HLM2ProcedureMapGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MapEditor/LevelDescriptors/Level.cpp MapEditor/LevelDescriptors/Level.h MapEditor/LevelDescriptors/TilesMap.cpp MapEditor/LevelDescriptors/TilesMap.h common.h MapEditor/LevelDescriptors/WallMap.cpp MapEditor/LevelDescriptors/WallMap.h MapEditor/LevelDescriptors/ObjectsMap.cpp MapEditor/LevelDescriptors/ObjectsMap.h MapEditor/Assets/Object.cpp MapEditor/Assets/Object.h MapEditor/Assets/Sprite.cpp MapEditor/Assets/Sprite.h MapEditor/Assets/ObjectManager.cpp MapEditor/Assets/ObjectManager.h)
add_executable(HLM2ProcedureMapGenerator ${SOURCE_FILES})