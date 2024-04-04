#pragma once

#include "Room.h"

class EmptyRoom : public Room {
private:
    bool isPrayed; 
    bool hasItem;
public:
    EmptyRoom();

    void Generate(int = 0);
    void Render(string = "");

    bool Item();
};