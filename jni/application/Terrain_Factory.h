//
//  Terrain_Factory.h
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#ifndef TERRAIN_FACTORY_H
#define TERRAIN_FACTORY_H

#include "Utility.h"
#include <zenilib.h>

class Terrain;

Terrain * create_terrain(const Zeni::String &type_,
                         const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
                         const Zeni::Vector3f &scale_ = STANDARD_SIZE,
                         const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));

#endif /* TERRAIN_FACTORY_H */
