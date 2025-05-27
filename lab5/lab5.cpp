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

    Universal u("Invoker", 120, 7, 50, 95.5, 60, 100);
    u.displayInfo();
    cout << "-------------------\n";

    return 0;
}
