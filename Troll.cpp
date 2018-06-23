#include "Troll.h"

Troll::Troll(const std::string& name, const Weapon& weapon, int maxLife)
    : Player(name, weapon), maxLife(maxLife) {
}
void Troll::makeStep() {
    this->position += 2;
    this->addLife();
}
void Troll::addLife() {
    if (this->life < this->maxLife) {
        this->life++;
    }
}
