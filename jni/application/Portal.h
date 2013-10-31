//
//  Portal.h
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#ifndef PORTAL_H
#define PORTAL_H

#include <zenilib.h>
#include "Terrain.h"

class Portal : public Terrain {
  public:
    Portal(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
           const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
           const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
    
    Portal(const Portal &rhs);
    
    Portal & operator=(const Portal &rhs);
    
    ~Portal();
  
    bool is_portal() const override;
  
    virtual void render() override;
    
  private:
    static Zeni::Model * model;
    static unsigned long instance_count;
};

#endif /* PORTAL_H */
