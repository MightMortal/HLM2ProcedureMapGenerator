//
// Created by Aleksandr Parfenov on 20.09.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_TILE_H
#define HLM2PROCEDUREMAPGENERATOR_TILE_H

#include <ostream>
#include "../../common.h"

class Tile
{
public:
    Tile(int _id, int _property, const string &_name);

    int getId() const
    { return _id; }

    int getProperty() const
    { return _property; }

    const string &getName() const
    { return _name; }

    friend ostream &operator<<(ostream &os, const Tile &tile);
private:
    int _id;
    int _property;
    string _name;
};


#endif //HLM2PROCEDUREMAPGENERATOR_TILE_H
