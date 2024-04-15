#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(int monsterId) : Room("Monster Room", MONTER_ROOM_COLOR, MONTER_ROOM_COLOR) {
    setDescription("Monster room, danger lurks. The monk must face a formidable creature in a fierce battle for survival.");

    // Randomise the monster. 0 = Goblin, 1 = Chupacabra, 2 = Foot.
    switch (monsterId) {
    default:
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

bool MonsterRoom::processActions(Entity *E1, Entity *E2, int E1_action, int E2_action)
{

    if (E1_action == 0) // E1 Attack 
    {
        printOnDescriptionCenterAndWait(E1->getName() + " ATTACKED " + E2->getName() + "!", E1->getColor());

        if (E2_action == 1) {
            printOnDescriptionCenterAndWait(E2->getName() + " DEFENDED " + E1->getName() + "'s attack!", E2->getColor());

            if (E1->tryCancelAction()) {// E2 Defend

                printOnDescriptionCenterAndWait(E2->getName() + " FAILED to DEFEND against " + E1->getName(), E2->getColor());

                E2->removeHealth();
                E2->takeDamage(E1->getDamage());
                E2->displayHealth();

                printOnDescriptionCenterAndWait(E1->getName() + " dealt " + to_string(E1->getDamage()) + " damage!", E1->getColor());

                if (!E2->isAlive())
                    return false;
            }
            else {
                E2->removeHealth();
                E2->setHealth(E2->getHealth() + 1);
                E2->displayHealth();

                printOnDescriptionCenterAndWait(E2->getName() + " RECOVERED 1 HP from DEFENDING " + E1->getName() + "'s attack!", E2->getColor());
            }
        }
        else if (E2->tryCancelAction())
            printOnDescriptionCenterAndWait(E2->getName() + " DODGED " + E1->getName() + "'s attack!", E2->getColor());
        else {
            E2->removeHealth();
            E2->takeDamage(E1->getDamage());
            E2->displayHealth();

            printOnDescriptionCenterAndWait(E1->getName() + " dealt " + to_string(E1->getDamage()) + " damage!", E1->getColor());

            if (!E2->isAlive())
                return false;
        }
    }
    else if (E2_action == 1) { // E1 Defend, E2 Defend
        printOnDescriptionCenterAndWait(E1->getName() + " tried to DEFEND " + E2->getName() + "'s attack", E1->getColor());

        if (E2->tryCancelAction())
            printOnDescriptionCenterAndWait(E1->getName() + " FAILED to DEFEND against " + E2->getName(), E1->getColor());
        else {
            E1->removeHealth();
            E1->setHealth(E1->getHealth() + 1);
            E1->displayHealth();

            printOnDescriptionCenterAndWait(E1->getName() + " RECOVERED 1 HP by DEFENDING", E1->getColor());
        }
    }

    return true;
}

bool MonsterRoom::processRoom(Player* player) {
    drawArt(
        monster->getArtModel(),
        monster->getArtHeight(),
        midWidth(GAMEPLAY_W, monster->getArtWidth()),
        midHeight(GAMEPLAY_H, monster->getArtHeight()),
        monster->getColor()
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

        if (!processActions(player, monster, player_action, monster_action))
            break;
        if (!processActions(monster, player, monster_action, player_action))
            break;
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
        printOnGameplayCenterAndWait(monster->getName() + " was defeated by " + player->getName() + " The Monk!", player->getColor());
        return true;
    }
    else {
        // The Player has been defeated, Game over.
        printOnDescriptionCenterAndWait(player->getName() + " died in battle! The treasure was never found... ", RED);
        return false;
    }
}
