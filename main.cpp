#include "Player.h"
#include "Troll.h"
#include "Warrior.h"
#include "Wizard.h"
int main() {
    Warrior w2("Tomer", Weapon("the wep", LIFE, 70), true);
    Wizard w("Tomer", Weapon("the wep", STRENGTH, 60), 3);
    Player& rw = w;
    Player& rw2 = w2;
    Troll t("Tomer", Weapon("the wep", STRENGTH, 60), 3);
    Player& rt = t;
    rt.addLife();
    // rw2 = rw;
    w.makeStep();
    std::cout << (w2.fight(w)) << std::endl;
    rw2.addStrength(70);
    std::cout << (rw.fight(w2)) << std::endl;
}