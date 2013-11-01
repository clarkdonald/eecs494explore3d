#include "White_Ghost.h"

using namespace std;
using namespace Zeni;

White_Ghost::White_Ghost(const Point3f &corner_)
: Monster(3, 1, rand() % 3 + 1, corner_, Vector3f(UNIT_LENGTH, UNIT_LENGTH, UNIT_LENGTH)) {
	if (!instance_count) model = new Model("models/ghost.3ds");
	++instance_count;
	create_body();
}

White_Ghost::~White_Ghost() {
  if (!--instance_count) {
     delete model;
     model = 0lu;
  }
}

void White_Ghost::render() {
  const std::pair<Vector3f, float> cur_rotation = get_rotation().get_rotation();
  model->set_translate(get_corner());
  model->set_scale(get_scale());
  model->set_rotate(cur_rotation.second, cur_rotation.first);
  model->render();
}

void White_Ghost::update(const float& time_step, const Point3f& player_position) 
{
	Vector3f direction_to_player = Vector3f(player_position - get_corner());
	set_corner(get_corner() + time_step * (speed / 6.0f) * direction_to_player);
}

Model* White_Ghost::model = 0;
unsigned long White_Ghost::instance_count = 0lu;
