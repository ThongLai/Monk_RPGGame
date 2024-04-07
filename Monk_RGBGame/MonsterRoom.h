#pragma once

#include "Room.h"
#include "Monster.h"

class MonsterRoom : public Room {
private:
    Monster* monster;
public:
    MonsterRoom(int monsterId = generateRand(0, 2));
    Monster* getMonster();
    bool isMonsterAlive();

    void CombatTryAttack(Player* player, int turn);
    void CombatTryDefend(Player* player, int turn);

    void Render(string = "");
    void processRoom(Player* player);
};
