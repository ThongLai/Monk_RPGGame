#include "TreasureRoom.h"

TreasureRoom::TreasureRoom() : Room("Treasure Room", TREASURE_ROOM_COLOR, TREASURE_ROOM_COLOR) {
    setDescription("You enter a dark room. As you walk forward, you can smell a strange scent coming from in front of you... ");
}

string TREASURE_PROMPT[] =
{
    "Collect Treasure",
    "Ignore?",
};
int TREASURE_PROMPT_SIZE = sizeof(TREASURE_PROMPT) / sizeof(string);

string IGNORE_PROMPT[] =
{
    "Collect Treasure",
    "Still Ignore",
};
int IGNORE_PROMPT_SIZE = sizeof(IGNORE_PROMPT) / sizeof(string);

bool TreasureRoom::processRoom(Player* player) {

    printOnGameplayCenterAndWait("Your stomach rumbles. Your inside, ready. This is it. It's the Treasure Room! Right in front of you... ");
    printOnGameplayCenterAndWait("In the treasure room, the monk is surrounded by dazzling wealth and priceless artifacts!");
    
    drawArt(
        TREASURE_ART,
        TREASURE_HEIGHT,
        midWidth(GAMEPLAY_W, TREASURE_WIDTH),
        midHeight(GAMEPLAY_H, TREASURE_HEIGHT),
        TREASURE_ROOM_COLOR
    );

    string prompt = "It's the Dungeon's Treasure Chest!";
    printString(prompt, midWidth(GAMEPLAY_W, prompt.size()), GAMEPLAY_H + midHeight(DESCRIPTION_H, 1), TREASURE_ROOM_COLOR);

    int box_width = 20;
    int box_height = 3;
    MENU treasureMenu("What will you do?", TREASURE_PROMPT, TREASURE_PROMPT_SIZE, GAMEPLAY_W / 10, GAMEPLAY_H + 2 + midHeight(DESCRIPTION_H, box_height * TREASURE_PROMPT_SIZE), box_width, box_height, TREASURE_ROOM_COLOR);
    treasureMenu.setBoxFormat(0, box_width, box_height, TREASURE_ROOM_COLOR, BLACK);
    treasureMenu.setBoxFormat(1, box_width, box_height, LIGHTRED, BLACK);
    treasureMenu.printMenu();
    int player_action = treasureMenu.inputMenu();
    treasureMenu.removeMenu();

    if (player_action == 1) {
        MENU ignoreMenu("Are you sure you want to IGNORE it?", IGNORE_PROMPT, IGNORE_PROMPT_SIZE, GAMEPLAY_W / 10, GAMEPLAY_H + 2 + midHeight(DESCRIPTION_H, box_height * IGNORE_PROMPT_SIZE), box_width, box_height, TREASURE_ROOM_COLOR);
        ignoreMenu.setBoxFormat(0, box_width, box_height, TREASURE_ROOM_COLOR, BLACK);
        ignoreMenu.setBoxFormat(1, box_width, box_height, LIGHTRED, BLACK);
        ignoreMenu.printMenu();
        player_action = ignoreMenu.inputMenu();
        ignoreMenu.removeMenu();

        removeString(prompt, midWidth(GAMEPLAY_W, prompt.size()), GAMEPLAY_H + midHeight(DESCRIPTION_H, 1));

        if (player_action == 1) {
            removeArt(
                TREASURE_HEIGHT,
                TREASURE_WIDTH,
                midWidth(GAMEPLAY_W, TREASURE_WIDTH),
                midHeight(GAMEPLAY_H, TREASURE_HEIGHT)
            );

            string prompt = "It's WEIRD that you choose to ignore the Treasure";
            printStringCenter(prompt);
            removeStringCenter(prompt);

            printOnDescriptionCenterAndWait("Oh well... you are probably an adventurous person. Let continue then!", player->getPlayerColor());
            return true;
        }
    }

    printOnDescriptionCenterAndWait(player->getName() + " The Monk collected the treasure, and makes their way out of the Dungeon!", TREASURE_ROOM_COLOR);

    removeArt(
        TREASURE_HEIGHT,
        TREASURE_WIDTH,
        midWidth(GAMEPLAY_W, TREASURE_WIDTH),
        midHeight(GAMEPLAY_H, TREASURE_HEIGHT)
    );

    return false;
}