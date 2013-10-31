//
//  Ghost_Potion.h
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#ifndef GHOST_POTION_H
#define GHOST_POTION_H

#include "Item.h"
#include <zenilib.h>

class Ghost_Potion : public Item {
  public:
    Ghost_Potion(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
                    const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
                    const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
    
    Ghost_Potion(const Ghost_Potion &rhs);
    
    Ghost_Potion & operator=(const Ghost_Potion &rhs);
    
    ~Ghost_Potion();
    
    virtual void render() override;
    
    bool for_ghost() const override;
    
  private:
    static Zeni::Model * model;
    static unsigned long instance_count;
};

#endif /* GHOST_POTION_H */
