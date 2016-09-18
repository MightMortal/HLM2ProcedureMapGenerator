//
// Created by Aleksandr Parfenov on 18.09.16.
//
#include "PlayMap.h"

#include <fstream>


PlayMap::PlayMap(string filename)
{
    ifstream ifs(filename);
    string line;
    if (!ifs.is_open()) {
        cerr << "Can't open file" << filename << endl;
        throw runtime_error("Can't open file " + filename);
    }

    getline(ifs, line);
    magic1 = stoi(line);
    getline(ifs, line);
    magic2 = stoi(line);

    while (!ifs.eof()) {
        PlayObject object;

        getline(ifs, line);
        if (line == "")
            break;
        object.id = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        object.x = stoi(line);
        getline(ifs, line);
        if (line == "")
            break;
        object.y = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        object.spriteId = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        object.angle = stod(line);

        getline(ifs, line);
        if (line == "")
            break;
        object.magic = stoi(line);

        objects.push_back(object);
    }

    ifs.close();
}
