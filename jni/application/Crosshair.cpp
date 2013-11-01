//
//  Crosshair.cpp
//  game
//
//  Created by Donald Clark on 10/27/13.
//
//

#include "Crosshair.h"
#include "Utility.h"
#include <zenilib.h>

using namespace Zeni;

Crosshair::Crosshair()
: radius(25.0f)
{}

Crosshair::~Crosshair() {}

void Crosshair::render(const bool &is_wielding_weapon, int player_health, int monsters_killed) {
  String texture = is_wielding_weapon ? "weapon_crosshair" : "normal_crosshair";
  float center_x = VIDEO_DIMENSION.second.x/2;
  float center_y = VIDEO_DIMENSION.second.y/2;
  render_image(texture,
               Point2f(center_x-radius, center_y-radius),
               Point2f(center_x+radius, center_y+radius));

  //render the hearts
  float x_val = 0.0f;
  int k;
  for(k = 0; k < player_health; k++){
	render_image("filled_heart", Point2f(x_val, 32.0f), Point2f(x_val + 32.0f, 64.0f));
	x_val += 32.0f;
  }
  while(k < 5){
	render_image("empty_heart", Point2f(x_val, 32.0f), Point2f(x_val + 32.0f, 64.0f));
	x_val += 32;
    k++;
  }

  std::string score_ = "Score: ";
  score_ += std::to_string(monsters_killed);
  String score = "";
  score = score_;
  Zeni::Font &fr = get_Fonts()["system_36_x600"];
  fr.render_text(score, Point2f(0.0f, 0.0f), get_Colors()["title_text"], ZENI_LEFT);
}
