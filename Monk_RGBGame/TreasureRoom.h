#pragma once

#include "Room.h"

extern string TREASURE_PROMPT[];
extern int TREASURE_PROMPT_SIZE;

class TreasureRoom : public Room {
public:
    TreasureRoom();
    
    bool processRoom(Player* player);
};