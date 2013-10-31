//
//  Ghost_Potion.cpp
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#include "Ghost_Potion.h"

using namespace Zeni;
using namespace Zeni::Collision;

Ghost_Potion::Ghost_Potion(const Zeni::Point3f &corner_,
                                 const Zeni::Vector3f &scale_,
                                 const Zeni::Quaternion &rotation_)
: Item(corner_, scale_, rotation_)
{
  if (!instance_count) model = new Model("models/water_block.3ds");
  ++instance_count;
  create_body();
}

Ghost_Potion::Ghost_Potion(const Ghost_Potion &rhs)
: Item(rhs.get_corner(), rhs.get_scale(), rhs.get_rotation())
{
  ++instance_count;
  create_body();
}

Ghost_Potion & Ghost_Potion::operator=(const Ghost_Potion &rhs) {
  set_corner(rhs.get_corner());
  set_scale(rhs.get_scale());
  set_rotation(rhs.get_rotation());
  create_body();
  return *this;
}

Ghost_Potion::~Ghost_Potion() {
  if (!--instance_count) {
    delete model;
    model = 0lu;
  }
}

void Ghost_Potion::render() {
  const std::pair<Vector3f, float> cur_rotation = get_rotation().get_rotation();
  model->set_translate(get_corner());
  model->set_scale(get_scale());
  model->set_rotate(cur_rotation.second, cur_rotation.first);
  model->render();
}

bool Ghost_Potion::for_ghost() const {
  return true;
}

Model * Ghost_Potion::model = 0;
unsigned long Ghost_Potion::instance_count = 0lu;
