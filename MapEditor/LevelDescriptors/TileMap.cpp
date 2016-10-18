//
// Created by asp437 on 13.09.16.
//

#include "TileMap.h"

#include <fstream>

TileMap::TileMap() {

}

TileMap::TileMap(std::string filename) {
    ifstream ifs(filename);
    string line;
    if (!ifs.is_open()) {
        cerr << "Can't open file" << filename << endl;
        throw runtime_error("Can't open file " + filename);
    }

    while (!ifs.eof()) {
        EditorTile tile;

        getline(ifs, line);
        if (line == "")
            break;
        tile.id = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        tile.textureX = stoi(line);
        getline(ifs, line);
        if (line == "")
            break;
        tile.textureY = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        tile.x = stoi(line);
        getline(ifs, line);
        if (line == "")
            break;
        tile.y = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        tile.attribute = stoi(line);

        tiles.push_back(tile);
    }

    ifs.close();
}
