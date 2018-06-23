#ifndef PLAYER_H_
#define PLAYER_H_
#include <math.h>
#include <string>
#include "Weapon.h"
#include "iostream"
class Player {
    const std::string name;
    int level;
    int life;
    int strength;
    const Weapon weapon;
    int position;

    static void subtructWithMin(int& number, int subtructBy, int minimum = 0);

   protected:
    int distanceFrom(const Player& player) const;
    virtual bool canAttack(const Player& player) const;

   public:
    explicit Player(const std::string& name, const Weapon& weapon);
    virtual ~Player() = default;
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    void nextLevel();
    bool isPlayer(const std::string& playerName) const;
    void makeStep();
    void addLife();
    void addStrength(int strengthToAdd);
    bool isAlive() const;
    bool weaponIsWeak(int weaponMinStrength) const;
    bool operator>(const Player& other) const;
    bool operator<(const Player& other) const;
    bool fight(Player& player);
};
#endif