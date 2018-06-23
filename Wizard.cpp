#include "Wizard.h"

Wizard::Wizard(const std::string& name, const Weapon& weapon, int range)
    : Player(name, weapon), range(range) {
    if (weapon.getTarget() == LIFE) {
        throw mtm::IllegalWeapon();
    }
    if (range < 0) {
        throw mtm::InvalidParam();
    }
}
bool Wizard::canAttack(const Player& player) const {
    int distance = this->distanceFrom(player);
    return distance < this->range && distance > 0 &&
           this->isWeaponStronger(player);
}
