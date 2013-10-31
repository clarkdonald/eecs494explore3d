#include "Arrow.h"

using namespace std;
using namespace Zeni;

Arrow::Arrow(const Point3f &corner_,
             const Vector3f& forward_,
             const float& power_)
: Game_Object(corner_,
              Vector3f(0.5f, 0.5f, 0.5f),
              Quaternion::Axis_Angle(Vector3f(0.0f, 0.0f, 1.0f), 0.0f),
              nullptr),
    forward(forward_), power(power_)
{
	if (!instance_count) model = new Model("models/sphere.3DS");
	++instance_count;
	create_body();
}

Arrow::~Arrow() {
  if (!--instance_count) {
     delete model;
     model = 0lu;
  }
}

void Arrow::render() {
  const std::pair<Vector3f, float> cur_rotation = get_rotation().get_rotation();
  model->set_translate(get_corner());
  model->set_scale(get_scale());
  model->set_rotate(cur_rotation.second, cur_rotation.first);
  model->render();
}

// updates it on its flight, based on x/y velocities and gravity (TBI)
void Arrow::update(const float& time_step) 
{
	set_corner(get_corner() + time_step * 800 * forward);
	create_body();
}

void Arrow::create_body()
{
	body = Collision::Sphere(get_corner() + Vector3f(-18.0f, -18.0f, -3.0f), 1);
}

Model* Arrow::model = 0;
unsigned long Arrow::instance_count = 0lu;
