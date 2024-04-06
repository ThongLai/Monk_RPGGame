#pragma once

#include "Room.h"

class EmptyRoom : public Room {
private:
    bool isPrayed; 
    bool hasItem;
public:
    EmptyRoom();

    void Render(string = "");

    bool Item();
};