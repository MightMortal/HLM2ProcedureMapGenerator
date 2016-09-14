//
// Created by Timofey Lysenko on 13.09.16.
//

#include "Sprite.h"

Sprite::Sprite(int _Key, const string &_SpritePath, int _Width, int _Height, int _NumFrames)
    : _Key(_Key), _SpritePath(_SpritePath), _Width(_Width), _Height(_Height), _NumFrames(_NumFrames)
{}

ostream &operator<<(ostream &os, const Sprite &sprite)
{
    os << "Sprite{_Key: " << sprite._Key << " _SpritePath: " << sprite._SpritePath << " _Width: " << sprite._Width
       << " _Height: " << sprite._Height << " _NumFrames: " << sprite._NumFrames << "}";
    return os;
}

Sprite::~Sprite()
{}
