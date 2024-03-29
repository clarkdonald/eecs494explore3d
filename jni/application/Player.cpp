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
#include "Item.h"
#include "Terrain.h"

using namespace Zeni;
using namespace Zeni::Collision;
using std::bad_exception;

Player::Abilities::Abilities()
: lift(false), jump(false), ghost(false), water(false)
{}

void Player::Abilities::clear() {
  lift = jump = ghost = water = false;
}

void Player::Abilities::set(const Item *item_) {
  if (!lift) lift = item_->for_lifting();
  if (!jump) jump = item_->for_jumping();
  if (!ghost) ghost = item_->for_ghost();
  if (!water) water = item_->for_fire();
}

Player::Player(const Camera &camera_,
               const Vector3f &end_point_b_,
               const float radius_)
: camera(camera_),
  end_point_b(end_point_b_),
  radius(radius_),
  on_ground(false),
  wielding_weapon(false),
  //item(nullptr),
  terrain(nullptr)
{
  camera.fov_rad = Zeni::Global::pi / 3.0f;
  health = 5;
  create_body();
}

Player::~Player() {
  if (terrain != nullptr) delete terrain;
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
    if (abilities.jump) velocity.k += 150.0f;
    else velocity.k += 75.0f;
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

void Player::set_item(Item *item_) {
  abilities.set(item_);
}

Terrain * Player::drop_terrain() {
  if (!is_lifting_terrain()) throw new bad_exception;
  Terrain *ret = terrain;
  terrain = nullptr;
  return ret;
}

Arrow * Player::fire() {
  return new Arrow(camera.position + Vector3f(18.0, 18.0, 3.0),
                   camera.get_forward());
}
