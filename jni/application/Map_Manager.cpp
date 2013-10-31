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

Map_Manager& Map_Manager::get_Instance()
{
  static Map_Manager Map_Manager;
  return Map_Manager;
}

Map_Manager::Map_Manager()
: index(0)
{
  for (int i = 0; i < NUM_FILES; ++i) {
    string str = "../assets/maps/level" + std::to_string(i) + ".txt";
    files.push_back(str);
  }
  
  /** load the character mapping for terrains **/
  terrain_charmap['c'] = "Concrete";
  terrain_charmap['g'] = "Grass";
  terrain_charmap['s'] = "Stone";
  terrain_charmap['G'] = "Ground";
  terrain_charmap['C'] = "Crate";

  /** load the character mapping for items **/
  item_charmap['b'] = "Bullet";
  item_charmap['p'] = "Potion";
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

const Zeni::String & Map_Manager::get_terrain(char c) const {
  map<char, Zeni::String>::const_iterator it;
  if ((it = terrain_charmap.find(c)) == terrain_charmap.end())
    throw new bad_exception;
  return it->second;
}

bool Map_Manager::find_item(char c) const {
  return item_charmap.find(c) != item_charmap.end();
}

const Zeni::String & Map_Manager::get_item(char c) const {
  map<char, Zeni::String>::const_iterator it;
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
