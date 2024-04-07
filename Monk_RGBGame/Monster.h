#pragma once

#include "CommonConfig.h"

class Monster {
private:
    string name;
    string description;

    int health;
    int damage;

    int totalHealth;

    int attackChance;
    int defendChance;
public:
    Monster(int monsterId);
    
    string getName();
    string getDescription();
    int getHealth();
    int getDamage();

    int getBaseHealth();  

    void setName(string monsterName);
    void setDescription(string noise);
    void setHealth(int health);
    void setDamage(int damage);

    void setBaseHealth(int base);

    void takeDamage(int amount);
    bool tryAction();
    int actionToPerform();
};