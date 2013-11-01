//
//  Fire_Potion.h
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#ifndef FIRE_POTION_H
#define FIRE_POTION_H

#include "Item.h"
#include <zenilib.h>

class Fire_Potion : public Item {
  public:
    Fire_Potion(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
                const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
                const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
    
    Fire_Potion(const Fire_Potion &rhs);
    
    Fire_Potion & operator=(const Fire_Potion &rhs);
    
    ~Fire_Potion();
    
    virtual void render() override;
    
    bool for_fire() const override;
    
  private:
    static Zeni::Model * model;
    static unsigned long instance_count;
};

#endif /* FIRE_POTION_H */
