#include <iostream>
#include "RPG.h"
#include "Game.h"

using namespace std;

int main() {
    // Create the game and generate the required ten NPC players.
    Game game;
    int num_players = 10;
    game.generatePlayers(num_players);

    // Run the tournament and display the final statistics.
    game.gameLoop();
    game.printFinalResults();
    return 0;
}
