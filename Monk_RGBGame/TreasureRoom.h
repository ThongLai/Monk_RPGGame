//
// Created by Mike on 18/03/2019.
//

#ifndef MONKASSIGNMENT_TREASUREROOM_H
#define MONKASSIGNMENT_TREASUREROOM_H

#include "Room.h"

class TreasureRoom : public Room {
public:
    TreasureRoom(Room *);

    void Generate() override;

    void Render(string) override;

    bool isTreasureRoom() override { return true; }; // Tells the manager of the Room class that this is the treasure subclass.

    bool isTreasureCollected;

    void TreasureCollected(string);

};


#endif //MONKASSIGNMENT_TREASUREROOM_H
