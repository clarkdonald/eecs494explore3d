//
//  Item_Factory.cpp
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#include "Item_Factory.h"
#include "Item_Includes.h"

using namespace Zeni;
using std::bad_alloc;

Item * create_item(const String &type_,
                   const Point3f &corner_,
                   const Vector3f &scale_,
                   const Quaternion &rotation_)
{
  if (type_ == "Strength") return new Strength_Potion(corner_, scale_, rotation_);
  else throw new std::bad_alloc;
}
