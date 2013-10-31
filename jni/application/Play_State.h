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

class Game_State;

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
    Game_State *game_state;
};

#endif /* PLAY_STATE_H */
