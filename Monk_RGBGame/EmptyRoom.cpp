#include "EmptyRoom.h"

EmptyRoom::EmptyRoom() : Room("Empty Room", EMPTY_ROOM_COLOR, EMPTY_ROOM_COLOR)
{
    this->isPrayed = false;
    setDescription("It is a place where the mind can roam freely, unburdened by the chaos of the outside world.");
    
    // 20% chance to have an item
    hasItem = (generateRand(0, 100) < 20);
}

bool EmptyRoom::Item()
{
    return hasItem;
}

string PRAY_PROMPT[] =
{
    "Pray",
    "Move On",
};
int PRAY_PROMPT_SIZE = sizeof(PRAY_PROMPT) / sizeof(string);

string ITEM_PROMPT[] =
{
    "Pick Up",
    "Move On",
};
int ITEM_PROMPT_SIZE = sizeof(ITEM_PROMPT) / sizeof(string);

bool EmptyRoom::processRoom(Player* player) {
    drawArt(
        EMPTY_ROOM_ART,
        EMPTY_ROOM_HEIGHT,
        midWidth(GAMEPLAY_W, EMPTY_ROOM_WIDTH),
        midHeight(GAMEPLAY_H, EMPTY_ROOM_HEIGHT),
        EMPTY_ROOM_COLOR
    );

    printOnDescriptionCenterAndWait("It is a place unburdened by the chaos of the outside world", EMPTY_ROOM_COLOR);

    int box_width = 20;
    int box_height = 3;
    MENU prayMenu("What would you like to do?", PRAY_PROMPT, PRAY_PROMPT_SIZE, midWidth(GAMEPLAY_W, box_width), GAMEPLAY_H + 2 + midHeight(DESCRIPTION_H, box_height * PRAY_PROMPT_SIZE), box_width, box_height);
    prayMenu.setTitlePosition(midWidth(GAMEPLAY_W, box_width), GAMEPLAY_H + 3 + midHeight(DESCRIPTION_H, box_height * PRAY_PROMPT_SIZE));
    prayMenu.setBoxFormat(0, box_width, box_height, EMPTY_ROOM_COLOR, BLACK);
    prayMenu.printMenu();

    int player_action = prayMenu.inputMenu();
    prayMenu.removeMenu();

    string prompt;
    if (player_action == 0) {
        // PRAY
        player->removeHealth();
        player->setHealth(PLAYER_BASE_HEALTH);
        player->displayHealth();

        printOnDescriptionCenterAndWait("Naturally, you sit inside the demonic-looking summoning circle. You're now full health! [" + to_string(player->getHealth()) + " / " + to_string(PLAYER_BASE_HEALTH) + "]", EMPTY_ROOM_COLOR);
    }

    removeArt(
        EMPTY_ROOM_HEIGHT,
        EMPTY_ROOM_WIDTH,
        midWidth(GAMEPLAY_W, EMPTY_ROOM_WIDTH),
        midHeight(GAMEPLAY_H, EMPTY_ROOM_HEIGHT)
    );

    if (Item()) {
        MENU itemMenu("As " + player->getName() + " walks forward, You see a glisten in front of them. What do you do?", ITEM_PROMPT, ITEM_PROMPT_SIZE, midWidth(GAMEPLAY_W, box_width), GAMEPLAY_H + 2 + midHeight(DESCRIPTION_H, box_height * PRAY_PROMPT_SIZE), box_width, box_height);
        itemMenu.setTitlePosition(midWidth(GAMEPLAY_W, box_width), GAMEPLAY_H + 3 + midHeight(DESCRIPTION_H, box_height * ITEM_PROMPT_SIZE));
        itemMenu.setBoxFormat(0, box_width, box_height, EMPTY_ROOM_COLOR, BLACK);
        itemMenu.printMenu();

        player_action = itemMenu.inputMenu();
        itemMenu.removeMenu();

        if (player_action == 0) {
            if (generateRand(1, 100) < 21) {
                printOnDescriptionCenterAndWait("You approach the item and pick it up... It's a Staff of Protection!", EMPTY_ROOM_COLOR);
                
                player->setHasProtection(true);

                printOnDescriptionCenterAndWait("During your next combat, the Staff of Protection will block the first attack.");
            }
            else {
                player->removeHealth();
                player->takeDamage(1);
                player->displayHealth();

                printOnDescriptionCenterAndWait("You approach the item and pick it up... OUCH! It was a sewing needle! You lose 1 HP. :(", RED);
            }
        }
    }

    return true;
}