#pragma once

#include "Room.h"

class EmptyRoom : public Room {
private:
    bool isPrayed; 
    bool hasItem;
public:
    EmptyRoom();

    bool Item();

    void processRoom(Player* player);

    void Render(string = "");
};