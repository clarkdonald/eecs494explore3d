//
//  Item.cpp
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#include "Item.h"

using namespace Zeni;

Item::Item(const Point3f &corner_,
           const Vector3f &scale_,
           const Quaternion &rotation_)
: Game_Object(corner_, scale_, rotation_)
{}

Item::~Item() {}

bool Item::for_fire() const {
  return false;
}

bool Item::for_jumping() const {
  return false;
}

bool Item::for_lifting() const {
  return false;
}

bool Item::for_ghost() const {
  return false;
}
