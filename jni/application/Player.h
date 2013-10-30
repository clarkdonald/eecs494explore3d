//
//  Player.h
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#ifndef PLAYER_H
#define PLAYER_H

#include <zenilib.h>
#include <vector>

class Arrow;

class Player {
  public:
    Player(const Zeni::Camera &camera_,
           const Zeni::Vector3f &end_point_b_,
           const float radius_);
  
    ~Player();
    
    // Level 1
    const Zeni::Camera & get_camera() const {return camera;}
  
    // Level 2
    void set_position(const Zeni::Point3f &position);
    void adjust_pitch(const float &phi);
    void turn_left_xy(const float &theta);
    
    // Level 3
    const Zeni::Collision::Capsule & get_body() const {return body;}
    bool is_on_ground() const {return on_ground;}
    bool is_wielding_weapon() const {return wielding_weapon;}
    const Zeni::Vector3f & get_velocity() const {return velocity;}
   
	  void set_velocity(const Zeni::Vector3f &velocity_) {velocity = velocity_;}
    void set_on_ground(const bool &is_on_ground_);
  
	  void jump();
    void step(const float &time_step);
	  void update_arrows(const float& time_step);
	
    //functions related to arrows
    Arrow * fire(const float& bow_power);
    
  private:
    void create_body();
    
    // Level 1/2
    Zeni::Camera camera;
    Zeni::Sound_Source * source;
    
    // Level 2
    Zeni::Vector3f end_point_b;
  
    float radius;
    
    // Level 3
    Zeni::Collision::Capsule body; // collision
    Zeni::Vector3f velocity;
  
    bool on_ground; 
    bool wielding_weapon;
};

#endif /* PLAYER_H */
