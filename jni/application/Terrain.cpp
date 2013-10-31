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

bool Terrain::is_cuttable() const {
  return false;
}

bool Terrain::is_water_filling() const {
  return false;
}

bool Terrain::is_extinguishable() const {
  return false;
}

bool Terrain::is_crushable() const {
  return false;
}

bool Terrain::is_forced_move() const {
  return false;
}
