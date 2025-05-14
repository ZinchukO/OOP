#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Warrior w("Axe", 150, 5, 30);
    w.displayInfo();

    cout << "-------------------\n";

    Mage m("Aghanim", 100, 6, 80);
    m.displayInfo();

    cout << "-------------------\n";

    Archer a("Lyralei", 110, 5, 92);
    a.displayInfo();

    cout << "-------------------\n";

    Healer h("Oracle", 90, 4, 40);
    h.displayInfo();

    cout << "-------------------\n";

    Rogue rogue("Rikimaru", 100, 5, 25); 
    rogue.displayInfo();

    return 0;
}
