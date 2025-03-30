#pragma once

#include "include.h"


struct Cell {
   int32_t q, s, r;

   Cell() = default;
   Cell(int32_t q, int32_t s, int32_t r) {
      this->q = q;
      this->s = s;
      this->r = r;
   }

   bool isNextCell(const Cell& other);
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
   explicit StarSystem(int64_t id, int8_t planet_cnt,  const Cell& pos);
   ~StarSystem();

   // inline void addTerritoryCell(const Cell& cell);

   inline void setOwner(int8_t owner);
   void planetCaptured(int8_t capture_lvl_edit_);

 private:
   int64_t id_;
   int8_t owner_, capture_lvl_;
   Cell pos_;
   std::vector<Planet*> planets_;
   // std::vector<Cell> territory_; // I'll think about this feature
};
