#include "EmptyRoom.h"

string PRAY_PROMPT[] =
{
    "Pray",
    "Move On",
};
int PRAY_PROMPT_SIZE = sizeof(PRAY_PROMPT) / sizeof(string);

string ITEM_PROMPT[] =
{
    "Pray",
    "Move On",
};
int ITEM_PROMPT_SIZE = sizeof(ITEM_PROMPT) / sizeof(string);


EmptyRoom::EmptyRoom() : Room("Empty Room")
{
    description = "As the monk enters the empty room, a calming presence fills the air. The room's peaceful atmosphere helps the monk regain their health and vitality.";
    this->isPrayed = false;

    // 20% chance to have an item
    hasItem = (generateRand(0, 100) < 20);
}

bool EmptyRoom::Item()
{
    return hasItem;
}

void EmptyRoom::processRoom(Player* player) {
    int box_width = 21;
    int box_height = 5;
    MENU prayMenu("What would you like to do?", PRAY_PROMPT, PRAY_PROMPT_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * PRAY_PROMPT_SIZE), box_width, box_height, WHITE, BLACK);
    int buf = 0;

    while (true)
    {
        system("cls");
        prayMenu.printMenu();
        int buf = prayMenu.inputMenu();

        if (buf == 0) {
            // PRAY
            system("cls");

            player->setHealth(PLAYER_BASE_HEALTH);
            printMessCenter("Naturally, you sit inside the demonic-looking summoning circle. You're now full health! [" + to_string(player->getHealth()) + " / " + to_string(PLAYER_BASE_HEALTH) + "]");
            break;
        }
        else
            break;
    }

    if (Item()) {
        int box_width = 21;
        int box_height = 5;
        MENU itemMenu("As " + player->getName() + " walks forward, they see a glisten in front of them. What do you do?", ITEM_PROMPT, ITEM_PROMPT_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * ITEM_PROMPT_SIZE), box_width, box_height, WHITE, BLACK);
        int buf = 0;

        while (true)
        {
            system("cls");
            itemMenu.printMenu();
            int buf = itemMenu.inputMenu();

            if (buf == 0) {
                system("cls");

                if (generateRand(1, 100) < 21) {
                    printMessCenter("You approach the item and pick it up... It's a Staff of Protection! During your next combat, the Staff of Protection will block the first attack.");
                    player->setHasProtection(true);
                }
                else {
                    printMessCenter("You approach the item and pick it up... OUCH! It was a sewing needle! You lose 1 HP. :( ");
                    player->takeDamage(1);
                }

                break;
            }
            else
                break;
        }
    }

    printMessCenter(player->getName() + " the Monk moves on to the next room... ");
}


void EmptyRoom::Render(string) {
    cout << description;
}
