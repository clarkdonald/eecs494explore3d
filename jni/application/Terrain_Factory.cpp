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

Terrain * create_terrain(const String &type_,
                         const Point3f &corner_,
                         const Vector3f &scale_,
                         const Quaternion &rotation_)
{
  if (type_ == "Crate") return new Crate(corner_, scale_, rotation_);
  else if (type_ == "Stone") return new Solid_Terrain("models/stone_block.3ds", corner_, scale_, rotation_);
  else if (type_ == "Brick") return new Solid_Terrain("models/brick_block.3ds", corner_, scale_, rotation_);
  else if (type_ == "Grass") return new Solid_Terrain("models/grass_block.3ds", corner_, scale_, rotation_);
  else if (type_ == "Concrete") return new Solid_Terrain("models/concrete_block.3ds", corner_, scale_, rotation_);
  else if (type_ == "Dirt") return new Solid_Terrain("models/dirt_block.3ds", corner_, scale_, rotation_);
  else if (type_ == "Sand") return new Solid_Terrain("models/sand_block.3ds", corner_, scale_, rotation_);
  else if (type_ == "Cloud") return new Solid_Terrain("models/cloud_block.3ds", corner_, scale_, rotation_);
  else if (type_ == "Water") return new Solid_Terrain("models/water_block.3ds", corner_, scale_, rotation_);
  else throw new std::bad_alloc;
}
