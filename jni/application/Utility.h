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

const float UNIT_LENGTH = 30.0f;
const Zeni::Vector3f OBJECT_SIZE = Zeni::Vector3f(UNIT_LENGTH,UNIT_LENGTH,UNIT_LENGTH);
const Zeni::Vector3f GROUND_SIZE = Zeni::Vector3f(UNIT_LENGTH,UNIT_LENGTH,5.0f);
const std::pair<Zeni::Point2f, Zeni::Point2f> VIDEO_DIMENSION =
  std::make_pair(Zeni::Point2f(0.0f, 0.0f), Zeni::Point2f(854.0f, 480.0f));

struct Controls {
  Controls();
  bool forward;
  bool left;
  bool back;
  bool right;
  bool pickup_item;
  bool drop_item;
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
