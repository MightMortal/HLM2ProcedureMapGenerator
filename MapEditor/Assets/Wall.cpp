//
// Created by Aleksandr Parfenov on 20.09.16.
//

#include "Wall.h"
Wall::Wall(int id, int property, int property2, const string &name)
    : _id(id), _property(property), _property2(property2), _name(name)
{
}

ostream &operator<<(ostream &os, const Wall &wall)
{
    os << "Wall{Id: " << wall._id << " Property: " << wall._property << " Property2: " << wall._property2 << " Name: "
       << wall._name << "}";
    return os;
}
