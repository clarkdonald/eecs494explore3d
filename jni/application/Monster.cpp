//
//  Terrain.cpp
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#include "Monster.h"

using namespace Zeni;

Monster::Monster(int health_, int damage_, int speed_,
				 const Point3f &corner_,
                 const Vector3f &scale_,
                 const Quaternion &rotation_)
: Game_Object(corner_, scale_, rotation_), health(health_), damage(damage_), speed(speed_)
{}

void Monster::take_damage(int damage)
{
	health -= damage;
}

