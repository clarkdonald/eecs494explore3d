//
//  Play_State.cpp
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#include "Play_State.h"
#include "Object_Factory.h"
#include "Game_Object.h"

using namespace Zeni;
using namespace Zeni::Collision;

Play_State::Controls::Controls()
: forward(false),
  left(false),
  back(false),
  right(false),
  pickup_item(false),
  drop_item(false),
  use_item(false)
{}

Play_State::Play_State()
: player(Camera(Point3f(0.0f, 0.0f, 50.0f), Quaternion(), 1.0f, 10000.0f),
         Vector3f(0.0f, 0.0f, -39.0f),
         11.0f)
{
  set_pausable(true);
  
  /** Add terrain objects to the world **/
  objects.push_back(create_object("Crate", Point3f(12.0f, 12.0f, 0.0f), Vector3f(30.0f, 30.0f, 30.0f)));
  objects.push_back(create_object("Crate", Point3f(48.0f, 48.0f, 0.0f), Vector3f(30.0f, 30.0f, 30.0f)));
}

void Play_State::on_push() {
  get_Window().set_mouse_state(Window::MOUSE_RELATIVE);
}

void Play_State::on_key(const SDL_KeyboardEvent &event) {
  switch(event.keysym.sym) {
    case SDLK_w:
      controls.forward = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_a:
      controls.left = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_s:
      controls.back = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_d:
      controls.right = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_f:
      controls.pickup_item = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_g:
      controls.drop_item = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_r:
      controls.use_item = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_SPACE:
      if (event.type == SDL_KEYDOWN) {
        player.jump();
        moved = true;
      }
      break;
      
    default:
      Gamestate_Base::on_key(event);
      break;
  }
}

void Play_State::on_mouse_motion(const SDL_MouseMotionEvent &event) {
  player.adjust_pitch(event.yrel / 500.0f);
  player.turn_left_xy(-event.xrel / 500.0f);
}

void Play_State::perform_logic() {
  const Time_HQ current_time = get_Timer_HQ().get_time();
  float processing_time = float(current_time.get_seconds_since(time_passed));
  time_passed = current_time;
  
  /** Get forward and left vectors in the XY-plane **/
  const Vector3f forward = player.get_camera().get_forward().get_ij().normalized();
  const Vector3f left = player.get_camera().get_left().get_ij().normalized();
  
  /** Get velocity vector split into a number of axes **/
  const Vector3f velocity = (controls.forward - controls.back) * 50.0f * forward
    + (controls.left - controls.right) * 50.0f * left;
  const Vector3f x_vel = velocity.get_i();
  const Vector3f y_vel = velocity.get_j();
  Vector3f z_vel = player.get_velocity().get_k();
  
  /** Bookkeeping for sound effects **/
  if (velocity.magnitude() != 0.0f) moved = true;
  
  /** Keep delays under control (if the program hangs for some time, we don't want to lose responsiveness) **/
  if (processing_time > 0.1f) processing_time = 0.1f;
  
  /** Physics processing loop**/
  for (float time_step = 0.05f;
      processing_time > 0.0f;
      processing_time -= time_step)
  {
    if (time_step > processing_time) time_step = processing_time;
    
    /** Gravity has its effect **/
    z_vel -= Vector3f(0.0f, 0.0f, 50.0f * time_step);
    
    /** Try to move on each axis **/
    partial_step(time_step, x_vel);
    partial_step(time_step, y_vel);
    partial_step(time_step, z_vel);
    
    /** Keep player above ground; Bookkeeping for jumping controls **/
    const Point3f &position = player.get_camera().position;
    if (position.z < 50.0f) {
      player.set_position(Point3f(position.x, position.y, 50.0f));
      player.set_on_ground(true);
    }
  }
}

void Play_State::render() {
  Video &vr = get_Video();
  vr.set_3d(player.get_camera());
  for (auto it = objects.begin(); it != objects.end(); ++it) (*it)->render();
}

void Play_State::partial_step(const float &time_step, const Vector3f &velocity) {
  player.set_velocity(velocity);
  const Point3f backup_position = player.get_camera().position;
  
  player.step(time_step);
  
  /** If collision with the crate has occurred, roll things back **/
  for (auto it = objects.begin(); it != objects.end(); ++it) {
    if ((*it)->get_body().intersects(player.get_body())) {
      if (moved) {
        /** Play a sound if possible **/
        (*it)->collide();
        moved = false;
      }
      
      player.set_position(backup_position);
      
      /** Bookkeeping for jumping controls **/
      if (velocity.k < 0.0f) player.set_on_ground(true);
    }
  }
}
