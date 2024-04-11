#pragma once

#include "CommonConfig.h"
#include "Box.h"

class Player {
private:
    string name;
    string description;

    int health;
    int damage; 

    bool isProtected = false;
public:
    Player(string name = "", string description = "", int heath = PLAYER_BASE_HEALTH, int damage = PLAYER_BASE_DAMAGE);

    string getName();
    string getDescription();
    int getHealth();    
    int getDamage();
    bool hasProtection();

    void setName(string name);
    void setDescription(string description);
    void setHealth(int health);
    void setHasProtection(bool isProtected);

    void setPlayer();
    void takeDamage(int amount);
    bool tryAction();
    void Die();
};