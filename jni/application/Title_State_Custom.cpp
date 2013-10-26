//
//  Title_State_Custom.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Title_State_Custom.h"

using namespace Zeni;

Title_State_Custom::Title_State_Custom()
: Title_State<Play_State, Instructions_State>("")
{
  m_widgets.unlend_Widget(title);
}

void Title_State_Custom::render() {
  Title_State<Play_State, Instructions_State>::render();
  render_image("logo", Point2f(150.0f, 0.0f), Point2f(650.0f, 225.0f));
}
