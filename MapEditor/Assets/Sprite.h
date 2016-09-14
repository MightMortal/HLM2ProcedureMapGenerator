//
// Created by Timofey Lysenko on 13.09.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_SPRITE_H
#define HLM2PROCEDUREMAPGENERATOR_SPRITE_H

#include <ostream>
#include "../../common.h"

class Sprite
{
public:
    Sprite(int _Key, const string &_SpritePath, int _Width, int _Height, int _NumFrames);

    virtual ~Sprite();

    int Key() const
    { return _Key; }

    const string &SpritePath() const
    { return _SpritePath; }

    int Width() const
    { return _Width; }

    int Height() const
    { return _Height; }

    int NumFrames() const
    { return _NumFrames; }

    friend ostream &operator<<(ostream &os, const Sprite &sprite);

private:
    int _Key;
    string _SpritePath;
    int _Width;
    int _Height;
    int _NumFrames;
};

#endif //HLM2PROCEDUREMAPGENERATOR_SPRITE_H
