//
//  Map_Manager.h
//  game
//
//  Created by Donald Clark on 10/27/13.
//
//

#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include <zenilib.h>
#include <vector>
#include <map>
#include <string>

const int NUM_FILES = 4;

class Map_Manager {
  public:
    static Map_Manager& get_Instance();
    
    const int & get_files_left() const;
    
    bool empty() const;
    
    void reset();
  
    bool find_terrain(char c) const;
  
    const Zeni::String & get_terrain(char c) const;
  
    bool find_combo_terrain(char c) const;
  
    const std::pair<Zeni::String, Zeni::String> & get_combo_terrain(char c) const;
  
    bool find_placement_terrain(char c) const;
  
    const std::pair<Zeni::String, Zeni::String> & get_placement_terrain(char c) const;
  
    bool find_item(char c) const;
  
    const Zeni::String & get_item(char c) const;
  
    const std::string & get_common_room() const {return common_room;}
  
    const std::string & get_next();
    
    const std::string & get_previous();
  
  private:
    Map_Manager();
    
    int index;
    std::string common_room;
    std::vector<std::string> files;
    std::map<char, std::pair<Zeni::String, Zeni::String> > placement_terrain_charmap;
    std::map<char, std::pair<Zeni::String, Zeni::String> > combo_terrain_charmap;
    std::map<char, Zeni::String> terrain_charmap;
    std::map<char, Zeni::String> item_charmap;
};

#endif /* MAP_MANAGER_H */
