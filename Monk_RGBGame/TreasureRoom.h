#pragma once

#include "Room.h"

class TreasureRoom : public Room {
private:
    bool isTreasureCollected;
public:
    TreasureRoom(bool isTreasureCollected = false);

    void Render(string = "");

    bool isTreasureRoom() override { return true; }; // Tells the manager of the Room class that this is the treasure subclass.

    void TreasureCollected(string);
};