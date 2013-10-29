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

const std::string & Map_Manager::get_next() {
  if (empty()) throw new bad_exception();
  return files[index++];
}

const std::string & Map_Manager::get_previous() {
  if (index == 0) throw new bad_exception;
  --index;
  return files[index++];
}
