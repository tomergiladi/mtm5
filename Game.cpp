#include "Game.h"
#include <algorithm>
using std::endl;
using std::map;
using std::ostream;
using std::shared_ptr;
using std::string;
void Game::deletePlayers() {
    /*for (int i = 0; i < this->currentPlayers; i++) {
        delete this->players[i];
    }
    delete[] this->players;*/
}
Game::Game(int maxPlayers) : maxPlayers(maxPlayers), players() {
}
GameStatus Game::insertPlayer(const string& playerName,
                              shared_ptr<Player> ptr) {
    if (this->players.find(playerName) != this->players.end()) {
        return NAME_ALREADY_EXISTS;
    }
    if (this->players.size() >= this->maxPlayers) {
        return GAME_FULL;
    }
    try {
        this->players.insert(
            std::pair<string, shared_ptr<Player>>(playerName, ptr));
    } catch (mtm::IllegalWeapon exception) {
        return IllegalWeapon;
    }
    return SUCCESS;
}
GameStatus Game::addPlayer(const string& playerName,
                           const string& weaponName,
                           Target target,
                           int hit_strength) {
    if (this->players.find(playerName) != this->players.end()) {
        return NAME_ALREADY_EXISTS;
    }
    if (this->players.size() >= this->maxPlayers) {
        return GAME_FULL;
    }
    try {
        this->players.insert(std::pair<string, shared_ptr<Player>>(
            playerName,
            new Warrior(playerName, Weapon(weaponName, target, hit_strength),
                        false)));
    } catch (mtm::IllegalWeapon exception) {
        return IllegalWeapon;
    }
    return SUCCESS;
}
GameStatus Game::addWizard(const string& playerName,
                           const string& weaponName,
                           Target target,
                           int hit_strength,
                           int range) {
    try {
        return this->insertPlayer(
            playerName,
            std::make_shared<Wizard>(
                playerName, Weapon(weaponName, target, hit_strength), range));
    } catch (mtm::IllegalWeapon exception) {
        return IllegalWeapon;
    }
    return SUCCESS;
}
GameStatus Game::addWarrior(const string& playerName,
                            const string& weaponName,
                            Target target,
                            int hit_strength,
                            bool rider) {
    try {
        return this->insertPlayer(
            playerName,
            std::make_shared<Warrior>(
                playerName, Weapon(weaponName, target, hit_strength), rider));
    } catch (mtm::IllegalWeapon exception) {
        return IllegalWeapon;
    }
    return SUCCESS;
}
GameStatus Game::addTroll(const string& playerName,
                          const string& weaponName,
                          Target target,
                          int hit_strength,
                          int maxLife) {
    try {
        return this->insertPlayer(
            playerName,
            std::make_shared<Troll>(
                playerName, Weapon(weaponName, target, hit_strength), maxLife));
    } catch (mtm::IllegalWeapon exception) {
        return IllegalWeapon;
    }
    return SUCCESS;
}
GameStatus Game::nextLevel(const string& playerName) {
    if (this->players.find(playerName) == this->players.end()) {
        return NAME_DOES_NOT_EXIST;
    }
    this->players[playerName]->nextLevel();
    return SUCCESS;
}
GameStatus Game::makeStep(const string& playerName) {
    if (this->players.find(playerName) == this->players.end()) {
        return NAME_DOES_NOT_EXIST;
    }
    this->players[playerName]->makeStep();
    return SUCCESS;
}
GameStatus Game::addLife(const string& playerName) {
    if (this->players.find(playerName) == this->players.end()) {
        return NAME_DOES_NOT_EXIST;
    }
    this->players[playerName]->addLife();
    return SUCCESS;
}
GameStatus Game::addStrength(const string& playerName, int strengthToAdd) {
    if (strengthToAdd < 0) {
        return INVALID_PARAM;
    }
    if (this->players.find(playerName) == this->players.end()) {
        return NAME_DOES_NOT_EXIST;
    }
    this->players[playerName]->addStrength(strengthToAdd);
    return SUCCESS;
}
class PlayerIsWeak {
    int strength;

   public:
    explicit PlayerIsWeak(int strength) : strength(strength) {
    }
    bool operator()(const Player& player) {
        ((Player&)player).makeStep();
        return player.weaponIsWeak(strength);
    }
};
bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    PlayerIsWeak playerIsWeak(weaponStrength);
    return this->removePlayersIf(playerIsWeak);
}
GameStatus Game::fight(const string& playerName1, const string& playerName2) {
    if (this->players.find(playerName1) == this->players.end() ||
        this->players.find(playerName2) == this->players.end()) {
        throw mtm::NameDoesNotExist();
    }
    bool fightSuccess =
        this->players[playerName1]->fight(*(this->players[playerName2]));
    if (!this->players[playerName1]->isAlive()) {
        this->players.erase(playerName1);
    }
    if (!this->players[playerName2]->isAlive()) {
        this->players.erase(playerName2);
    }
    return fightSuccess ? SUCCESS : FIGHT_FAILED;
}
template <class FCN>
bool Game::removePlayersIf(FCN& fcn) {
    bool result = false;
    for (map<string, shared_ptr<Player>>::const_iterator it =
             this->players.begin();
         it != this->players.end(); it++) {
        if (fcn(static_cast<const Player&>(*it->second))) {
            it = this->players.erase(it);
            result = true;
        }
    }
    return result;
}
ostream& operator<<(ostream& os, const Game& game) {
    int i = 0;
    for (map<string, shared_ptr<Player>>::const_iterator it =
             game.players.begin();
         it != game.players.end(); it++, i++) {
        os << "player " << (i) << ": " << *(it->second) << "," << endl;
    }
    return os;
}