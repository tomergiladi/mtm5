#ifndef WARRIOR_H_
#define WARRIOR_H_
#include <string>
#include "mtm_exceptions.h"
#include "player.h"
#include "weapon.h"
class Warrior : public Player {
    bool isRider;

   public:
    Warrior(const std::string& name, const Weapon& weapon, bool isRider);
    virtual ~Warrior() override = default;
    Warrior(const Warrior& other) = default;
    Warrior& operator=(const Warrior& other) = default;
    void makeStep() override;
};
#endif
