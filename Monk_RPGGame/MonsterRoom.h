#pragma once

#include "Room.h"
#include "Goblin.h"
#include "Chupacabra.h"
#include "Foot.h"

extern string ACTION_PROMPT[];
extern int ACTION_PROMPT_SIZE;

class MonsterRoom : public Room {
private:
    Monster* monster;
public:
    MonsterRoom(int monsterId = generateRand(0, 2));
    ~MonsterRoom();

    bool processActions(Entity *E1, Entity *E2, int E1_action, int E2_action);
    bool processRoom(Player* player);
};