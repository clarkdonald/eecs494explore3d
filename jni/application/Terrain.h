//
//  Terrain.h
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#ifndef TERRAIN_H
#define TERRAIN_H

#include "Game_Object.h"
#include "Utility.h"
#include <zenilib.h>

class Terrain : public Game_Object {
  public:
    Terrain(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
            const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
            const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));

    virtual ~Terrain() = 0;
  
    virtual bool is_portal() const;
  
    virtual bool is_portable() const;
  
    virtual bool is_fire() const;

	virtual const Zeni::Collision::Parallelepiped & get_big_body() const {return get_body();} 
};

#endif /* TERRAIN_H */
