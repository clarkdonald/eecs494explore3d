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
: lift(false)
{}

void Player::Abilities::clear() {
  lift = false;
}

void Player::Abilities::set(const Item *item_) {
  lift = item_->for_lifting();
}

Player::Player(const Camera &camera_,
               const Vector3f &end_point_b_,
               const float radius_)
: camera(camera_),
  end_point_b(end_point_b_),
  radius(radius_),
  on_ground(false),
  wielding_weapon(false),
  item(nullptr),
  terrain(nullptr)
{
  camera.fov_rad = Zeni::Global::pi / 3.0f;
  create_body();
}

Player::~Player() {
  if (terrain != nullptr) delete terrain;
  if (item != nullptr) delete item;
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
    velocity.k += 75.0f;
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

const bool & Player::can_lift() const {
  return abilities.lift;
}

Item * Player::drop_item() {
  if (!is_wielding_item()) throw new bad_exception;
  abilities.clear();
  Item *ret = item;
  item = nullptr;
  return ret;
}

void Player::set_item(Item *item_) {
  item = item_;
  abilities.set(item);
}

Terrain * Player::drop_terrain() {
  if (!is_lifting_terrain()) throw new bad_exception;
  Terrain *ret = terrain;
  terrain = nullptr;
  return ret;
}

// TODO: need to be able to center the bullets when they get fired
Arrow * Player::fire(const float& bow_power) {
	wielding_weapon = true;
  return new Arrow(camera.position +
                   camera.get_forward() * 10 +
                   camera.get_left() * 12 +
                   camera.get_up() * -12,
                   camera.get_forward(),
                   bow_power);
}
