//
//  Play_State.h
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "Player.h"
#include "Crosshair.h"
#include "Skybox.h"
#include "Utility.h"
#include <zenilib.h>
#include <string>

class Terrain;
class Item;
class Arrow;
class Cloud;
class Monster;

class Play_State : public Zeni::Gamestate_Base {
  public:
    Play_State();
  
    ~Play_State();
  
    void on_push();
  
    void on_pop();
  
    void on_key(const SDL_KeyboardEvent &event);
  
    void on_mouse_motion(const SDL_MouseMotionEvent &event);
  
    void on_mouse_button(const SDL_MouseButtonEvent &event);
  
    void perform_logic();
    
    void render();
    
  private:
    void partial_step(const float &time_step, const Zeni::Vector3f &velocity);
  
    void load_map(const std::string &file_);
  
    Zeni::Time_HQ time_passed;
    Controls controls;
    std::list<Item*> items;
    std::list<Terrain*> terrains;
    std::list<Arrow*> arrows;
	std::list<Cloud*> clouds;
	std::list<Monster*> monsters;
    Player* player;
    Crosshair crosshair;
    float bow_power;
    bool moved;
    Dimension dimension;
};

#endif /* PLAY_STATE_H */
