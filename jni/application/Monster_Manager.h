//
//  Terrain.h
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#ifndef MONSTER_MANAGER_H
#define MONSTER_MANAGER_H

#include "Game_Object.h"
#include "White_Ghost.h"
#include "Monster.h"
#include "Utility.h"
#include <zenilib.h>

const int MAX_MONSTERS = 10;

Monster* spawn_monster(const Zeni::Point3f& player_position);

#endif /* TERRAIN_H */
