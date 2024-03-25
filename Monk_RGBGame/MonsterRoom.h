//
// Created by Mike on 09/03/2019.
//

#ifndef MONKASSIGNMENT_MONSTERROOM_H
#define MONKASSIGNMENT_MONSTERROOM_H

#include "Room.h"
#include "MonsterController.h"

class MonsterRoom : public Room {
public:
    MonsterRoom(Room*);
    void Generate(int) override;
    MonsterController* getMonster();
    void Render() override;
    bool isMonsterAlive();

    // Methods from the MonsterController
    int getMonsterHealth();
    int getMonsterBaseHealth();
    string getMonsterName();
    string getMonsterNoise();
    void setMonsterHealth(int value);
    void subtractMonsterHealth(int value);
    int getMonsterAttackPoints();
    bool monsterTryAction();
    int monsterActionToPerform();
private:
    MonsterController *monster;
};


#endif //MONKASSIGNMENT_MONSTERROOM_H
