//
//  Leg_Potion.h
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#ifndef LEG_POTION_H
#define LEG_POTION_H

#include "Item.h"
#include <zenilib.h>

class Leg_Potion : public Item {
  public:
    Leg_Potion(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
                    const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
                    const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
    
    Leg_Potion(const Leg_Potion &rhs);
    
    Leg_Potion & operator=(const Leg_Potion &rhs);
    
    ~Leg_Potion();
    
    virtual void render() override;
    
    bool for_jumping() const override;
    
  private:
    static Zeni::Model * model;
    static unsigned long instance_count;
};

#endif /* LEG_POTION_H */
