//
// Created by asp437 on 13.09.16.
//

#ifndef HLM_LEVEL_READER_LEVEL_H
#define HLM_LEVEL_READER_LEVEL_H
#include "../../common.h"

class LevelMetaInformation {
public:
    LevelMetaInformation();
    LevelMetaInformation(string filename);

    string _name;

    int _floorNumber; // Counted from 0

    string _authorName;

    int _magic2; // 0

    int _sRankScore;
    int _playerId;

    int _magic3; // 1
    int _magic4; // -1

    int _musicId;

    int _leftCornerX;
    int _leftCornerY;
    int _width;
    int _height;

    int _magic5; // 974
    int _magic6; // 0

    int hours;
    int minutes;
    int day;
    int month;
    int year;

    string _cityName;
    string _stateName;
    string _address;

    int _magic7; // 0
    int _magic8; // 9999
    int _magic9; // 9999
private:
};

#endif //HLM_LEVEL_READER_LEVEL_H
