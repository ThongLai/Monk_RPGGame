#include "EmptyRoom.h"

EmptyRoom::EmptyRoom() : Room("Empty Room")
{
    description = "As the monk enters the empty room, a calming presence fills the air. The room's peaceful atmosphere helps the monk regain their health and vitality.";
    this->isPrayed = false;

    // 20% chance to have an item
    hasItem = (generateRand(1, 100) < 20);
}

bool EmptyRoom::Item()
{
    return hasItem;
}

void EmptyRoom::processRoom(Player* player) {
    // Initialise the "input" to contains user's input
    int input = -1;

    // Keep asking the player for the correct instruction. Break out of the loop when it's a 0 or 1.
    cout << "\n What would you like to do? \n [0] = pray \n [1] = move on" << endl;
    while (true) {
        if (_kbhit()) {
            input = toupper(_getch());

            if (input == '0' || input == '1')
                break;
            else
                cout << "Input unrecognised :( " << endl;
        }
    }

    if (input == '0') {
        player->setHealth(PLAYER_BASE_HEALTH);
        printf("Naturally, you sit inside the demonic-looking summoning circle. You're now full health! [%d / %d] \n",
            player->getHealth(), PLAYER_BASE_HEALTH);
    }

    // Cast the current room to an EmptyRoom object.

    if (Item()) {
        cout << "As " << player->getName() << " walks forward, they see a glisten in front of them." << endl;
        cout << " What do you do? \n [0] = Pick Up \n [1] = Ignore" << endl;

        input = -1;
        while (true) {
            if (_kbhit()) {
                input = toupper(_getch());

                if (input == '0' || input == '1')
                    break;
                else
                    cout << "The Monk didn't understand that!" << endl;
            }
        }

        if (input == '0') {
            if (generateRand(1, 100) < 21) {
                cout << "You approach the item and pick it up... It's a Staff of Protection! \n During your next combat, the Staff of Protection will block the first attack." << endl;
                player->setHasProtection(true);
            }
            else {
                cout << "You approach the item and pick it up... OUCH! It was a sewing needle! \n You lose 1 HP. :( " << endl;
                player->takeDamage(1);
            }
        }
    }

    cout << player->getName() << " the Monk moves on to the next room..." << endl;
}


void EmptyRoom::Render(string) {
    cout << description;
}
