#include "Monster_Manager.h"
#include "White_Ghost.h"
#include "Monster.h"
#include <zenilib.h>

using namespace std;
using namespace Zeni;

Monster* spawn_monster(const Point3f& player_position)
{
	return new White_Ghost(Point3f(player_position.x + rand() % 2000 + 1000, player_position.y + rand() % 2000 + 1000, 50.0f)); 
}