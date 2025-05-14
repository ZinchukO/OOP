#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
protected:
    string name;
    int health;
    int level;

public:
    Character(const string& name, int health, int level);
    void displayInfo();
    ~Character();
};


class Warrior : Character {
protected:
    int attackPower;
public:
    Warrior(const string& name, int health, int level, int attackPower);
    void displayInfo() ;
};

class Mage : Character {
protected:
    int mana;
public:
    Mage(const string& name, int health, int level, int mana);
    void displayInfo();
};

class Archer : Character {
protected:
    float accuracy;
public:
    Archer(const string& name, int health, int level, float accuracy);
    void displayInfo();
};

class Healer : Character {
protected:   
    int healPower;
public:
    Healer(const string& name, int health, int level, int healPower);
    void displayInfo();
};

class Rogue : Character {
protected:
    float critChance;
    
public:
    Rogue(const string& name, int health, int level, float critChance);
    void displayInfo() ;
};

#endif
