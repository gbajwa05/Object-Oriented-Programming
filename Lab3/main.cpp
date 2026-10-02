//main.cpp
#include <iostream>
#include <cstdio>
#include "RPG.h"

using namespace std;

int main() 
{
    //Create one RPG with the overloaded constructor
    RPG p1 = RPG("Wiz", 0, 0.2, 60, 1);

    //Create one RPG with the default constructor
    RPG p2 = RPG();

    //Print p1's statistics
    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", 
     
        p1.getHitsTaken(),
        p1.getLuck(),
        p1.getExp(),
        p1.getLevel());

    //Print p2's statistics
    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", 
        p2.getHitsTaken(),
        p2.getExp(),
        p2.getLevel());

//Test setHitsTaken()
p2.setHitsTaken(3);

cout << "\nP2 hits taken ";
cout << p2.getHitsTaken() << endl;

//Test isAlive()
cout << "0 is dead, 1 is alive\n";
cout << "P1 " << p1.isAlive() << endl;
cout << "P2 " << p2.isAlive() << endl;

return 0;    
}