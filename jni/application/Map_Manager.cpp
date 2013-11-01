//
//  Map_Manager.cpp
//  game
//
//  Created by Donald Clark on 10/27/13.
//
//

#include "Map_Manager.h"
#include "Utility.h"
#include <zenilib.h>

using namespace Zeni;
using std::string;
using std::cerr;
using std::endl;
using std::bad_exception;
using std::map;
using std::make_pair;
using std::pair;

Map_Manager& Map_Manager::get_Instance()
{
  static Map_Manager Map_Manager;
  return Map_Manager;
}

Map_Manager::Map_Manager()
: index(0), common_room("../assets/maps/common.txt")
{
  for (int i = 0; i < NUM_FILES; ++i) {
    string str = "../assets/maps/level" + std::to_string(i) + ".txt";
    files.push_back(str);
  }
  
  /** load the character mapping for combo terrains **/
  combo_terrain_charmap['g'] = make_pair("Dirt", "Grass");
  
  /** load the character mapping for placement terrains **/
  placement_terrain_charmap['C'] = make_pair("Stone", "Crate");
  placement_terrain_charmap['p'] = make_pair("Stone", "Portal");

  /** load the character mapping for terrains **/
  terrain_charmap['c'] = "Concrete";
  terrain_charmap['g'] = "Grass";
  terrain_charmap['s'] = "Stone";
  terrain_charmap['d'] = "Dirt";
  terrain_charmap['S'] = "Sand";
  terrain_charmap['y'] = "Cloud";
  terrain_charmap['w'] = "Water";
  terrain_charmap['C'] = "Crate";
  terrain_charmap['p'] = "Portal";
  terrain_charmap['f'] = "Fire";
  terrain_charmap['b'] = "Brick";

  /** load the character mapping for items **/
  item_charmap['l'] = "Leg";
  item_charmap['g'] = "Ghost";
  item_charmap['f'] = "Fire";
  item_charmap['s'] = "Strength";
}

const int & Map_Manager::get_files_left() const {
  return index;
}

bool Map_Manager::empty() const {
  return (files.size() - index) <= 0;
}

void Map_Manager::reset() {
  index = 0;
}

bool Map_Manager::find_terrain(char c) const {
  return terrain_charmap.find(c) != terrain_charmap.end();
}

const String & Map_Manager::get_terrain(char c) const {
  map<char, String>::const_iterator it;
  if ((it = terrain_charmap.find(c)) == terrain_charmap.end())
    throw new bad_exception;
  return it->second;
}

bool Map_Manager::find_combo_terrain(char c) const {
  return combo_terrain_charmap.find(c) != combo_terrain_charmap.end();
}

const std::pair<String, String> & Map_Manager::get_combo_terrain(char c) const {
  map<char, pair<String, String> >::const_iterator it;
  if ((it = combo_terrain_charmap.find(c)) == combo_terrain_charmap.end())
    throw new bad_exception;
  return it->second;
}

bool Map_Manager::find_placement_terrain(char c) const {
  return placement_terrain_charmap.find(c) != placement_terrain_charmap.end();
}

const pair<String, String> & Map_Manager::get_placement_terrain(char c) const {
  map<char, pair<String, String> >::const_iterator it;
  if ((it = placement_terrain_charmap.find(c)) == placement_terrain_charmap.end())
    throw new bad_exception;
  return it->second;
}

bool Map_Manager::find_item(char c) const {
  return item_charmap.find(c) != item_charmap.end();
}

const String & Map_Manager::get_item(char c) const {
  map<char, String>::const_iterator it;
  if ((it = item_charmap.find(c)) == item_charmap.end())
    throw new bad_exception;
  return it->second;
}

const std::string & Map_Manager::get_next() {
  if (empty()) throw new bad_exception();
  return files[index++];
}

const std::string & Map_Manager::get_previous() {
  if (index == 0) throw new bad_exception;
  --index;
  return files[index++];
}
