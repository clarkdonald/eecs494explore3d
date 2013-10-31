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
class Item;
class Terrain;

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
  
    // functions related to combat
	  void take_damage(int damage) {health -= damage;};
	  bool is_dead() { return health <= 0;}

    // functions related to items
    //bool is_wielding_item() const {return item != nullptr;}
    //Item * drop_item();
    void set_item(Item *item_);
  
    // functions related to abilities from items
    const bool & can_lift() const {return abilities.lift;}
    const bool & can_walk_through_terrain() const {return abilities.ghost;}
    const bool & can_walk_through_fire() const {return abilities.water;}
  
    // functions related to terrains
    bool is_lifting_terrain() const {return terrain != nullptr;}
    Terrain * drop_terrain();
    void set_terrain(Terrain *terrain_) {terrain = terrain_;}
  
    // functions related to arrows
    Arrow * fire(const float& bow_power);
    
  private:
    struct Abilities {
      Abilities();
      void clear();
      void set(const Item *item_);
      bool lift;
      bool jump;
      bool ghost;
      bool water;
    } abilities;
  
    void create_body();
    
    // Level 1/2
    Zeni::Camera camera;
  
    // Level 2
    Zeni::Vector3f end_point_b;
  
    float radius;
    
    // Level 3
    Zeni::Collision::Capsule body; // collision
    Zeni::Vector3f velocity;
  
    bool on_ground; 
    bool wielding_weapon;
	  int health;

	  //Item* item;
    Terrain* terrain;
};

#endif /* PLAYER_H */
