//
//  Play_State.h
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "Crate.h"
#include "Player.h"
#include <zenilib.h>

class Play_State : public Zeni::Gamestate_Base {
    struct Controls {
      Controls() : forward(false), left(false), back(false), right(false) {}
      
      bool forward;
      bool left;
      bool back;
      bool right;
    } controls;
    
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
    
    Crate crate;
    Player player;
    
    bool moved;
};

#endif /* PLAY_STATE_H */

