//
//  Play_State.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Play_State.h"

using namespace Zeni;

Play_State::Play_State() {
  set_pausable(true);
}

void Play_State::on_push() {
  get_Window().set_mouse_state(Window::MOUSE_HIDDEN);
}

void Play_State::on_pop() {
  get_Window().set_mouse_state(Window::MOUSE_NORMAL);
}

void Play_State::on_key(const SDL_KeyboardEvent &event) {
  switch(event.keysym.sym) {
    case SDLK_UP:
      m_control.up = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_LEFT:
      m_control.left = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_DOWN:
      m_control.down = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_RIGHT:
      m_control.right = event.type == SDL_KEYDOWN;
      break;
      
    default:
      Gamestate_Base::on_key(event); // Let Gamestate_Base handle it
      break;
  }
}

void Play_State::render() {
}

void Play_State::perform_logic() {
}
