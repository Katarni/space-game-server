#include "include.h"

class Planet {
 public:
    enum class Resourse {
        Metal, Gold, Spice
    };

 private:
    Resourse resourse_;
    int8_t owner_;
};
