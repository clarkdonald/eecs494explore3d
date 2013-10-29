#ifndef ARROW_H
#define ARROW_H

#include "Game_Object.h"
#include <zenilib.h>

class Arrow : public Game_Object {
  public:
    Arrow(const Zeni::Point3f &corner_, const Zeni::Vector3f& forward_, const float& power);

    bool is_done() {return current_state == DISSAPEAR;}

    void render() override;
  
    void update(const float& time_step) override;

    ~Arrow();
  private:

    enum Arrow_State
      { IN_MOTION, HIT_OBJECT, DISSAPEAR };
    
    Arrow_State current_state;
    Zeni::Vector3f forward;
    float power;
    static Zeni::Model* model;
    static unsigned long instance_count;
};

#endif