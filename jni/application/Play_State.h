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
#include <zenilib.h>

class Game_Object;

class Play_State : public Zeni::Gamestate_Base {
  public:
    Play_State();
    
    void on_push();
    
    void on_key(const SDL_KeyboardEvent &event);
  
    void on_mouse_motion(const SDL_MouseMotionEvent &event);
    
    void perform_logic();
    
    void render();
    
  private:
    void partial_step(const float &time_step, const Zeni::Vector3f &velocity);
    
    Zeni::Time_HQ time_passed;
  
    struct Controls {
      Controls();
      bool forward;
      bool left;
      bool back;
      bool right;
      bool pickup_item;
      bool drop_item;
      bool use_item;
	  bool shooting_arrow;
    } controls;
  
    std::list<Game_Object*> objects;
    Player player;
    Crosshair crosshair;
	//Skybox skybox;
	float bow_power;
    bool moved;
};

#endif /* PLAY_STATE_H */
