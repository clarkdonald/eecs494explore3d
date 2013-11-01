//
//  Crosshair.cpp
//  game
//
//  Created by Donald Clark on 10/27/13.
//
//

#include "Crosshair.h"
#include "Utility.h"
#include "Player.h"
#include <zenilib.h>

using namespace Zeni;

Crosshair::Crosshair()
: radius(25.0f)
{}

Crosshair::~Crosshair() {}

void Crosshair::render(const bool &is_wielding_weapon, Player* player) {
  String texture = is_wielding_weapon ? "weapon_crosshair" : "normal_crosshair";
  float center_x = VIDEO_DIMENSION.second.x/2;
  float center_y = VIDEO_DIMENSION.second.y/2;
  render_image(texture,
               Point2f(center_x-radius, center_y-radius),
               Point2f(center_x+radius, center_y+radius));

  //render the hearts
  float x_val = 0.0f;
  int k;
  for(k = 0; k < player->get_health(); k++){
	render_image("filled_heart", Point2f(x_val, 0.0f), Point2f(x_val + 32.0f, 32.0f));
	  x_val += 32.0f;
  }
  while(k < 5){
	render_image("empty_heart", Point2f(x_val, 0.0f), Point2f(x_val + 32.0f, 32.0f));
	  x_val += 32;
    k++;
  }

  x_val = 0;
  if(player -> can_lift()){
    render_image("yellow_pill", Point2f(x_val, 32.0f), Point2f(x_val + 32.0f, 64.0f));
	  x_val += 32;
  }
  if(player -> can_walk_through_fire()){
    render_image("blue_pill", Point2f(x_val, 32.0f), Point2f(x_val + 32.0f, 64.0f));
	  x_val += 32;
  }
  if(player -> can_walk_through_terrain()){
    render_image("white_pill", Point2f(x_val, 32.0f), Point2f(x_val + 32.0f, 64.0f));
	  x_val += 32;
  }
  if(player -> can_jump()){
    render_image("green_pill", Point2f(x_val, 32.0f), Point2f(x_val + 32.0f, 64.0f));
	  x_val += 32;
  }
}
