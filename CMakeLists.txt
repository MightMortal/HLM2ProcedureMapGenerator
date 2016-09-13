cmake_minimum_required(VERSION 3.6)
project(HLM2ProcedureMapGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MapEditor/AssetDescriptors/Level.cpp MapEditor/AssetDescriptors/Level.h MapEditor/AssetDescriptors/TilesMap.cpp MapEditor/AssetDescriptors/TilesMap.h common.h MapEditor/AssetDescriptors/WallMap.cpp MapEditor/AssetDescriptors/WallMap.h MapEditor/AssetDescriptors/ObjectsMap.cpp MapEditor/AssetDescriptors/ObjectsMap.h)
add_executable(HLM2ProcedureMapGenerator ${SOURCE_FILES})