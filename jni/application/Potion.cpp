//
//  Potion.cpp
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#include "Potion.h"

using namespace Zeni;
using namespace Zeni::Collision;

Potion::Potion(const Zeni::Point3f &corner_,
               const Zeni::Vector3f &scale_,
               const Zeni::Quaternion &rotation_)
: Item(corner_, scale_, rotation_)
{
  if (!instance_count) model = new Model("models/water_block.3ds");
  ++instance_count;
  create_body();
}

Potion::Potion(const Potion &rhs)
: Item(rhs.get_corner(), rhs.get_scale(), rhs.get_rotation())
{
  ++instance_count;
  create_body();
}

Potion & Potion::operator=(const Potion &rhs) {
  set_corner(rhs.get_corner());
  set_scale(rhs.get_scale());
  set_rotation(rhs.get_rotation());
  create_body();
  return *this;
}

Potion::~Potion() {
  if (!--instance_count) {
    delete model;
    model = 0lu;
  }
}

void Potion::render() {
  const std::pair<Vector3f, float> cur_rotation = get_rotation().get_rotation();
  model->set_translate(get_corner());
  model->set_scale(get_scale());
  model->set_rotate(cur_rotation.second, cur_rotation.first);
  model->render();
}

bool Potion::for_pushing() const {
  return true;
}

Model * Potion::model = 0;
unsigned long Potion::instance_count = 0lu;