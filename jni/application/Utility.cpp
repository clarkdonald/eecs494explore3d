//
//  Utility.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Utility.h"

Controls::Controls()
: forward(false),
  left(false),
  back(false),
  right(false),
  pickup_item(false),
  drop_item(false),
  use_item(false),
  shooting_arrow(false)
{}

Dimension::Dimension()
: width(0),
  height(0)
{}

Dimension::Dimension(int width_, int height_)
: width(width_),
  height(height_)
{}
