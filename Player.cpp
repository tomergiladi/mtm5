#include "Player.h"
void Player::subtructWithMin(int& number, int subructBy, int minimum) {
    number -= subructBy;
    // make sure that after the substruction, the number is at least minimum
    if (number < minimum) {
        number = minimum;
    }
}
int Player::distanceFrom(const Player& player) const {
    return abs(this->position - player.position);
}
bool Player::canAttack(const Player& player) const {
    return this->distanceFrom(player) == 0 && this->isWeaponStronger(player);
}
void Player::attack(Player& player) const {
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
}
bool Player::isWeaponStronger(const Player& player) const {
    return this->weapon > player.weapon;
}
Player::Player(const std::string& name, const Weapon& weapon)
    : name(name), level(1), life(1), strength(1), weapon(weapon), position(0) {
}
Player::~Player() {
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

bool Player::weaponIsWeak(int weaponMinStrength) const {
    return this->weapon.getValue() < weaponMinStrength;
}
std::ostream& operator<<(std::ostream& os, const Player& player) {
    return os << "{player name: " << player.name
              << ", weapon: " << player.weapon << "}";
}
bool Player::fight(Player& player) {
    if (this->canAttack(player)) {
        this->attack(player);
        return true;
    }
    if (player.canAttack(*this)) {
        player.attack(*this);
        return true;
    }
    return false;
}
bool operator>(const Player& player1, const Player& player2) {
    return player1.name > player2.name;
}
bool operator<(const Player& player1, const Player& player2) {
    return player2 > player1;
}