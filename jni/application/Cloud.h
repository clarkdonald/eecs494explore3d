#ifndef CLOUD_H
#define CLOUD_H

#include "Game_Object.h"

#include <zenilib.h>

class Terrain;

const Zeni::Vector3f CLOUD_SIZE = Zeni::Vector3f(100.0f, 100.0f, 20.0f);
const float CLOUD_HEIGHT = 800.0f;
const float CLOUD_LENGTH = 100.0f;

class Cloud {
  public:
    Cloud(const Zeni::Point3f &corner_, int pattern_number);

    void render();
  
    void update(const float& time_step);

    ~Cloud();
  private:

    std::vector<Terrain*> cloud_blocks;

	void create_cloud0(const Zeni::Point3f& corner);
	void create_cloud1(const Zeni::Point3f& corner);
	void create_cloud2(const Zeni::Point3f& corner);
	void create_cloud3(const Zeni::Point3f& corner);
	void create_cloud4(const Zeni::Point3f& corner);
	void create_cloud5(const Zeni::Point3f& corner);
};

#endif