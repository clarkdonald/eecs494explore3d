//
//  Crate.h
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#ifndef CRATE_H
#define CRATE_H

#include <zenilib.h>
#include "Terrain.h"

class Crate : public Terrain {
  public:
    Crate(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
          const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
          const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
  
    Crate(const Crate &rhs);
  
    Crate & operator=(const Crate &rhs);
  
    ~Crate();
    
    virtual void render() override;
  
    bool is_portable() const override;
  
  private:
    static Zeni::Model * model;
    static unsigned long instance_count;
};

#endif /* CRATE_H */
