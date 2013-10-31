//
//  Play_State.cpp
//  game
//
//  Created by Donald Clark on 10/26/13. blasbdlfjasdlfjlasdjfpiajweoifjoiaw fjadfjoasjdo asdojfaosdjoa
//
//

#include "Play_State.h"
#include "Map_Manager.h"
#include "Game_State.h"
#include <string>

using namespace Zeni;
using namespace Zeni::Collision;
using std::string;

Play_State::Play_State()
: game_state(new Game_State(Map_Manager::get_Instance().get_common_room()))
{
  set_pausable(true);
}

Play_State::~Play_State() {
  if (game_state != nullptr) delete game_state;
}

void Play_State::on_push() {
  get_Window().set_mouse_state(Window::MOUSE_RELATIVE);
}

void Play_State::on_pop() {
  Map_Manager::get_Instance().reset();
  get_Window().set_mouse_state(Window::MOUSE_NORMAL);
}

void Play_State::on_key(const SDL_KeyboardEvent &event) {
  if (event.keysym.sym == SDLK_p && event.type == SDL_KEYDOWN) {
    std::cout << "POOP!\n";
    string file = game_state->is_common() ?
      Map_Manager::get_Instance().get_common_room() :
      Map_Manager::get_Instance().get_previous();
    delete game_state;
    game_state = new Game_State(file);
  }
  
  if (!game_state->on_key(event))
    Gamestate_Base::on_key(event);
}

void Play_State::on_mouse_button(const SDL_MouseButtonEvent &event) {
  game_state->on_mouse_button(event);
}

void Play_State::on_mouse_motion(const SDL_MouseMotionEvent &event) {
  game_state->on_mouse_motion(event);
}

void Play_State::perform_logic() {
  if (game_state->is_done()) {
    delete game_state;
    if (Map_Manager::get_Instance().empty()) get_Game().pop_state();
    else game_state = new Game_State(Map_Manager::get_Instance().get_next());
  }
  game_state->perform_logic();
}

void Play_State::render(){
  game_state->render();
}
