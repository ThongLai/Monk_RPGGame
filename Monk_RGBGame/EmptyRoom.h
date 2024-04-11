#pragma once

#include "Room.h"

extern string PRAY_PROMPT[];
extern int PRAY_PROMPT_SIZE;

extern string ITEM_PROMPT[];
extern int ITEM_PROMPT_SIZE;

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