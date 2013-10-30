//
//  Player.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Player.h"
#include "Game_Object.h"
#include "Arrow.h"
#include "Object_Factory.h"

using namespace Zeni;
using namespace Zeni::Collision;

Player::Player(const Camera &camera_,
               const Vector3f &end_point_b_,
               const float radius_)
: camera(camera_),
  source(new Sound_Source(get_Sounds()["gunshot"])),
  end_point_b(end_point_b_),
  radius(radius_),
  on_ground(false),
  wielding_weapon(false)
{
  camera.fov_rad = Zeni::Global::pi / 3.0f;
  create_body();
}

Player::~Player() {
  delete source;
}

void Player::set_position(const Point3f &position) {
  camera.position = position;
  create_body();
}

void Player::adjust_pitch(const float &phi) {
  const Quaternion backup = camera.orientation;
  const Vector3f backup_up = camera.get_up();
  
  camera.adjust_pitch(phi);
  
  if (camera.get_up().k < 0.0f && backup_up.k >= 0.0f)
    camera.orientation = backup;
}

void Player::turn_left_xy(const float &theta) {
  camera.turn_left_xy(theta);
}

void Player::set_on_ground(const bool &is_on_ground_) {
  on_ground = is_on_ground_;
  if (on_ground) velocity.k = 0.0f;
}

void Player::jump() {
  if (on_ground) {
    velocity.k += 60.0f;
    on_ground = false;
  }
}

void Player::step(const float &time_step) {
  camera.position += time_step * velocity * 2;
  create_body();
}

void Player::create_body() {
  Sound &sr = get_Sound();
  
  body = Capsule(camera.position,
                 camera.position + end_point_b,
                 radius);
  
  sr.set_listener_position(camera.position);
  sr.set_listener_forward_and_up(camera.get_forward(), camera.get_up());
  sr.set_listener_velocity(velocity);
}

// TODO: need to be able to center the bullets when they get fired
Arrow * Player::fire(const float& bow_power) {
//  source->set_position(camera.position);
//  if (!source->is_playing()) source->play();
	wielding_weapon = true;
  return new Arrow(camera.position +
                   camera.get_forward() * 10 +
                   camera.get_left() * 12 +
                   camera.get_up() * -12,
                   camera.get_forward(),
                   bow_power);
}
