//
// Created by Timofey Lysenko on 13.09.16.
//

#ifndef HLM2PROCEDUREMAPGENERATOR_OBJECT_H
#define HLM2PROCEDUREMAPGENERATOR_OBJECT_H

#include <ostream>
#include "../../common.h"
#include "Sprite.h"

class Object
{
public:
    Object(int _Key,
           const string &_ObjectName,
           int _Sprite,
           int _Depth,
           int _ParentObject,
           int _MaskSprite,
           bool _Solid,
           bool _Visible,
           bool _Persistent);

    ~Object();

    int Key() const
    { return _Key; }

    const string &ObjectName() const
    { return _ObjectName; }

    int Sprite() const
    { return _Sprite; }

    int Depth() const
    { return _Depth; }

    int ParentObject() const
    { return _ParentObject; }

    int MaskSprite() const
    { return _MaskSprite; }

    bool isSolid() const
    { return _Solid; }

    bool isVisible() const
    { return _Visible; }

    bool isPersistent() const
    { return _Persistent; }

    friend ostream &operator<<(ostream &os, const Object &object);

private:
    int _Key;
    string _ObjectName;
    int _Sprite;
    int _Depth;
    int _ParentObject;
    int _MaskSprite;
    bool _Solid;
    bool _Visible;
    bool _Persistent;
};

#endif //HLM2PROCEDUREMAPGENERATOR_OBJECT_H
