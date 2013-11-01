//
//  Fire.cpp
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#include "Fire.h"

using namespace Zeni;
using namespace Zeni::Collision;

Fire::Fire(const Point3f &corner_,
             const Vector3f &scale_,
             const Quaternion &rotation_)
: Terrain(corner_, scale_, rotation_)
{
  if (!instance_count) model = new Model("models/fire_block.3ds");
  ++instance_count;
  create_body();
}

Fire::Fire(const Fire &rhs)
: Terrain(rhs.get_corner(),
          rhs.get_scale(),
          rhs.get_rotation())
{
  ++instance_count;
  create_body();
}

Fire & Fire::operator=(const Fire &rhs) {
  set_corner(rhs.get_corner());
  set_scale(rhs.get_scale());
  set_rotation(rhs.get_rotation());
  create_body();
  return *this;
}

Fire::~Fire() {
  if (!--instance_count) {
    delete model;
    model = 0lu;
  }
}

void Fire::render() {
  const std::pair<Vector3f, float> cur_rotation = get_rotation().get_rotation();
  model->set_translate(get_corner());
  model->set_scale(get_scale());
  model->set_rotate(cur_rotation.second, cur_rotation.first);
  model->render();
}

bool Fire::is_fire() const {
  return true;
}

Model * Fire::model = 0;
unsigned long Fire::instance_count = 0lu;