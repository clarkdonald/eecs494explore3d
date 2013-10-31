//
//  Strength_Potion.h
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#ifndef STRENGTH_POTION_H
#define STRENGTH_POTION_H

#include "Item.h"
#include <zenilib.h>

class Strength_Potion : public Item {
  public:
    Strength_Potion(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
                    const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
                    const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
  
    Strength_Potion(const Strength_Potion &rhs);
    
    Strength_Potion & operator=(const Strength_Potion &rhs);
    
    ~Strength_Potion();
    
    virtual void render() override;
  
    bool for_lifting() const override;
  
  private:
    static Zeni::Model * model;
    static unsigned long instance_count;
};

#endif /* STRENGTH_POTION_H */
