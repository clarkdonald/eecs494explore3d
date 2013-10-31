//
//  Terrain.cpp
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#include "Terrain.h"

using namespace Zeni;

Terrain::Terrain(const Point3f &corner_,
                 const Vector3f &scale_,
                 const Quaternion &rotation_)
: Game_Object(corner_, scale_, rotation_)
{}

Terrain::~Terrain() {}

bool Terrain::is_portal() const {
  return false;
}

bool Terrain::is_portable() const {
  return false;
}

bool Terrain::is_fire() const {
  return false;
}
