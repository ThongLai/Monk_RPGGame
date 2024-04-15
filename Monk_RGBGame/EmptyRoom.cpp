#include "EmptyRoom.h"

EmptyRoom::EmptyRoom() : Room("Empty Room", EMPTY_ROOM_COLOR, EMPTY_ROOM_COLOR)
{
    this->isPrayed = false;
    setDescription("It is a place where the mind can roam freely, unburdened by the chaos of the outside world.");
    
    // 20% chance to have an item
    hasItem = (generateRand(0, 100) < ITEM_CHANCE);
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
            int item_chance = generateRand(0, 100);

            printOnDescriptionCenterAndWait("You approach the item and pick it up... ", EMPTY_ROOM_COLOR);

            if (item_chance < SWORD_CHANCE) {
                drawArt(
                    SWORD_ART,
                    SWORD_HEIGHT,
                    midWidth(GAMEPLAY_W, SWORD_WIDTH),
                    midHeight(GAMEPLAY_H, SWORD_HEIGHT),
                    MAGENTA
                );

                printOnDescriptionCenterAndWait("It's the Sword of Hero!", MAGENTA);
                
                player->setDamage(player->getDamage() + 1);
                player->displayDamage(MAGENTA);

                printOnDescriptionCenterAndWait("With the Sword of Hero, your Attack Damage is increased by 1.", MAGENTA);

                removeArt(
                    SWORD_HEIGHT,
                    SWORD_WIDTH,
                    midWidth(GAMEPLAY_W, SWORD_WIDTH),
                    midHeight(GAMEPLAY_H, SWORD_HEIGHT)
                );
            }
            else if (item_chance < SHEILD_CHANCE) {
                drawArt(
                    SHIELD_ART,
                    SHIELD_HEIGHT,
                    midWidth(GAMEPLAY_W, SHIELD_WIDTH),
                    midHeight(GAMEPLAY_H, SHIELD_HEIGHT),
                    LIGHTBLUE
                );

                printOnDescriptionCenterAndWait("It's the Shield of Angel!", LIGHTBLUE);

                player->setHasProtection(true);
                player->displayProtection();

                printOnDescriptionCenterAndWait("During your next combat, the Shield of Angel will block the first attack.", LIGHTBLUE);

                removeArt(
                    SHIELD_HEIGHT,
                    SHIELD_WIDTH,
                    midWidth(GAMEPLAY_W, SHIELD_WIDTH),
                    midHeight(GAMEPLAY_H, SHIELD_HEIGHT)
                );
            }
            else {
                drawArt(
                    CACTUS_ART,
                    CACTUS_HEIGHT,
                    midWidth(GAMEPLAY_W, CACTUS_WIDTH),
                    midHeight(GAMEPLAY_H, CACTUS_HEIGHT),
                    GREEN
                );

                player->removeHealth();
                player->takeDamage(1);
                player->displayHealth();

                printOnDescriptionCenterAndWait("OUCH! It's a Cactus! You lose 1 HP. :(", RED);
            
                removeArt(
                    CACTUS_HEIGHT,
                    CACTUS_WIDTH,
                    midWidth(GAMEPLAY_W, CACTUS_WIDTH),
                    midHeight(GAMEPLAY_H, CACTUS_HEIGHT)
                );

                if (!player->isAlive())
                    return false;
            }
        }
    }

    return true;
}