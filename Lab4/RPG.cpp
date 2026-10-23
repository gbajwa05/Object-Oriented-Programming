#include "RPG.h"
#include <cstdio>
#include <random>

// Default RPG starts alive with beginner-level statistics.
RPG::RPG() : name(""), hits_taken(0), luck(0.1f), exp(0.0f), level(1) {}

RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
    : name(name), hits_taken(hits_taken), luck(luck), exp(exp), level(level) {}

void RPG::setHitsTaken(int new_hits) { hits_taken = new_hits; }
bool RPG::isAlive() const { return hits_taken < MAX_HITS_TAKEN; }
string RPG::getName() const { return name; }
int RPG::getHitsTaken() const { return hits_taken; }
float RPG::getLuck() const { return luck; }
float RPG::getExp() const { return exp; }
int RPG::getLevel() const { return level; }

void RPG::setName(string new_name) { name = new_name; }

/**
 * Adds 50 experience points. Once experience reaches 100, the RPG
 * levels up, its experience resets, and its luck increases.
 */
void RPG::updateExpLevel() {
    exp += 50.0f;
    if (exp >= 100.0f) {
        ++level;
        exp = 0.0f;
        luck += 0.1f;
    }
}

/**
 * Attempts to hit an opponent. A random value is compared with the
 * opponent's luck; a successful hit increases the opponent's hit count.
 */
void RPG::attack(RPG *opponent) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);
    float random_num = dis(gen);

    // Higher luck slightly increases the chance that the attack misses.
    bool hit = random_num > HIT_FACTOR * opponent->getLuck();
    if (hit) {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}

/** Prints the RPG's current statistics and alive/dead status. */
void RPG::printStats() {
    printf("Name: %-8s Hits Taken: %d  Luck: %.6f  Exp: %.6f  Level: %d  Status: %s\n",
           name.c_str(), hits_taken, luck, exp, level,
           isAlive() ? "Alive" : "Dead");
}

RPG::~RPG() {}
