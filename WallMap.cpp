//
// Created by asp437 on 13.09.16.
//

#include "WallMap.h"

#include <fstream>

WallMap::WallMap(string filename)
{
    ifstream ifs(filename);
    string line;
    if (!ifs.is_open()) {
        // TODO: Throw exception
        cerr << "Can't open file" << endl;
        return;
    }

    while (!ifs.eof()) {
        Wall wall;

        getline(ifs, line);
        if (line == "")
            break;
        wall.id = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        wall.x = stoi(line);
        getline(ifs, line);
        if (line == "")
            break;
        wall.y = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        wall.attribute = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        wall.magic = stoi(line);

        wallMap.push_back(wall);
    }

    ifs.close();
}
