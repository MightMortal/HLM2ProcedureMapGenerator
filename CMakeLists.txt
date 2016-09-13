cmake_minimum_required(VERSION 3.6)
project(HLM2ProcedureMapGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Level.cpp Level.h TilesMap.cpp TilesMap.h common.h WallMap.cpp WallMap.h ObjectsMap.cpp ObjectsMap.h)
add_executable(HLM2ProcedureMapGenerator ${SOURCE_FILES})