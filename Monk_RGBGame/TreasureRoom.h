#pragma once

#include "Room.h"

class TreasureRoom : public Room {
private:
    bool isTreasureCollected;
public:
    TreasureRoom(bool isTreasureCollected = false);
    
    void Render(string = "");
    void processRoom(Player* player);
};