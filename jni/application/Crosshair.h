//
//  Crosshair.h
//  game
//
//  Created by Donald Clark on 10/27/13.
//
//

#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include "Game_Object.h"

class Player;

class Crosshair {
  public:
    Crosshair();

    ~Crosshair();
  
    void render(const bool &is_wielding_weapon, Player* player);
  
    const float & get_radius() {return radius;}
  
  private:
    float radius;
};

#endif /* CROSSHAIR_H */
