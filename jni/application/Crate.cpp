//
//  Crate.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Crate.h"

using namespace Zeni;
using namespace Zeni::Collision;

Crate::Crate(const Point3f &corner_,
             const Vector3f &scale_,
             const Quaternion &rotation_)
: Terrain(corner_, scale_, rotation_)
{

  if (!instance_count) model = new Model("models/crate.3ds");
  ++instance_count;
  create_body();
  create_big_body();
}

Crate::Crate(const Crate &rhs)
: Terrain(rhs.get_corner(),
          rhs.get_scale(),
          rhs.get_rotation())
{
  ++instance_count;
  create_body();
  create_big_body();
}

Crate & Crate::operator=(const Crate &rhs) {
  set_corner(rhs.get_corner());
  set_scale(rhs.get_scale());
  set_rotation(rhs.get_rotation());
  create_body();
  create_big_body();
  return *this;
}

Crate::~Crate() {
  if (!--instance_count) {
    delete model;
    model = 0lu;
  }
}

void Crate::render() {
  const std::pair<Vector3f, float> cur_rotation = get_rotation().get_rotation();
  model->set_translate(get_corner());
  model->set_scale(get_scale());
  model->set_rotate(cur_rotation.second, cur_rotation.first);
  model->render();
}

bool Crate::is_portable() const {
	return true;
}

void Crate::create_big_body()
{
	big_body = Parallelepiped(get_corner() - Point3f(10.0f, 10.0f, 10.0f),
						get_rotation() * get_scale().get_i() * 1.5,
                        get_rotation() * get_scale().get_j() * 1.5,
                        get_rotation() * get_scale().get_k() * 1.5);
}

Model * Crate::model = 0;
unsigned long Crate::instance_count = 0lu;
