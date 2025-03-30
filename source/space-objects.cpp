#include "../include/space-objects.h"

Planet::Planet(StarSystem* system) : star_system_(system),
                                        owner_(0),
                                        resource_(Planet::Resource(random() % 3)) {}

Planet::Planet(int8_t owner, StarSystem* system) : star_system_(system),
                                                    owner_(owner),
                                                    resource_(Planet::Resource(random() % 3)) {}

StarSystem::StarSystem(int8_t planet_cnt) : owner_(0) {
    planets_.resize(planet_cnt, nullptr);
    for (auto& planet : planets_) {
        planet = new Planet(this);
    }
}

StarSystem::~StarSystem() {
    for (auto& planet : planets_) {
        delete planet;
    }
}
