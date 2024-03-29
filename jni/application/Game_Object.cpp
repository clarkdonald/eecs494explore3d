//
//  Game_Object.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Game_Object.h"

using namespace Zeni;
using namespace Zeni::Collision;

Game_Object::Game_Object(const Point3f &corner_,
                         const Vector3f &scale_,
                         const Quaternion &rotation_,
                         Sound_Source *sound_)
: source(nullptr),
  corner(corner_),
  scale(scale_),
  rotation(rotation_)
{}

Game_Object::~Game_Object() {
  if (source != nullptr) delete source;
}

void Game_Object::collide() {
  if (source == nullptr) return;
  if (!source->is_playing()) source->play();
}

void Game_Object::create_body() {
  body = Parallelepiped(corner,
                        rotation * scale.get_i(),
                        rotation * scale.get_j(),
                        rotation * scale.get_k());
  
  if (source)
	  source->set_position(corner + rotation * scale / 2.0f);
}
