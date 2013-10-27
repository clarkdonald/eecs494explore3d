//
//  Player.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Player.h"

using namespace Zeni;
using namespace Zeni::Collision;

Player::Player(const Camera &camera_,
               const Vector3f &end_point_b_,
               const float radius_)
: camera(camera_),
  end_point_b(end_point_b_),
  radius(radius_),
  on_ground(false)
{
  camera.fov_rad = Zeni::Global::pi / 3.0f;
  create_body();
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
  camera.position += time_step * velocity;
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
