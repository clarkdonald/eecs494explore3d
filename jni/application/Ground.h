//
//  Ground.h
//  game
//
//  Created by Donald Clark on 10/27/13.
//
//

#ifndef GROUND_H
#define GROUND_H

#include <zenilib.h>
#include "Terrain.h"
#include <zenilib.h>

class Ground : public Terrain {
public:
  Ground(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
         const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
         const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
  
  Ground(const Ground &rhs);
  
  Ground & operator=(const Ground &rhs);
  
  ~Ground();
  
  virtual void render() override;
  
private:
  static Zeni::Model * model;
  static unsigned long instance_count;
};

#endif /* GROUND_H */