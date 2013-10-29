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

class Game_Object;

class Play_State : public Zeni::Gamestate_Base {
  public:
    Play_State();
    
    void on_push();
  
    void on_pop();
  
    void on_key(const SDL_KeyboardEvent &event);
  
    void on_mouse_motion(const SDL_MouseMotionEvent &event);
    
    void perform_logic();
    
    void render();
    
  private:
    void partial_step(const float &time_step, const Zeni::Vector3f &velocity);
  

    void load_map(const std::string &file);
  
    Zeni::Time_HQ time_passed;
    Controls controls;
    std::list<Game_Object*> objects;
    Player* player;
    Crosshair crosshair;
	float bow_power;
    bool moved;
    Dimension dimension;
};

#endif /* PLAY_STATE_H */
