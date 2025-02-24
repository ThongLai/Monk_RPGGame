#pragma once

#include "CommonConfig.h"
#include "ModelArts.h"

class Entity {
private:
    string name;
    string description;
    int color; // Entity Color when draw name and description

    int health;
    int baseHealth;
    int damage;
    int cancel_chance;

public:
    Entity();
    
    // Getters
    string getName();
    string getDescription();
    int getColor();
    int getHealth();
    int getDamage();
    int getBaseHealth();

    // Setters
    void setName(string monsterName);
    void setDescription(string description);
    void setColor(int monsterColor);
    void setHealth(int health);
    void setDamage(int damage);
    void setBaseHealth(int baseHealth);
    void setCancelChance(int cancel_chance);

    bool tryCancelAction();
    bool isAlive();

    virtual void takeDamage(int amount);
    virtual void displayHealth();
    virtual void removeHealth();
    virtual void displayDescription();
};