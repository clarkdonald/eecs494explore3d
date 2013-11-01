//
//  Game_State.cpp
//  game
//
//  Created by Donald Clark on 10/31/13.
//
//

#include "Game_State.h"
#include "Terrain_Factory.h"
#include "Terrain.h"
#include "Item_Factory.h"
#include "Item.h"
#include "Arrow.h"
#include "Utility.h"
#include "Skybox.h"
#include "Map_Manager.h"
#include "Monster_Manager.h"
#include "Cloud.h"
#include "White_Ghost.h"
#include <utility>
#include <fstream>
#include <map>
#include <vector>

using namespace Zeni;
using namespace Zeni::Collision;
using std::make_pair;
using std::string;
using std::getline;
using std::ifstream;
using std::bad_exception;
using std::to_string;
using std::map;
using std::vector;
using std::cerr;
using std::endl;

Game_State::Game_State(const std::string &file_)
: player(nullptr),
  spawn_timer(0.0f),
  done(false),
  monsters_killed(0)
{
  /** Load common room **/
  load_map(file_);
  level_type_e = ((file_ == "../assets/maps/common.txt") ? COMMON : GAME);
  
  /** Load BGM **/
  Sound &sr = get_Sound();
  sr.set_BGM("music/fortunedays");
  sr.set_BGM_looping(true);
  sr.play_BGM();
}

Game_State::~Game_State() {
  for (auto it = terrains.begin(); it != terrains.end(); ++it)
    if (*it != nullptr) delete *it;
  for (auto it = items.begin(); it != items.end(); ++it)
    if (*it != nullptr) delete *it;
  for (auto it = arrows.begin(); it != arrows.end(); ++it)
    if (*it != nullptr) delete *it;
  for (auto it = clouds.begin(); it != clouds.end(); ++it)
    if (*it != nullptr) delete *it;
  if (player != nullptr) delete player;
  get_Sound().stop_BGM();
}

bool Game_State::on_key(const SDL_KeyboardEvent &event) {
  switch(event.keysym.sym) {
    case SDLK_w:
      controls.forward = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_a:
      controls.left = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_s:
      controls.back = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_d:
      controls.right = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_e:
      controls.pickup_item = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_c:
      controls.drop_item = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_f:
      controls.use_item = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_SPACE:
      if (event.type == SDL_KEYDOWN) {
        player->jump();
        moved = true;
      }
      break;
      
    default:
      return false;
      break;
  }
  return true;
}

void Game_State::on_mouse_button(const SDL_MouseButtonEvent &event) {
  controls.shooting_arrow = event.state == SDL_PRESSED;
}

void Game_State::on_mouse_motion(const SDL_MouseMotionEvent &event) {
  player->adjust_pitch(event.yrel / 500.0f);
  player->turn_left_xy(-event.xrel / 500.0f);
}

void Game_State::perform_logic() {  
  const Time_HQ current_time = get_Timer_HQ().get_time();
  float processing_time = float(current_time.get_seconds_since(time_passed));
  time_passed = current_time;
  float time_step = processing_time;

  spawn_timer += time_step;

  if (spawn_timer >= 3.0f) {
	  spawn_timer = 0;
	  if(level_type_e == GAME)
		monsters.push_back(spawn_monster(player -> get_camera().position));
  }
  
  /** Move the clouds, delete them after a while so that new ones get formed **/
  for (auto it = clouds.begin(); it != clouds.end();) {
    (*it) -> update(time_step);
	  if((*it) -> is_done()) {
      delete(*it);
		  it = clouds.erase(it);
	  }
	  else it++;
  }

  while(clouds.size() < MAX_CLOUDS)
	clouds.push_back(new Cloud(Point3f(rand() % 5000, rand() % 5000, 0.0f), rand() % NUM_CLOUD_TYPES));
  
  /** Get forward and left vectors in the XY-plane **/
  const Vector3f forward = player->get_camera().get_forward().get_ij().normalized();
  const Vector3f left = player->get_camera().get_left().get_ij().normalized();
  
  /** Get velocity vector split into a number of axes **/
  const Vector3f velocity = (controls.forward - controls.back) * 70.0f * forward
    + (controls.left - controls.right) * 70.0f * left;
  const Vector3f x_vel = velocity.get_i();
  const Vector3f y_vel = velocity.get_j();
  Vector3f z_vel = player->get_velocity().get_k();
  
  /** Bookkeeping for sound effects **/
  if (velocity.magnitude() != 0.0f) moved = true;
  
  /** Keep delays under control (if the program hangs for some time, we don't want to lose responsiveness) **/
  if (processing_time > 0.1f) processing_time = 0.1f;
  
  /** Physics processing loop **/
  for (float time_step = 0.05f; processing_time > 0.0f; processing_time -= time_step) {
    if (time_step > processing_time) time_step = processing_time;
    
    /** Gravity has its effect **/
    z_vel -= Vector3f(0.0f, 0.0f, 100.0f * time_step);
    
    /** Try to move on each axis **/
    partial_step(time_step, x_vel);
    partial_step(time_step, y_vel);
    partial_step(time_step, z_vel);

    /** Keep player above ground; Bookkeeping for jumping controls **/
    const Point3f &position = player->get_camera().position;
    if (position.z < 50.0f) {
      player->set_position(Point3f(position.x, position.y, 50.0f));
      player->set_on_ground(true);
    }
  }
  
  /** Logic for items **/
//    if (controls.drop_item) {
//      Item* item = player->drop_item();
//      Point3f pos = Point3f(player->get_camera().position.x,
//                            player->get_camera().position.y,
//                            player->get_camera().position.z - CAMERA_HEIGHT);
//      item->set_corner(pos);
//      items.push_back(item);
//    }
  if (controls.use_item) {
    if (!use_timer.is_running()) {
      if (player->can_lift()) {
        if (player->is_lifting_terrain()) {
          Terrain* terrain = player->drop_terrain();
          Point3f pos = Point3f(player->get_camera().position.x,
                                player->get_camera().position.y,
                                player->get_camera().position.z - CAMERA_HEIGHT + 5.0f);
          terrain->set_corner(pos);
          terrains.push_back(terrain);
        }
        else {
          for (auto it = terrains.begin(); it != terrains.end(); ++it) {
            if ((*it)->is_portable()) {
              if ((*it)->get_body().intersects(player->get_body())) {
                player->set_terrain(*it);
                terrains.erase(it);
                break;
              }
            }
          }
        }
      }
      use_timer.reset();
      use_timer.start();
    }
    else if (use_timer.seconds() > 0.3f) use_timer.stop();
  }
  if (controls.pickup_item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
      if ((*it)->get_body().intersects(player->get_body())) {
        player->set_item(*it);
        delete *it;
        items.erase(it);
        break;
      }
    }
  }

  /** Have monsters run their AI. delete them if they are dead. **/
  for (auto it = monsters.begin(); it != monsters.end();) {
	  (*it) -> update(time_step, player->get_camera().position);
	  if ((*it) -> is_dead()) {
		  delete (*it);
		  it = monsters.erase(it);
		  monsters_killed++;
	  }
	  else it++;
  }

  /** Logic for shooting arrows **/
  if (!shooting_timer.is_running()) {
    if (controls.shooting_arrow) arrows.push_back(player->fire());
    shooting_timer.reset();
    shooting_timer.start();
  }
  else if (shooting_timer.seconds() > 0.3f) shooting_timer.stop();

  /** Logic to update arrows **/
  for (auto it = arrows.begin(); it != arrows.end();) {
	  bool is_done = false;
    for (auto monster : monsters) {
      if ((*it)->get_body().intersects(monster->get_body())) {
        monster -> take_damage(1);
        is_done = true;
      }
    }

    if (is_done || (*it)->get_distance_traveled() > 4000.0f) {
      delete *it;
      it = arrows.erase(it);
    }
    else {
      (*it)->update(time_step);
      it++;
    }
  }
}

void Game_State::render(){
  if (done) return;
  
  /** Render 3D stuff **/
  Video &vr = get_Video();
  vr.set_3d(player->get_camera());
  render_skybox(player -> get_camera());
  for (auto cloud : clouds) cloud->render();
  for(auto monster : monsters) monster -> render();
  for (auto arrow : arrows) arrow->render();
  for (auto terrain : terrains) terrain->render();
  for (auto item : items) item->render();
  
  /** Render 2D stuff **/
  vr.set_2d(VIDEO_DIMENSION, true);
  crosshair.render(player->is_wielding_weapon(), player->get_health(), monsters_killed);
  vr.clear_depth_buffer();
}

void Game_State::partial_step(const float &time_step, const Vector3f &velocity) {
  player->set_velocity(velocity);
  const Point3f backup_position = player->get_camera().position;
  
  player->step(time_step);
  
  /** If collision with terrain has occurred, roll things back **/
  for (auto it = terrains.begin(); it != terrains.end(); ++it) {
    if ((*it)->get_body().intersects(player->get_body())) {
      if ((*it)->is_portal()) done = true;
      else if (player->can_walk_through_terrain() && !(*it)->is_fire()) continue;
      else if (player->can_walk_through_fire() && (*it)->is_fire()) continue;
      
      if (moved) {
        /** Play a sound if possible **/
        (*it)->collide();
        moved = false;
      }
      
      player->set_position(backup_position);
      
      /** Bookkeeping for jumping controls **/
      if (velocity.k < 0.0f) player->set_on_ground(true);
    }
  }
  
  /** Logic for collision between mosnter and player **/
  for (auto monster : monsters) {
	  if (monster->get_body().intersects(player->get_body())) {
      // TODO: We can't let the monsters move us back into a terrain, big glitch
		  player->set_position(player->get_camera().position + player->get_camera().get_forward() * -100);
		  player->take_damage(monster -> get_damage());
	  }
  }
}

/**
 * Checks to see if blocks can be arranged in a concave manner to save memory.
 */
bool check_concavity(const vector< vector<int> > &topology, int y, int x) {
  if (y <= 0 || y >= (topology.size()-1) || x <= 0 || x >= (topology[y].size()-1)) {
    return false;
  }
  
  /** Logic for concavity of each tile **/
  if (topology[y][x] <= topology[y+1][x] &&
      topology[y][x] <= topology[y-1][x] &&
      topology[y][x] <= topology[y][x+1] &&
      topology[y][x] <= topology[y][x-1])
  {
    return true;
  }
  
  return false;
}

void Game_State::load_map(const std::string &file_) {
  ifstream file(file_);
  int start_x, start_y, item_count;
  
  /** Check if file exists, and get dimensions of map **/
  if (!file.is_open()) throw new bad_exception;
  if (!(file >> dimension.height)) throw new bad_exception;
  if (!(file >> dimension.width)) throw new bad_exception;
  
  /** Receive starting location of Explorer **/
  if (!(file >> start_y)) throw new bad_exception;
  if (start_y < 0 || start_y >= dimension.height) throw new bad_exception;
  if (!(file >> start_x)) throw new bad_exception;
  if (start_x < 0 || start_x >= dimension.width) throw new bad_exception;
  
  /** Receive Item Count from text file **/
  if (!(file >> item_count)) throw new bad_exception;
  
  string line;
  getline(file,line); // waste comment
  if (line.find('#') != std::string::npos) throw new bad_exception;
  getline(file,line); // waste a newline
  
  /** Read items on the map **/
  for (int i = 0; i < item_count; ++i) {
    char item_char;
    if (!(file >> item_char)) throw new bad_exception;
    
    int z;
    if (!(file >> z)) throw new bad_exception;
    
    int y;
    if (!(file >> y)) throw new bad_exception;
    if (y < 0 || y >= dimension.height) throw new bad_exception;
    
    int x;
    if (!(file >> x)) throw new bad_exception;
    if (x < 0 || x >= dimension.width) throw new bad_exception;
    
    items.push_back(
      create_item(Map_Manager::get_Instance().get_item(item_char),
        Point3f(UNIT_LENGTH*x, UNIT_LENGTH*y, UNIT_LENGTH*z), ITEM_SIZE));
  }
  
  vector< vector<int> > topology(dimension.height, vector<int>(dimension.width, 0));
  getline(file,line); // waste a newline
  
  /** Read topology from text file **/
  for (int height = 0; getline(file,line) && height < dimension.height;) {
    if (line.find('#') != std::string::npos) continue;
    for (int width = 0; width < line.length() && width < dimension.width; ++width) {
      topology[height][width] = line[width] - '0';
    }
    ++height;
  }
  
  /** Read terrain from text file **/
  for (int height = 0; getline(file,line) && height < dimension.height;) {
    if (line.find('#') != std::string::npos) continue;
    for (int width = 0; width < line.length() && width < dimension.width; ++width) {
      //std::cout << height << ' ' << width << std::endl;
      /** check each terrain/item type and place them **/
      if (line[width] == '.');
      else if (Map_Manager::get_Instance().find_terrain(line[width])) {
        if (topology[height][width] > 1 && check_concavity(topology,height,width)) {
          if (Map_Manager::get_Instance().find_combo_terrain(line[width])) {
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_combo_terrain(line[width]).first,
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*(topology[height][width]-1)), MEDIUM_SIZE));
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_combo_terrain(line[width]).second,
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*topology[height][width]-SKINNY_HEIGHT), SKINNY_SIZE));
          }
          else if (Map_Manager::get_Instance().find_placement_terrain(line[width])) {
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_placement_terrain(line[width]).first,
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*(topology[height][width]-1))));
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_placement_terrain(line[width]).second,
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*topology[height][width])));
          }
          else {
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_terrain(line[width]),
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, 0.0f), SKINNY_SIZE));
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_terrain(line[width]),
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*(topology[height][width]-1))));
          }
        }
        else if (Map_Manager::get_Instance().find_combo_terrain(line[width])) {
          int i = 0;
          for (; i < (topology[height][width]-1); ++i) {
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_combo_terrain(line[width]).first,
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*i)));
          }
          terrains.push_back(
            create_terrain(Map_Manager::get_Instance().get_combo_terrain(line[width]).first,
              Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*(i++)), MEDIUM_SIZE));
          terrains.push_back(
            create_terrain(Map_Manager::get_Instance().get_combo_terrain(line[width]).second,
              Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*i-SKINNY_HEIGHT), SKINNY_SIZE));
        }
        else if (Map_Manager::get_Instance().find_placement_terrain(line[width])) {
          int i = 0;
          for (; i < topology[height][width]; ++i) {
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_placement_terrain(line[width]).first,
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*i)));
          }
          terrains.push_back(
            create_terrain(Map_Manager::get_Instance().get_placement_terrain(line[width]).second,
              Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*i)));
        }
        else {
          for (int i = 0; i < topology[height][width]; ++i) {
            terrains.push_back(
              create_terrain(Map_Manager::get_Instance().get_terrain(line[width]),
                Point3f(UNIT_LENGTH*width, UNIT_LENGTH*height, UNIT_LENGTH*i)));
          }
        }
      }
      else {
        throw new bad_exception;
      }
    }
    ++height;
  }
  
  /** Make sure we aren't placing a player inside a terrain **/
  if (topology[start_y][start_x] > 1 && !check_concavity(topology,start_y,start_x))
    throw new bad_exception;
  player = new Player(Camera(Point3f(UNIT_LENGTH*start_x, UNIT_LENGTH*start_y, CAMERA_HEIGHT),
                             Quaternion(), 1.0f, 10000.0f), Vector3f(0.0f, 0.0f, -39.0f), 11.0f);
  
  /** Spawn cloud **/
  while(clouds.size() < MAX_CLOUDS)
	clouds.push_back(new Cloud(Point3f(rand() % 5000, rand() % 5000, 0.0f), rand() % NUM_CLOUD_TYPES));

  
  /** spawn 5 ghosts **/
  //for(int k = 0; k < 5; k++)
	//monsters.push_back(spawn_monster(player -> get_camera().position));


  file.close();
}
