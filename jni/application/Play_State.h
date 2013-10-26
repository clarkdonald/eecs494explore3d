//
//  Play_State.h
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include <zenilib.h>
#include "Utility.h"

class Play_State : public Zeni::Gamestate_Base {
  Play_State(const Play_State &);
  Play_State operator=(const Play_State &);
  
  public:
    Play_State();
    
  private:
    void on_push();
    
    void on_pop();
    
    void on_key(const SDL_KeyboardEvent &event);
    
    void render();
    
    void perform_logic();
    
    Controls m_control;
};
#endif /* PLAY_STATE_H */
