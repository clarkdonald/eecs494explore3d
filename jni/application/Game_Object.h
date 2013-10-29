//
//  Game_Object.h
//  game
//
//  Created by Donald Clark on 10/26/13.
//
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <zenilib.h>

class Game_Object {
  public:
    Game_Object(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
                const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
                const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f),
                Zeni::Sound_Source *sound_ = nullptr);
  
    virtual ~Game_Object() = 0;
    virtual void render() = 0;
	virtual void update(const float& time_step) { /*does nothing for some objects */ }
    virtual void collide();

    const Zeni::Point3f & get_corner() const {return corner;}
	const Zeni::Vector3f & get_scale() const {return scale;}
    const Zeni::Quaternion & get_rotation() const {return rotation;}

    void set_corner(const Zeni::Point3f &corner_) {corner = corner_;}
    void set_scale(const Zeni::Vector3f &scale_) {scale = scale_;}
    void set_rotation(const Zeni::Quaternion &rotation_) {rotation = rotation_;}
    const Zeni::Collision::Parallelepiped & get_body() const {return body;}
  
  protected:
    void create_body();
  
  private:
    // Level 1
    Zeni::Sound_Source * source;
    
    // Level 2
    Zeni::Point3f corner;
    Zeni::Vector3f scale;
    Zeni::Quaternion rotation;
    
    // Level 3
    Zeni::Collision::Parallelepiped body; // not motion so much as collision
};

#endif /* GAME_OBJECT_H */
