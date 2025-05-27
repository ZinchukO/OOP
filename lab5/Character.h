#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
public:
    string name;
    int health;
    int level;

    Character(const string& name, int health, int level);
    virtual void displayInfo();
    virtual ~Character();
};

class Warrior : virtual public Character {
protected:
    int attackPower;
public:
    Warrior(const string& name, int health, int level, int attackPower);
    void displayInfo() override;
};

class Mage : virtual public Character {
protected:
    int mana;
public:
    Mage(const string& name, int health, int level, int mana);
    void displayInfo() override;
};

class Archer : virtual public Character {
protected:
    float accuracy;
public:
    Archer(const string& name, int health, int level, float accuracy);
    void displayInfo() override;
};

class Healer : virtual public Character {
protected:
    int healPower;
public:
    Healer(const string& name, int health, int level, int healPower);
    void displayInfo() override;
};

class Universal : public Warrior, public Mage, public Archer, public Healer {
public:
    Universal(const string& name, int health, int level, int attackPower, float accuracy, int healPower, int mana);

    void displayInfo() override;
};

#endif
