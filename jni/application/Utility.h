//
//  Utility.h
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#ifndef UTILITY_H
#define UTILITY_H

#include <utility>
#include <Zeni/Coordinate.h>

const float UNIT_LENGTH = 40.0f;
const float CAMERA_HEIGHT = 50.0f;
const float SKINNY_HEIGHT = 5.0f;
const float ITEM_LENGTH = 1.0f;
const float FIRE_LENGTH = UNIT_LENGTH*3;
const Zeni::Vector3f FIRE_SIZE = Zeni::Vector3f(UNIT_LENGTH,UNIT_LENGTH,FIRE_LENGTH);
const Zeni::Vector3f ITEM_SIZE = Zeni::Vector3f(ITEM_LENGTH,ITEM_LENGTH,ITEM_LENGTH);
const Zeni::Vector3f STANDARD_SIZE = Zeni::Vector3f(UNIT_LENGTH,UNIT_LENGTH,UNIT_LENGTH);
const Zeni::Vector3f MEDIUM_SIZE = Zeni::Vector3f(UNIT_LENGTH,UNIT_LENGTH,UNIT_LENGTH-SKINNY_HEIGHT);
const Zeni::Vector3f SKINNY_SIZE = Zeni::Vector3f(UNIT_LENGTH,UNIT_LENGTH,SKINNY_HEIGHT);
const std::pair<Zeni::Point2f, Zeni::Point2f> VIDEO_DIMENSION =
  std::make_pair(Zeni::Point2f(0.0f, 0.0f), Zeni::Point2f(854.0f, 480.0f));

struct Controls {
  Controls();
  bool forward;
  bool left;
  bool back;
  bool right;
  bool pickup_item;
  bool use_item;
  bool shooting_arrow;
};

struct Dimension {
  Dimension();
  Dimension(int width_, int height_);
  int width;
  int height;
};

#endif /* UTILITY_H */
