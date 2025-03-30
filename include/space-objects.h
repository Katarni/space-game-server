#pragma once

#include "include.h"

class StarSystem;

class Planet {
 public:
    enum class Resource {
        Metal, Gold, Spice
    };

    explicit Planet(StarSystem* system);
    Planet(int8_t owner, StarSystem* system);

 private:
    StarSystem* star_system_;
    Resource resource_;
    int8_t owner_;
};

class StarSystem {
 public:
    explicit StarSystem(int8_t planet_cnt);
    ~StarSystem();

 private:
    int8_t owner_;
    std::vector<Planet*> planets_;
};
