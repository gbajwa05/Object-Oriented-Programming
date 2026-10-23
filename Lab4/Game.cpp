#include "Game.h"
#include <iostream>
#include <iterator>
#include <random>
#include <string>

Game::Game() {}

/** Creates players named NPC_0 through NPC_(n-1) and marks them alive. */
void Game::generatePlayers(int n) {
    for (int i = 0; i < n; i++) {
        players.push_back(new RPG());
        string new_name = "NPC_" + to_string(i);
        players[i]->setName(new_name);
        live_players.insert(i);
    }
}

/** Randomly selects and returns one index from the live_players set. */
int Game::selectPlayer() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() - 1);

    int randomIndex = dist(gen);
    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);
    return *it;
}

/** Resets the winner, removes the loser, awards experience, and reports the result. */
void Game::endRound(RPG *winner, RPG *loser, int loserIndex) {
    winner->setHitsTaken(0);
    live_players.erase(loserIndex);
    winner->updateExpLevel();
    cout << winner->getName() << " won against " << loser->getName() << endl;
}

/**
 * Selects two different living players, lets them attack until one is dead,
 * and then completes the round using the surviving player as the winner.
 */
void Game::battleRound() {
    int playerIndex1 = selectPlayer();
    int playerIndex2 = selectPlayer();
    // A player cannot battle itself, so select a new pair if this happens.
    if (playerIndex1 == playerIndex2) {
        battleRound();
        return;
    }

    RPG *player1 = players[playerIndex1];
    RPG *player2 = players[playerIndex2];
    // Players take turns attacking while both are still alive.
    while (player1->isAlive() && player2->isAlive()) {
        player1->attack(player2);
        if (player2->isAlive()) {
            player2->attack(player1);
        }
    }

    if (player1->isAlive()) {
        endRound(player1, player2, playerIndex2);
    } else {
        endRound(player2, player1, playerIndex1);
    }
}

/** Repeats battles until the live player set contains only one player. */
void Game::gameLoop() {
    while (live_players.size() > 1) {
        battleRound();
    }
}

/** Prints the statistics for every player, including eliminated players. */
void Game::printFinalResults() {
    for (RPG *player : players) {
        player->printStats();
    }
}

/** Deletes every RPG pointer created by generatePlayers(). */
Game::~Game() {
    for (RPG *player : players) {
        delete player;
    }
}
