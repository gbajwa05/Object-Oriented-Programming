#ifndef GAME_H
#define GAME_H

#include "RPG.h"
#include <set>
#include <vector>
using namespace std;

class Game {
public:
    // Creates an empty game.
    Game();
    // Creates n players and records all of them as alive.
    void generatePlayers(int n);
    // Randomly returns the index of one living player.
    int selectPlayer();
    // Removes the loser and updates the winner after a round.
    void endRound(RPG *winner, RPG *loser, int loserIndex);
    // Runs one battle between two randomly selected players.
    void battleRound();
    // Continues battles until only one player remains alive.
    void gameLoop();
    // Prints the final statistics for every player.
    void printFinalResults();
    // Releases the dynamically allocated RPG objects.
    ~Game();

private:
    vector<RPG *> players;
    set<int> live_players;
};

#endif
