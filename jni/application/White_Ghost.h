//
//  Terrain.h
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#ifndef WHITE_GHOST_
#define WHITE_GHOST_

#include "Monster.h"
#include "Utility.h"
#include <zenilib.h>

class White_Ghost : public Monster {
  public:
    White_Ghost(const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f));

	void update(const float& time_step) override;
	void render() override;

	~White_Ghost();

private:
	static Zeni::Model* model;
    static unsigned long instance_count;
};

#endif /* TERRAIN_H */
