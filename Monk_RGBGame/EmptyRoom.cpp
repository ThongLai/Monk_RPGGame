#include "EmptyRoom.h"

EmptyRoom::EmptyRoom() : Room("Empty Room")
{
    description = "As the monk enters the empty room, a calming presence fills the air. The room's peaceful atmosphere helps the monk regain their health and vitality.";
    this->isPrayed = false;

    // 20% chance to have an item
    hasItem = (generateRand(1, 100) < 20);
}

void EmptyRoom::Render(string) {
    cout << description;
}

bool EmptyRoom::Item()
{
    return hasItem;
}
