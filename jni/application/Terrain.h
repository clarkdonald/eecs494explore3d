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
  
    virtual bool is_cuttable() const;
    
    virtual bool is_water_filling() const;
    
    virtual bool is_extinguishable() const;
    
    virtual bool is_crushable() const;
    
    virtual bool is_forced_move() const;
};

#endif /* TERRAIN_H */
