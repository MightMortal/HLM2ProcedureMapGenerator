//
// Created by asp437 on 13.09.16.
//

#include "ObjectMap.h"

#include <fstream>

ObjectMap::ObjectMap(string filename) {
    ifstream ifs(filename);
    string line;
    if (!ifs.is_open()) {
        cerr << "Can't open file" << filename << endl;
        throw runtime_error("Can't open file " + filename);
    }

    while (!ifs.eof()) {
        EditorObject object;

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
        object.behaviorId = stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        object.magic = stoi(line);

        objects.push_back(object);
    }

    ifs.close();
}
