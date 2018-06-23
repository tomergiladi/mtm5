#ifndef TROLL_H_
#define TROLL_H_
#include <string>
#include "mtm_exceptions.h"
#include "player.h"
#include "weapon.h"
class Troll : public Player {
    int maxLife;

   public:
    Troll(const std::string& name, const Weapon& weapon, int maxLife);
    virtual ~Troll() override = default;
    Troll(const Troll& other) = default;
    Troll& operator=(const Troll& other) = default;
    void makeStep() override;
    void addLife() override;
};
#endif
