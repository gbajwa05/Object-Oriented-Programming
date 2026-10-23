#ifndef RPG_H
#define RPG_H

#include <string>
using namespace std;

const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05f;
const int MAX_HITS_TAKEN = 3;

class RPG {
public:
    // Creates an RPG with default starting statistics.
    RPG();
    // Creates an RPG using the supplied statistics.
    RPG(string name, int hits_taken, float luck, float exp, int level);

    // Returns true while the RPG has taken fewer than MAX_HITS_TAKEN hits.
    bool isAlive() const;
    // Replaces the RPG's current number of hits taken.
    void setHitsTaken(int new_hits);
    string getName() const;
    int getHitsTaken() const;
    float getLuck() const;
    float getExp() const;
    int getLevel() const;

    // Extended functions required for Part Two.
    void setName(string name);
    void updateExpLevel();
    void attack(RPG *opponent);
    void printStats();
    ~RPG();

private:
    string name;
    int hits_taken;
    float luck;
    float exp;
    int level;
};

#endif
