#pragma once

#include "Entity.h"
#include "CommonConfig.h"
#include "Box.h"

class Player : public Entity{
private:
    bool isProtected;
public:
    Player();

    bool hasProtection();
    void setHasProtection(bool isProtected);

    void setPlayer();
    void takeDamage(int amount);

    void displayHealth();
    void removeHealth();
    void displayDamage(int color = PLAYER_COLOR);
    void displayProtection();
};