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

class Crate {
  public:
    Crate(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
          const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
          const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
    Crate(const Crate &rhs);
    Crate & operator=(const Crate &rhs);
    ~Crate();
    
    void render();
    
    void collide();
    
    const Zeni::Collision::Parallelepiped & get_body() const {return body;}
    
  private:
    void create_body();
    
    // Level 1
    static Zeni::Model * model;
    static unsigned long instance_count;
    Zeni::Sound_Source * source;
    
    // Level 2
    Zeni::Point3f corner;
    Zeni::Vector3f scale;
    Zeni::Quaternion rotation;
    
    // Level 3
    Zeni::Collision::Parallelepiped body; // not motion so much as collision
};

#endif /* CRATE_H */

