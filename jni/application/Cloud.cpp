#include "Cloud.h"
#include "Solid_Terrain.h"
#include "Terrain_Factory.h"
#include <list>
#include <zenilib.h>

using namespace std;
using namespace Zeni;

Cloud::Cloud(const Point3f &corner_, int pattern_number)
{
	distance_traveled = 0.0f;
	max_distance = rand() % 3000 + 2000;
	switch(pattern_number)
	{
		case 0:
			create_cloud0(corner_);
			break;
      
		case 1:
			create_cloud1(corner_);
			break;
      
		case 2:
			create_cloud2(corner_);
			break;
      
		case 3:
			create_cloud3(corner_);
			break;
      
		case 4:
			create_cloud4(corner_);
			break;
      
		case 5:
			create_cloud5(corner_);
			break;
      
		default:
			//error
			break;
	}
}

Cloud::~Cloud() {
  for (auto it = cloud_blocks.begin(); it != cloud_blocks.end(); ++it)
    if (*it != nullptr) delete *it;
}

void Cloud::render()
{
	for (auto cloud_block : cloud_blocks)
		cloud_block -> render();
}

void Cloud::update(const float& time_step)
{
	for (auto cloud_block : cloud_blocks) {
		cloud_block -> set_corner(cloud_block -> get_corner() + time_step * 50 * Vector3f(-1.0f, 0.0f, 0.0f));
	}
	distance_traveled += time_step * 50;
}

void Cloud::create_cloud0(const Point3f& corner)
{
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 2, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 3, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 4, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 2, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
}

void Cloud::create_cloud1(const Point3f& corner)
{
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 2, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 3, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 4, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 6, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 7, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 8, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 6, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
}

void Cloud::create_cloud2(const Point3f& corner)
{
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
}

void Cloud::create_cloud3(const Point3f& corner)
{
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
}

void Cloud::create_cloud4(const Point3f& corner)
{
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 2, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 3, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 4, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 2, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE));
}

void Cloud::create_cloud5(const Point3f& corner)
{
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 6, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 7, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 8, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 4, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 6, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 6, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 9, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 9, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 9, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE));

	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 2, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 3, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 4, 0.0f, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(0.0f, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 2, CLOUD_LENGTH, CLOUD_HEIGHT), CLOUD_SIZE));
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE)); 
	cloud_blocks.push_back(create_terrain("Cloud", corner + Vector3f(CLOUD_LENGTH * 5, CLOUD_LENGTH * 2, CLOUD_HEIGHT), CLOUD_SIZE));
}