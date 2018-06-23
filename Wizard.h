#ifndef WIZARD_H_
#define WIZARD_H_
#include <string>
#include "mtm_exceptions.h"
#include "player.h"
#include "weapon.h"
class Wizard : public Player {
    int range;
    bool canAttack(const Player& player) const override;

   public:
    Wizard(const std::string& name, const Weapon& weapon, int range);
    virtual ~Wizard() override = default;
    Wizard(const Wizard& other) = default;
    Wizard& operator=(const Wizard& other) = default;
};
#endif
