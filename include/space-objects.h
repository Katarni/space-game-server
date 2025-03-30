#pragma once

#include "include.h"


struct Point {
   int32_t x, y;

   Point() = default;
   Point(int32_t x, int32_t y) {
      this->x = x;
      this->y = y;
   }
};


class StarSystem;


class Planet {
public:
   enum class Resource {
      Metal, Gold, Spice
   };

   explicit Planet(StarSystem* system) : star_system_(system), owner_(0),
                                          resource_(Planet::Resource(random() % 3)),
                                          resource_cnt_(random() % 8 + 1) {}

   Planet(int8_t owner, StarSystem* system) : star_system_(system), owner_(owner),
                                             resource_(Planet::Resource(random() % 3)),
                                             resource_cnt_(random() % 8 + 1) {}

   inline void setOwner(int8_t owner);
   void capture(int8_t new_owner);

 private:
   StarSystem* star_system_;
   Resource resource_;
   int8_t owner_, radius_, speed_, resource_cnt_;
};


class StarSystem {
 public:
   explicit StarSystem(int64_t id, int8_t planet_cnt,  const Point& pos);
   ~StarSystem();

   inline void addTerritoryPoint(const Point& point);

   inline void setOwner(int8_t owner);
   void planetCaptured(int8_t capture_lvl_edit_);

 private:
   int64_t id_;
   int8_t owner_, capture_lvl_;
   Point pos_;
   std::vector<Planet*> planets_;
   std::vector<Point> territory_;
};
