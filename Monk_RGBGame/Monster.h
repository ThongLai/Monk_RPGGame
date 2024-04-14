#pragma once

#include "CommonConfig.h"

class Monster {
private:
    string name;
    string description;
    int monsterColor;

    int health;
    int baseHealth;
    int damage;
protected:
    int cancel_chance;
    int attack_chance;
public:
    Monster();
    
    string getName();
    string getDescription();
    int getMonsterColor();
    int getHealth();
    int getDamage();
    int getBaseHealth();  

    void setName(string monsterName);
    void setDescription(string noise);
    void setMonsterColor(int monsterColor);
    void setHealth(int health);
    void setDamage(int damage);
    void setBaseHealth(int base);

    void takeDamage(int amount);
    bool tryCancelAction();
    int actionToPerform();
    bool isAlive();

    void displayHealth();
    void removeHealth();
};