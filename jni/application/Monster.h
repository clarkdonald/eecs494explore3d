//
//  Terrain.h
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#ifndef MONSTER_H
#define MONSTER_H

#include "Game_Object.h"
#include "Utility.h"
#include <zenilib.h>

class Monster : public Game_Object {
  public:
    Monster(int health_, int damage_, 
			const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
            const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
            const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));

	void update(const float& time_step) = 0;
	void take_damage(int damage);
	bool is_dead() { return health <= 0; }

	int get_damage() {return damage;}

private:
	int health;
	int damage;
};

#endif /* TERRAIN_H */
