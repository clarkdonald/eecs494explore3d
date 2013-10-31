//
//  Item.h
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#ifndef ITEM_H
#define ITEM_H

#include "Game_Object.h"
#include <zenilib.h>

class Item : public Game_Object {
  public:
    Item(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
         const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
         const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
  
    virtual ~Item() = 0;
    
    virtual bool for_fire() const;
    
    virtual bool for_jumping() const;
    
    virtual bool for_lifting() const;
    
    virtual bool for_ghost() const;
};

#endif /* ITEM_H */
