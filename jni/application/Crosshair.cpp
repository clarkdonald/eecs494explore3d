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

void Crosshair::render(const bool &is_wielding_weapon) {
  String texture = is_wielding_weapon ? "weapon_crosshair" : "normal_crosshair";
  float center_x = VIDEO_DIMENSION.second.x/2;
  float center_y = VIDEO_DIMENSION.second.y/2;
  render_image(texture,
               Point2f(center_x-radius, center_y-radius),
               Point2f(center_x+radius, center_y+radius));
}
