#include "Weapon.h"
#include <string>
int Weapon::getTargetValue() const {
    switch (this->getTarget()) {
        case LEVEL: {
            return 1;
        }
        case STRENGTH: {
            return 2;
        }
        case LIFE: {
            return 3;
        }
        default: { return 0; }
    }
}
Weapon::Weapon(const std::string& name, Target target, int hit_strength)
    : name(name), target(target), hitStrength(hit_strength) {
}
Target Weapon::getTarget() const {
    return this->target;
}
int Weapon::getHitStrength() const {
    return this->hitStrength;
}
int Weapon::getValue() const {
    return this->getHitStrength() * this->getTargetValue();
}

bool operator>(const Weapon& weapon1, const Weapon& weapon2) {
    return weapon1.getValue() > weapon2.getValue();
}
bool operator<(const Weapon& weapon1, const Weapon& weapon2) {
    return weapon2 > weapon1;
}
bool operator==(const Weapon& weapon1, const Weapon& weapon2) {
    return !(weapon1 > weapon2 || weapon1 < weapon2);
}
bool operator!=(const Weapon& weapon1, const Weapon& weapon2) {
    return !(weapon1 == weapon2);
}

std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
    return os << "{weapon name: " << weapon.name
              << ", weapon value:" << weapon.getValue() << "}";
}