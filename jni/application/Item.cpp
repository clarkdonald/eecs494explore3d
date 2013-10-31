//
//  Item.cpp
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#include "Item.h"
#include "Utility.h"

using namespace Zeni;
using namespace Zeni::Collision;

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

void Item::create_body() {
  body = Capsule(get_corner(),
                 get_corner() + Vector3f(get_scale().x,get_scale().y,0.0f),
                 get_scale().z);
}
