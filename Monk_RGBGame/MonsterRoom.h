#pragma once

#include "Room.h"
#include "MonsterController.h"

class MonsterRoom : public Room {
private:
    MonsterController* monster;
public:
    MonsterRoom();
    MonsterController* getMonster();

    void Generate(int = 0);
    void Render(string = "");

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
};
