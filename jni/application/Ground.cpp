//
//  Ground.cpp
//  game
//
//  Created by Donald Clark on 10/27/13.
//
//

#include "Ground.h"

using namespace Zeni;
using namespace Zeni::Collision;

Ground::Ground(const Point3f &corner_,
               const Vector3f &scale_,
               const Quaternion &rotation_)
: Terrain(corner_, scale_, rotation_)
{
  if (!instance_count) model = new Model("models/ground.3ds");
  ++instance_count;
  create_body();
}

Ground::Ground(const Ground &rhs)
: Terrain(rhs.get_corner(), rhs.get_scale(), rhs.get_rotation())
{
  ++instance_count;
  create_body();
}

Ground & Ground::operator=(const Ground &rhs) {
  set_corner(rhs.get_corner());
  set_scale(rhs.get_scale());
  set_rotation(rhs.get_rotation());
  create_body();
  return *this;
}

Ground::~Ground() {
  if (!--instance_count) {
    delete model;
    model = 0lu;
  }
}

void Ground::render() {
  const std::pair<Vector3f, float> cur_rotation = get_rotation().get_rotation();
  model->set_translate(get_corner());
  model->set_scale(get_scale());
  model->set_rotate(cur_rotation.second, cur_rotation.first);
  model->render();
}

Model * Ground::model = 0;
unsigned long Ground::instance_count = 0lu;
