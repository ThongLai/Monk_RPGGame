#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(int monsterId) : Room("Monster Room", MONTER_ROOM_COLOR, MONTER_ROOM_COLOR) {
    setDescription("Monster room, danger lurks. The monk must face a formidable creature in a fierce battle for survival.");

    // Randomise the monster. 0 = Goblin, 1 = Chupacabra, 2 = Foot.
    switch (monsterId) {
    case(0):
        monster = new Goblin;
        break;
    case(1):
        monster = new Chupacabra;
        break;
    case(2):
        monster = new Foot;
        break;
    }
}

MonsterRoom::~MonsterRoom()
{
    delete monster;
}

string ACTION_PROMPT[] =
{
    "Attack",
    "Defend",
};
int ACTION_PROMPT_SIZE = sizeof(ACTION_PROMPT) / sizeof(string);

bool MonsterRoom::processRoom(Player* player) {
    drawArt(
        monster->getArtModel(),
        monster->getArtHeight(),
        midWidth(GAMEPLAY_W, monster->getArtWidth()),
        midHeight(GAMEPLAY_H, monster->getArtHeight()),
        monster->getMonsterColor()
    );

    monster->displayHealth();

    printOnDescriptionCenterAndWait("It's a " + monster->getName() + "! The door behind you locks. The battle has begun!");

    while (true) {
        int box_width = 20;
        int box_height = 3;
        MENU actionMenu("What will the all-powerful Monk do?", ACTION_PROMPT, ACTION_PROMPT_SIZE, GAMEPLAY_W / 10, GAMEPLAY_H + 2 + midHeight(DESCRIPTION_H, box_height * ACTION_PROMPT_SIZE), box_width, box_height, WHITE, BLACK);
        actionMenu.setBoxFormat(0, box_width, box_height, LIGHTRED, BLACK);
        actionMenu.setBoxFormat(1, box_width, box_height, LIGHTBLUE, BLACK);
        actionMenu.printMenu();

        int player_action = actionMenu.inputMenu();
        actionMenu.removeMenu();
        int monster_action = monster->actionToPerform();


        if (player_action == 0) // Player Attack 
        {
            printOnDescriptionCenterAndWait(player->getName() + " the Monk ATTACKED " + monster->getName() + "!", player->getPlayerColor());

            if (monster_action == 1) {
                printOnDescriptionCenterAndWait(monster->getName() + " DEFENDED " + player->getName() + "'s attack!", monster->getMonsterColor());

                if (player->tryCancelAction()) {// Monster Defend

                    printOnDescriptionCenterAndWait(monster->getName() + " FAILED to DEFEND against " + player->getName(), monster->getMonsterColor());

                    monster->removeHealth();
                    monster->takeDamage(player->getDamage());
                    monster->displayHealth();

                    printOnDescriptionCenterAndWait(player->getName() + " dealt " + to_string(player->getDamage()) + " damage!", player->getPlayerColor());

                    if (!monster->isAlive())
                        break;
                }
            }
            else if (monster->tryCancelAction())
                printOnDescriptionCenterAndWait(monster->getName() + " DODGED " + player->getName() + "'s attack!", monster->getMonsterColor());
            else {
                monster->removeHealth();
                monster->takeDamage(player->getDamage());
                monster->displayHealth();

                printOnDescriptionCenterAndWait(player->getName() + " dealt " + to_string(player->getDamage()) + " damage!", player->getPlayerColor());
                
                if (!monster->isAlive())
                    break;
            }
        }
        else if (monster_action == 1)
            printOnDescriptionCenterAndWait(player->getName() + " tried to DEFEND " + monster->getName() + "'s attack!", player->getPlayerColor());

        if (monster_action == 0) // Monster Attack 
        {
            printOnDescriptionCenterAndWait(monster->getName() + " ATTACKED " + player->getName() + "!", monster->getMonsterColor());

            if (player_action == 1) {
                printOnDescriptionCenterAndWait(player->getName() + " DEFENDED " + monster->getName() + "'s attack!", player->getPlayerColor());

                if (monster->tryCancelAction()) {
                    printOnDescriptionCenterAndWait(player->getName() + " FAILED to DEFEND against " + monster->getName(), player->getPlayerColor());

                    player->removeHealth();
                    player->takeDamage(monster->getDamage());
                    player->displayHealth();

                    printOnDescriptionCenterAndWait(monster->getName() + " dealt " + to_string(monster->getDamage()) + " damage!", monster->getMonsterColor());
                    
                    if (!player->isAlive())
                        break;
                }
            }
            else if (player->tryCancelAction())
                printOnDescriptionCenterAndWait(player->getName() + " DODGED " + monster->getName() + "'s attack!", player->getPlayerColor());
            else {

                player->removeHealth();
                player->takeDamage(monster->getDamage());
                player->displayHealth();

                printOnDescriptionCenterAndWait(monster->getName() + " dealt " + to_string(monster->getDamage()) + " damage!", monster->getMonsterColor());
                
                if (!player->isAlive())
                    break;
            }
        }
        else if (player_action == 1)
            printOnDescriptionCenterAndWait(monster->getName() + " tried to DEFEND " + player->getName() + "'s attack!", monster->getMonsterColor());
    }

    removeArt(
        monster->getArtHeight(),
        monster->getArtWidth(),
        midWidth(GAMEPLAY_W, monster->getArtWidth()),
        midHeight(GAMEPLAY_H, monster->getArtHeight())
    );

    monster->removeHealth();

    if (player->isAlive()) {
        // The Monster has been defeated, allow the player to move on.
        printOnGameplayCenterAndWait(monster->getName() + " was defeated by " + player->getName() + " The Monk!", player->getPlayerColor());
        return true;
    }
    else {
        // The Player has been defeated, Game over.
        printOnDescriptionCenterAndWait(player->getName() + " died in battle! The treasure was never found... ", RED);
        return false;
    }
}
