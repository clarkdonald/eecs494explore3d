//
//  Map_Manager.h
//  game
//
//  Created by Donald Clark on 10/27/13.
//
//

#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include <vector>
#include <map>
#include <string>

const int NUM_FILES = 1;

class Map_Manager {
  public:
    static Map_Manager& get_Instance();
    
    const int & get_files_left() const;
    
    bool empty() const;
    
    void reset();
    
    const std::string & get_next();
    
    const std::string & get_previous();
  
  private:
    Map_Manager();
    
    int index;
    std::vector<std::string> files;
};

#endif /* MAP_MANAGER_H */
