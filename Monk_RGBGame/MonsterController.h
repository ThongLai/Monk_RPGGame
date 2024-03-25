//
// Created by Mike on 08/03/2019.
//

#ifndef MONKASSIGNMENT_MONSTERCONTROLLER_H
#define MONKASSIGNMENT_MONSTERCONTROLLER_H

#include "MonsterModel.h"

class MonsterController {
public:
    MonsterController(int monsterId);
    int getMonsterHealth();
    int getMonsterBaseHealth();
    string getMonsterName();
    string getMonsterNoise();
    void setMonsterHealth(int value);
    void subtractMonsterHealth(int value);
    int getMonsterAttackPoints();
    bool tryAction();
    int actionToPerform();
    int rngAction(int,int);
private:
    MonsterModel* _model;
};


#endif //MONKASSIGNMENT_MONSTERCONTROLLER_H
