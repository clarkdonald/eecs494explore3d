//
//  Fire.h
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#ifndef FIRE_H
#define FIRE_H

#include <zenilib.h>
#include "Terrain.h"

class Fire : public Terrain {
  public:
    Fire(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
         const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
         const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
    
    Fire(const Fire &rhs);
    
    Fire & operator=(const Fire &rhs);
    
    ~Fire();
    
    virtual void render() override;
  
    bool is_fire() const override;
  
  private:
    static Zeni::Model * model;
    static unsigned long instance_count;
};

#endif /* FIRE_H */
