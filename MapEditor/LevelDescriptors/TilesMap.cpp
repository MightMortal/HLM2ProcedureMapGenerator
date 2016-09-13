//
// Created by asp437 on 13.09.16.
//

#include "TilesMap.h"

#include <fstream>

TilesMap::TilesMap()
{

}

TilesMap::TilesMap(std::string filename)
{
    ifstream ifs(filename);
    string line;
    if (!ifs.is_open()) {
        // TODO: Throw exception
        cerr << "Can't open file" << endl;
        return;
    }

    while (!ifs.eof()) {
        Tile tile;

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

        map.push_back(tile);
    }

    ifs.close();
}
