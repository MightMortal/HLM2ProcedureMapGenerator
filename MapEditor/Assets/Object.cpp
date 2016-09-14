//
// Created by Timofey Lysenko on 13.09.16.
//

#include "Object.h"

Object::Object(int _Key,
               const string &_ObjectName,
               int _Sprite,
               int _Depth,
               int _ParentObject,
               int _MaskSprite,
               bool _Solid,
               bool _Visible,
               bool _Persistent)
    : _Key(_Key),
      _ObjectName(_ObjectName),
      _Sprite(_Sprite),
      _Depth(_Depth),
      _ParentObject(_ParentObject),
      _MaskSprite(_MaskSprite),
      _Solid(_Solid),
      _Visible(_Visible),
      _Persistent(_Persistent)
{}

Object::~Object()
{}

ostream &operator<<(ostream &os, const Object &object)
{
    os << "Object{_Key: " << object._Key << " _ObjectName: " << object._ObjectName << " _Sprite: " << object._Sprite
       << " _Depth: " << object._Depth << " _ParentObject: " << object._ParentObject << " _MaskSprite: "
       << object._MaskSprite << " _Solid: " << object._Solid << " _Visible: " << object._Visible << " _Persistent: "
       << object._Persistent << "}";
    return os;
}
