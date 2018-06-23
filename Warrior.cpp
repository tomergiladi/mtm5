#include "Warrior.h"

Warrior::Warrior(const std::string& name, const Weapon& weapon, bool isRider)
    : Player(name, weapon), isRider(isRider) {
    if (weapon.getTarget() == LEVEL) {
        throw mtm::IllegalWeapon();
    }
}
void Warrior::makeStep() {
    this->position += this->isRider ? 5 : 1;
}
