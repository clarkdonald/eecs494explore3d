//
//  Terrain_Factory.cpp
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#include "Terrain_Factory.h"
#include "Terrain_Includes.h"

using std::bad_alloc;
using namespace Zeni;

Terrain * create_terrain(const Zeni::String &type_,
                         const Zeni::Point3f &corner_,
                         const Zeni::Vector3f &scale_,
                         const Zeni::Quaternion &rotation_)
{
  if (type_ == "Ground") return new Ground(corner_, scale_, rotation_);
  else if (type_ == "Crate") return new Crate(corner_, scale_, rotation_);
  else throw new std::bad_alloc;
}
