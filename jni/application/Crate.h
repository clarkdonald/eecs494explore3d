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
    
    const Zeni::Collision::Parallelepiped & get_body() const {return m_body;}
    
  private:
    void create_body();
    
    // Level 1
    static Zeni::Model * m_model;
    static unsigned long m_instance_count;
    
    Zeni::Sound_Source * m_source;
    
    // Level 2
    Zeni::Point3f m_corner;
    Zeni::Vector3f m_scale;
    Zeni::Quaternion m_rotation;
    
    // Level 3
    Zeni::Collision::Parallelepiped m_body; // not motion so much as collision
    
    // Level 4
    // A stationary Crate has no controls
};

#endif /* CRATE_H */

