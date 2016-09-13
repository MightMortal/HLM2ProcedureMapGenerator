cmake_minimum_required(VERSION 3.6)
project(HLM2ProcedureMapGenerator)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp common.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/Assets/Object.cpp MapEditor/Assets/Object.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/Assets/ObjectManager.cpp MapEditor/Assets/ObjectManager.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/Assets/Sprite.cpp MapEditor/Assets/Sprite.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/GUI/moc_mainwindow.cpp MapEditor/GUI/moc_qstringitemmodel.cpp)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/GUI/mainwindow.cpp MapEditor/GUI/mainwindow.h MapEditor/GUI/ui_mainwindow.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/GUI/qstringitemmodel.cpp MapEditor/GUI/qstringitemmodel.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/LevelDescriptors/Level.cpp MapEditor/LevelDescriptors/Level.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/LevelDescriptors/TilesMap.cpp MapEditor/LevelDescriptors/TilesMap.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/LevelDescriptors/WallMap.cpp MapEditor/LevelDescriptors/WallMap.h)
set(SOURCE_FILES ${SOURCE_FILES} MapEditor/LevelDescriptors/ObjectsMap.cpp MapEditor/LevelDescriptors/ObjectsMap.h)

add_executable(HLM2ProcedureMapGenerator ${SOURCE_FILES})

qt5_use_modules(HLM2ProcedureMapGenerator Core Widgets Gui)