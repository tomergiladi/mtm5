#include "Player.h"
int Player::distanceFrom(const Player& player) const {
    return abs(this->position - player.position);
}
bool Player::canAttack(const Player& player) const {
    return this->distanceFrom(player) == 0;
}
Player::Player(const std::string& name, const Weapon& weapon)
    : name(name), level(1), life(1), strength(1), weapon(weapon), position(0) {
}
void Player::nextLevel() {
    this->level++;
}
bool Player::isPlayer(const std::string& playerName) const {
    return this->name == playerName;
}
void Player::makeStep() {
    this->position++;
}
void Player::addLife() {
    this->life++;
}
void Player::addStrength(int strengthToAdd) {
    this->strength += strengthToAdd;
}
bool Player::isAlive() const {
    return this->level > 0 && this->life > 0 && this->strength > 0;
}
bool Player::operator>(const Player& other) const {
    // std::cout << this->name << other.name << (strcmp(this->name,
    // other.name));
    this->name > other.name;
}
bool Player::weaponIsWeak(int weaponMinStrength) const {
    return this->weapon.getValue() < weaponMinStrength;
}
bool Player::operator<(const Player& other) const {
    return other > *this;
}
std::ostream& operator<<(std::ostream& os, const Player& player) {
    return os << "{player name: " << player.name
              << ", weapon: " << player.weapon << "}";
}
void Player::subtructWithMin(int& number, int subructBy, int minimum) {
    number -= subructBy;
    if (number < minimum) {
        number = minimum;
    }
}
bool Player::fight(Player& player) {
    if (this->weapon == player.weapon) {
        return false;
    }
    if (player.weapon > this->weapon) {
        return player.fight(*this);
    }
    int hitStrength = this->weapon.getHitStrength();
    switch (this->weapon.getTarget()) {
        case LEVEL: {
            Player::subtructWithMin(player.level, hitStrength);
            break;
        }
        case STRENGTH: {
            Player::subtructWithMin(player.strength, hitStrength);
            break;
        }
        case LIFE: {
            Player::subtructWithMin(player.life, hitStrength);
            break;
        }
    }
    return true;
}