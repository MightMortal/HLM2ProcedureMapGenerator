//
// Created by Aleksandr Parfenov on 18.09.16.
//
#include "PlayMap.h"

#include <fstream>

PlayMap::PlayMap(string filename) {
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

void PlayMap::save(string filename) {
    ofstream ofs(filename);
    if (!ofs.is_open()) {
        cerr << "Can't open file" << filename << endl;
        throw runtime_error("Can't open file " + filename);
    }
    ofs << magic1 << endl;
    ofs << magic2 << endl;

    for (auto it = objects.begin(); it != objects.end(); ++it) {
        ofs << it->id << endl;
        ofs << it->x << endl;
        ofs << it->y << endl;
        ofs << it->spriteId << endl;
        ofs << it->angle << endl;
        ofs << it->magic << endl;
    }

    ofs.flush();
    ofs.close();
}