//
//  Object_Factory.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Object_Factory.h"
#include "Object_Includes.h"

using std::bad_alloc;
using namespace Zeni;

Game_Object * create_object(const String &type_,
                            const Point3f &corner_,
                            const Vector3f &scale_,
                            const Quaternion &rotation_)
{
  if (type_ == "Crate") return new Crate(corner_, scale_, rotation_);
  else if (type_ == "Ground") return new Ground(corner_, scale_, rotation_);
  else throw new std::bad_alloc;
}
