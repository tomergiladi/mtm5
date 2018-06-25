#include "Game.H"
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
    Game game(20);
    game.addPlayer("tomer", "the weapon", LIFE, 200);
    game.addPlayer("tomer2", "the weapon", LEVEL, 200);
    game.addPlayer("tomer3", "the weapon", STRENGTH, 200);
    game.addLife("tomer");
    game.addStrength("tomer", 5);
    game.addWizard("wizTomer", "wep", LIFE, 400, 4);
    game.addWizard("wizTomer", "wep", LEVEL, 10000, 4);
    game.addWarrior("warTomer", "wep", LIFE, 400, true);
    game.fight("wizTomer", "warTomer");
    game.makeStep("wizTomer");
    game.fight("wizTomer", "warTomer");
    game.removeAllPlayersWithWeakWeapon(100);
    std::cout << game << std::endl;
}