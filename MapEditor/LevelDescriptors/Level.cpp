//
// Created by asp437 on 13.09.16.
//

#include "Level.h"

#include <fstream>
#include <iostream>

Level::Level()
    : _magic1(9999), _magic2(9999)
{

}

Level::Level(string filename)
{
    string line;
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "Can't open file" << filename << endl;
        throw runtime_error("Can't open open file " + filename);
    }

    getline(ifs, _name);

    getline(ifs, line);
    _magic1 = stoi(line);

    getline(ifs, _authorName);

    getline(ifs, line);
    _magic2 = stoi(line);


    getline(ifs, line);
    _sRankScore = stoi(line);
    getline(ifs, line);
    _playerId = stoi(line);

    getline(ifs, line);
    _magic3 = stoi(line);
    getline(ifs, line);
    _magic4 = stoi(line);

    getline(ifs, line);
    _musicId = stoi(line);

    getline(ifs, line);
    _leftCornerX = stoi(line);
    getline(ifs, line);
    _leftCornerY = stoi(line);
    getline(ifs, line);
    _width = stoi(line);
    getline(ifs, line);
    _height = stoi(line);


    getline(ifs, line);
    _magic5 = stoi(line);
    getline(ifs, line);
    _magic6 = stoi(line);


    getline(ifs, line);
    hours = stoi(line);
    getline(ifs, line);
    minutes = stoi(line);
    getline(ifs, line);
    day = stoi(line);
    getline(ifs, line);
    month = stoi(line);
    getline(ifs, line);
    year = stoi(line);

    getline(ifs, _cityName);
    getline(ifs, _stateName);
    getline(ifs, _address);


    getline(ifs, line);
    _magic7 = stoi(line);
    getline(ifs, line);
    _magic8 = stoi(line);
    getline(ifs, line);
    _magic9 = stoi(line);

    ifs.close();
}
