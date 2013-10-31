//
//  Solid_Terrain.h
//  game
//
//  Created by Donald Clark on 10/30/13.
//
//

#ifndef SOLID_TERRAIN_H
#define SOLID_TERRAIN_H

#include "Terrain.h"
#include <zenilib.h>
#include <utility>
#include <map>

class Solid_Terrain : public Terrain {
  public:
    Solid_Terrain(const Zeni::String &model_,
                  const Zeni::Point3f &corner_ = Zeni::Point3f(0.0f, 0.0f, 0.0f),
                  const Zeni::Vector3f &scale_ = Zeni::Vector3f(1.0f, 1.0f, 1.0f),
                  const Zeni::Quaternion &rotation_ = Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));
    
    Solid_Terrain(const Solid_Terrain &rhs);
    
    Solid_Terrain & operator=(const Solid_Terrain &rhs);
    
    ~Solid_Terrain();
  
    const Zeni::String & get_model() const {return model;}
  
    virtual void render() override;
    
  private:
    static class Model_Manager {
      public:
        Model_Manager();
        
        ~Model_Manager();
        
        bool find_model(const Zeni::String &model_) const;
        
        Zeni::Model * get_model(const Zeni::String &model_);
        
        void load_model(const Zeni::String &model_);
        
        const unsigned long & get_instance_count(const Zeni::String &model_) const;
        
        void decrement_instance_count(const Zeni::String &model_);
        
        void increment_instance_count(const Zeni::String &model_);
        
      private:
        std::map<Zeni::String, std::pair<Zeni::Model*, unsigned long> > model_map;
    } model_manager;
  
    Zeni::String model;
};

#endif /* SOLID_TERRAIN_H */
