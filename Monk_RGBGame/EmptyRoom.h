//
// Created by Mike on 10/03/2019.
//

#ifndef MONKASSIGNMENT_EMPTYROOM_H
#define MONKASSIGNMENT_EMPTYROOM_H

#include "PlayerController.h"
#include "Room.h"

class EmptyRoom : public Room {
public:
    EmptyRoom(Room*);
    void Generate(int) override;
    bool hasPrayed; // Has the player prayed in the room already? Default to false.
    bool hasItem;
    void Render() override;
};

#endif //MONKASSIGNMENT_EMPTYROOM_H
