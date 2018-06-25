#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <map>
#include <memory>
#include "Player.h"
#include "Troll.h"
#include "Warrior.h"
#include "Wizard.h"
// enum that defines the possible error types returned from the game class
enum GameStatus {
    INVALID_PARAM,
    IllegalWeapon,
    NAME_ALREADY_EXISTS,
    GAME_FULL,
    NAME_DOES_NOT_EXIST,
    FIGHT_FAILED,
    SUCCESS
};
class Game {
    // the game private fields
    int maxPlayers;  // the maximum nuber of players int the game

    // players map where all players of the game are stored
    std::map<std::string, std::shared_ptr<Player>> players;
    // deletes all players from the current game
    void deletePlayers();
    GameStatus insertPlayer(const std::string& playerName,
                            std::shared_ptr<Player> ptr);

   public:
    // creates a new game with initial max players
    explicit Game(int maxPlayers);

    // copies an existing game with all of its fields and resources
    Game(const Game& game) = delete;

    // assignment operator. deletes all of the game resources and copies the new
    // game resources and fields.
    Game& operator=(const Game& game) = delete;

    // destroys the game resources
    ~Game() = default;

    // add a new player to the game, needs a player name and  a weapon name,
    // target, strength to create the player and t-he weapon and store them
    // return SUCCESS if no error were encountered
    // return NAME_ALREADY_EXISTS if the player is already in the game and
    // GAME_FULL if there is no room left for new players
    GameStatus addPlayer(const std::string& playerName,
                         const std::string& weaponName,
                         Target target,
                         int hit_strength);
    GameStatus addWizard(const std::string& playerName,
                         const std::string& weaponName,
                         Target target,
                         int hit_strength,
                         int range);
    GameStatus addWarrior(const std::string& playerName,
                          const std::string& weaponName,
                          Target target,
                          int hit_strength,
                          bool rider);
    GameStatus addTroll(const std::string& playerName,
                        const std::string& weaponName,
                        Target target,
                        int hit_strength,
                        int maxLife);

    // recieves a players name and if that player exist advances its level
    // return SUCCESS if no error were encountered
    // return NAME_DOES_NOT_EXIST if the player is not in the current game
    GameStatus nextLevel(const std::string& playerName);

    // recieves a players name and if that player exist advances its position
    // return SUCCESS if no error were encountered
    // return NAME_DOES_NOT_EXIST if the player is not in the current game
    GameStatus makeStep(const std::string& playerName);

    // recieves a players name and if that player exist advances its life by one
    // return SUCCESS if no error were encountered
    // return NAME_DOES_NOT_EXIST if the player is not in the current game
    GameStatus addLife(const std::string& playerName);

    // recieves a players name and if that player exist adds the given positive
    // int to its stength
    // return SUCCESS if no error were encountered
    // return NAME_DOES_NOT_EXIST if the player is not in the current game
    // return INVALID_PARAM if strengthToAdd is not positive
    GameStatus addStrength(const std::string& playerName, int strengthToAdd);

    // removes all players with weak weapon value from the game
    // return true if atleast one player was removed and false otherwise
    bool removeAllPlayersWithWeakWeapon(int weaponStrength);

    // calls the fight method between the two players and if one of them dies,
    // removes him from teh game
    // return NAME_DOES_NOT_EXIST if one of the players is not in the current
    // game
    // returns FIGHT_FAILED if the fight was not taken( the players are not in
    // the same position or their weapons value are the same)
    // return SUCCESS if the fight was successful
    GameStatus fight(const std::string& playerName1,
                     const std::string& playerName2);

    template <class FCN>
    bool removePlayersIf(FCN& fcn);

    // prints the game to the ostream given,
    // prints each player in a row the format player i :{player}
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};
#endif