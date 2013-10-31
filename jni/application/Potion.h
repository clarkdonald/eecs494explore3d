//
//  Potion.h
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include <zenilib.h>

class Potion : public Item {
  public:
    Potion(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
           const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
           const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
  
    Potion(const Potion &rhs);
    
    Potion & operator=(const Potion &rhs);
    
    ~Potion();
    
    virtual void render() override;
  
    bool for_lifting() const override;
  
  private:
    static Zeni::Model * model;
    static unsigned long instance_count;
};

#endif /* POTION_H */