//
// Created by Aleksandr Parfenov on 20.09.16.
//

#include "Tile.h"
Tile::Tile(int id, int property, const string &name)
    : _id(id), _property(property), _name(name) {}

ostream &operator<<(ostream &os, const Tile &tile) {
    os << "Tile{Id: " << tile._id << " Property: " << tile._property << " Name: " << tile._name << "}";
    return os;
}
