//
// Created by asp437 on 13.09.16.
//

#include "ObjectsMap.h"

#include <fstream>

ObjectsMap::ObjectsMap(string filename)
{
    ifstream ifs(filename);
    string line;
    if (!ifs.is_open()) {
        // TODO: Throw exception
        cerr << "Can't open file" << endl;
        return;
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
        object.behaviorId= stoi(line);

        getline(ifs, line);
        if (line == "")
            break;
        object.magic = stoi(line);

        objectsMap.push_back(object);
    }

    ifs.close();
}
