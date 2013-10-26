//
//  Object_Factory.h
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include <zenilib.h>

class Game_Object;

Game_Object * create_object(const Zeni::String &type_,
                            const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
                            const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
                            const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));

#endif /* OBJECT_FACTORY_H */
