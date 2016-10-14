//
// Created by Aleksandr Parfenov on 20.09.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_WALL_H
#define HLM2PROCEDUREMAPGENERATOR_WALL_H

#include <ostream>
#include "../../common.h"

class Wall
{
public:
    Wall(int id, int property, int property2, const string &name);

    int getId() const
    { return _id; }

    int getProperty() const
    { return _property; }

    int getProperty2() const
    { return _property2; }

    const string &getName() const
    { return _name; }

    friend ostream &operator<<(ostream &os, const Wall &wall);
private:
    int _id;
    int _property;
    int _property2;
    string _name;
};

#endif //HLM2PROCEDUREMAPGENERATOR_WALL_H
