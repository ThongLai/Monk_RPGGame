//
// Created by Mike on 15/03/2019.
//

#ifndef MONKASSIGNMENT_PLAYERCONTROLLER_H
#define MONKASSIGNMENT_PLAYERCONTROLLER_H

#include "PlayerModel.h"
#include "MonsterController.h"

class PlayerController {
public:
    PlayerController(int,string,string);

    void setPlayerHealth(int);
    void subtractPlayerHealth (int);
    int getPlayerHealth();
    string getPlayerDescription();
    string getPlayerName();
    int getPlayerBaseHealth();
    int getPlayerDamage();
    bool tryAction();
    bool playerHasProtection();
    void Die();
    void setPlayerProtection(bool);
private:
    PlayerModel* player;
};


#endif //MONKASSIGNMENT_PLAYERCONTROLLER_H
