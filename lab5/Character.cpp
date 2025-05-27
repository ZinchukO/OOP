#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(const string& name, int health, int level)
    : name(name), health(health), level(level) {}

void Character::displayInfo() {
    cout << "Name: " << name << ", Health: " << health << ", Level: " << level << endl;
}

Character::~Character() {}


Warrior::Warrior(const string& name, int health, int level, int attackPower)
    : Character(name, health, level), attackPower(attackPower) {}

void Warrior::displayInfo() {
    cout << "Warrior - ";
    Character::displayInfo();
    cout << "Attack Power: " << attackPower << endl;
}


Mage::Mage(const string& name, int health, int level, int mana)
    : Character(name, health, level), mana(mana) {}

void Mage::displayInfo() {
    cout << "Mage - ";
    Character::displayInfo();
    cout << "Mana: " << mana << endl;
}


Archer::Archer(const string& name, int health, int level, float accuracy)
    : Character(name, health, level), accuracy(accuracy) {}

void Archer::displayInfo() {
    cout << "Archer - ";
    Character::displayInfo();
    cout << "Accuracy: " << accuracy << "%" << endl;
}


Healer::Healer(const string& name, int health, int level, int healPower)
    : Character(name, health, level), healPower(healPower) {}

void Healer::displayInfo() {
    cout << "Healer - ";
    Character::displayInfo();
    cout << "Healing Power: " << healPower << endl;
}


Universal::Universal(const string& name, int health, int level, int attackPower, float accuracy, int healPower, int mana)
    :Character(name, health, level),
      Warrior(name, health, level, attackPower),
      Mage(name, health, level, mana),
      Archer(name, health, level, accuracy),
      Healer(name, health, level, healPower) {}

void Universal::displayInfo() {
    cout << "Universal - ";
    Character::displayInfo();
    cout << "Attack Power: " << attackPower
         << ", Accuracy: " << accuracy
         << "%, Healing Power: " << healPower
         << ", Mana: " << mana << endl;
}
