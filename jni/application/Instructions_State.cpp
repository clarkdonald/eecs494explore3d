//
//  Instructions_State.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Instructions_State.h"
#include <utility>

using namespace Zeni;
using std::make_pair;

Instructions_State::Instructions_State()
: tb(Point2f(),
     Point2f(800.0f, 600.0f),
     "system_36_800x600",
     "P U R P O S E\n"
     "You must get to safety by getting to your vehicle. "
     "You do this by clearing obstacles in the map you are thrown in, while "
     "shooting off or dodging away from ghosts.\n\n"
     "C O N T R O L S\n"
     "WASD Keys: Move the explorer\n"
     "Mouse Scroll: Look around\n"
     "Mouse Left-Click: Shoot\n"
     "Space Bar: Jump\n"
     "E Key: Pick up an item\n"
     "C Key: Drop an item\n"
     "F Key: Use an item\n"
     "P Key: Retry level\n\n"
     "ESC to return to the menu.",
     Color())
{
  tb.give_BG_Renderer(new Widget_Renderer_Color(get_Colors()["black"]));
}

void Instructions_State::on_key(const SDL_KeyboardEvent &event) {
  if(event.keysym.sym == SDLK_ESCAPE) {
    if(event.state == SDL_PRESSED)
      get_Game().pop_state();
  }
}

void Instructions_State::render() {
  get_Video().set_2d(make_pair(Point2f(), Point2f(800.0f, 600.0f)), true);
  tb.render();
}
