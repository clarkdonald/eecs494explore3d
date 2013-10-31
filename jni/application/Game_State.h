//
//  Game_State.h
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

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

class Game_State {
public:
  Game_State(const std::string &file_);
  
  ~Game_State();
  
  void on_push();
  
  void on_pop();
  
  bool on_key(const SDL_KeyboardEvent &event);
  
  void on_mouse_motion(const SDL_MouseMotionEvent &event);
  
  void on_mouse_button(const SDL_MouseButtonEvent &event);
  
  void perform_logic();
  
  void render();
  
  bool is_done() const {return done;}
  
  bool is_common() const {return level_type_e == COMMON;}
  
private:
  void clear();
  
  void partial_step(const float &time_step, const Zeni::Vector3f &velocity);
  
  void load_map(const std::string &file_);
  
  Zeni::Time_HQ time_passed;
  Controls controls;
  std::list<Item*> items;
  std::list<Terrain*> terrains;
  std::list<Arrow*> arrows;
  std::list<Monster*> monsters;
  std::list<Cloud*> clouds;
  Player* player;
  Crosshair crosshair;
  float bow_power;
  bool moved;
  bool done;
  Dimension dimension;
  enum Level_Type { COMMON, GAME } level_type_e;
};

#endif /* GAME_STATE_H */