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
: source(new Sound_Source(get_Sounds()["collide"])),
  corner(corner_),
  scale(scale_),
  rotation(rotation_)
{
  if (!instance_count) model = new Model("models/crate.3ds");
  ++instance_count;
  create_body();
}

Crate::Crate(const Crate &rhs)
: source(new Sound_Source(get_Sounds()["collide"])),
  corner(rhs.corner),
  scale(rhs.scale),
  rotation(rhs.rotation)
{
  ++instance_count;
  create_body();
}

Crate & Crate::operator=(const Crate &rhs) {
  corner = rhs.corner;
  scale = rhs.scale;
  rotation = rhs.rotation;
  create_body();
  return *this;
}

Crate::~Crate() {
  delete source;
  if(!--instance_count) {
    delete model;
    model = 0lu;
  }
}

void Crate::render() {
  const std::pair<Vector3f, float> cur_rotation = rotation.get_rotation();
  
  model->set_translate(corner);
  model->set_scale(scale);
  model->set_rotate(cur_rotation.second, cur_rotation.first);

  model->render();
}

void Crate::collide() {
  if (!source->is_playing()) source->play();
}

void Crate::create_body() {
  body = Parallelepiped(corner,
                        rotation * scale.get_i(),
                        rotation * scale.get_j(),
                        rotation * scale.get_k());
  
  source->set_position(corner + rotation * scale / 2.0f);
}

Model * Crate::model = 0;
unsigned long Crate::instance_count = 0lu;
