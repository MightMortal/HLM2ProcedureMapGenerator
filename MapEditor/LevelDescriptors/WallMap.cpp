//
// Created by asp437 on 13.09.16.
//

#include "WallMap.h"

#include <fstream>

WallMap::WallMap(string filename) {
    ifstream ifs(filename);
    string line;
    if (!ifs.is_open()) {
        cerr << "Can't open file" << filename << endl;
        throw runtime_error("Can't open file " + filename);
    }

    while (!ifs.eof()) {
        EditorWall wall;

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

        walls.push_back(wall);
    }

    ifs.close();
}

void WallMap::save(string filename) {
    ofstream ofs(filename);
    if (!ofs.is_open()) {
        cerr << "Can't open file" << filename << endl;
        throw runtime_error("Can't open file " + filename);
    }

    for (auto it = walls.begin(); it != walls.end(); ++it) {
        ofs << it->id << endl;
        ofs << it->x << endl;
        ofs << it->y << endl;
        ofs << it->attribute << endl;
        ofs << it->magic << endl;
    }

    ofs.flush();
    ofs.close();
}
