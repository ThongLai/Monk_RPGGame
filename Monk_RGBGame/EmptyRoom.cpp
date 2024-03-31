//
// Created by Mike on 10/03/2019.
//
#include <iostream>
#include <random>
#include "EmptyRoom.h"
using namespace std;

EmptyRoom::EmptyRoom(Room *sender) : Room(sender)
{
}

void EmptyRoom::Generate(int itemChance) {
    this->hasPrayed = false;
    // Set hasItem to true if rngItemGen returns less than 20, therefore making an item a 20% chance.
    hasItem = (itemChance < 20);
}

void EmptyRoom::Render() {
    cout << "You enter a room. There's a dim light in front of you. There's a circle of "
            "candles underneath the light. It looks important. ";

}
