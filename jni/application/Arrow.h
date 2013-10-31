#ifndef ARROW_H
#define ARROW_H

#include "Game_Object.h"
#include <zenilib.h>

class Arrow : public Game_Object {
  public:
    Arrow(const Zeni::Point3f &corner_,
          const Zeni::Vector3f& forward_,
          const float& power);

    void render() override;
	const Zeni::Collision::Sphere& get_body() const { return body; }
    void update(const float& time_step) override;

	float get_distance_traveled() {return distance_traveled;}

    ~Arrow();

protected:
	void create_body() override;

private:
    Zeni::Vector3f forward;
    float power;
	float distance_traveled;
    static Zeni::Model* model;
    static unsigned long instance_count;

	Zeni::Collision::Sphere body;
};

#endif