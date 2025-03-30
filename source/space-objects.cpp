#include "../include/space-objects.h"

bool Cell::isNextCell(const Cell& other) {
    if (q != other.q && r != other.r && s != other.s) {
        return false;
    }

    return q - other.q == other.r - r || q - other.q == other.s - s || r - other.r == other.s - s;
}

void Planet::setOwner(int8_t owner) {
    owner_ = owner;
}

void Planet::capture(int8_t new_owner) {
    int8_t lvl_edit = new_owner;
    if (owner_ != 0) {
        lvl_edit *= 2;
    }
    setOwner(new_owner);
    star_system_->planetCaptured(lvl_edit);
}

StarSystem::StarSystem(int64_t id, int8_t planet_cnt, const Cell& pos) : id_(id), owner_(0), capture_lvl_(0), pos_(pos) {
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

// void StarSystem::addTerritoryCell(const Cell& cell) {
//     territory_.push_back(cell);
// }

void StarSystem::setOwner(int8_t owner) {
    owner_ = owner;
    capture_lvl_ = planets_.size() * owner_;
    for (auto planet : planets_) {
        planet->setOwner(owner);
    }
}

void StarSystem::planetCaptured(int8_t capture_lvl_edit_) {
    capture_lvl_ += capture_lvl_edit_;
}