#pragma once

#include "CommonConfig.h"
#include "Box.h"

class Player {
private:
    string name;
    int playerColor;

    int health;
    int damage;

    bool isProtected;
    int cancelActionChance;
public:
    Player(string name = "",int playerColor = PLAYER_COLOR, int heath = PLAYER_BASE_HEALTH, int damage = PLAYER_BASE_DAMAGE, int cancelActionChance = PLAYER_CANCEL_ACTION_CHANCE);

    string getName();
    int getHealth();
    int getDamage();
    bool hasProtection();
    int getPlayerColor();

    void setName(string name);
    void setHealth(int health);
    void setDamage(int damage);
    void setHasProtection(bool isProtected);

    void setPlayer();
    void takeDamage(int amount);
    bool tryCancelAction();
    bool isAlive();

    void displayHealth();
    void removeHealth();
    void displayDamage(int color = PLAYER_COLOR);
    void displayProtection();
};