#include "Cloud.h"
#include "Solid_Terrain.h"
#include "Terrain_Factory.h"
#include <vector>
#include <zenilib.h>

using namespace std;
using namespace Zeni;

Cloud::Cloud(const Point3f &corner_, int pattern_number)
{
	switch(pattern_number)
	{
		case 0:
			create_cloud0(corner_);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			//error
			break;
	}
}

void Cloud::render()
{
	for(auto cloud_block : cloud_blocks)
		cloud_block -> render();
}

void Cloud::update(const float& time_step)
{
	for(auto cloud_block : cloud_blocks)
	{
		cloud_block -> set_corner(cloud_block -> get_corner() + time_step * 25 * Vector3f(-1.0f, 0.0f, 0.0f));
	}
}

//private functions to make different cloud shaptes

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

}

void Cloud::create_cloud2(const Point3f& corner)
{

}

void Cloud::create_cloud3(const Point3f& corner)
{

}

void Cloud::create_cloud4(const Point3f& corner)
{

}

void Cloud::create_cloud5(const Point3f& corner)
{

}