#ifndef SKYBOX_H
#define SKYBOX_H

#include "Game_Object.h"
#include <zenilib.h>

struct Space_Rectangle {
  Space_Rectangle(Zeni::Point3f position_,
                  Zeni::Vector3f vec0_,
                  Zeni::Vector3f vec1_,
                  Zeni::Vector3f vec2_)
  : position(position_), vec0(vec0_), vec1(vec1_), vec2(vec2_)
  {}
  
  Zeni::Point3f position;
  Zeni::Vector3f vec0;
  Zeni::Vector3f vec1;
  Zeni::Vector3f vec2;
};

void render_skybox(const Zeni::Camera& camera);

#endif /* CROSSHAIR_H */
