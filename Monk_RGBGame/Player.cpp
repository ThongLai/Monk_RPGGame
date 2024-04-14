#include "Player.h"

Player::Player(string name, int playerColor, int health, int damage, int cancelActionChance) {
    this->name = name;
    this->playerColor = playerColor;
    this->health = health;
    this->damage = damage;
    this->isProtected = false;
    this->cancelActionChance = cancelActionChance;
}

// Getters
string Player::getName() {
    return name;
}

int Player::getHealth() {
    return health;
}

int Player::getDamage() {
    return damage;
}

bool Player::hasProtection() {
    return isProtected;
}

// Setters
void Player::setName(string name) {
    this->name = name;
}

int Player::getPlayerColor()
{
    return playerColor;
}

void Player::setHealth(int health) {
    this->health = health;
}

void Player::setHasProtection(bool isProtected) {
    this->isProtected = isProtected;
}

void Player::setPlayer()
{
    string player_prompts[4] = {
        "You're in a fractured reality. And a dungeon, don't forget that.",
        "Once you advance through a door, there's no going back. Good luck...",
        "Now that's over, what's your name?",
        "Hello! Welcome to the Dungeon :)"
    };

    BOX box_drawer(midWidth(SCREEN_WIDTH, SCREEN_WIDTH * 4 / 5), SCREEN_HEIGHT * 2 / 20, SCREEN_WIDTH * 4 / 5, SCREEN_HEIGHT * 4 / 5);
    box_drawer.printBorder();
    box_drawer.setBox(midWidth(SCREEN_WIDTH, SCREEN_WIDTH * 3 / 5), SCREEN_HEIGHT * 5 / 20, SCREEN_WIDTH * 3 / 5, SCREEN_HEIGHT * 5 / 20);
    box_drawer.printBorder();

    printString(player_prompts[0], midWidth(SCREEN_WIDTH, player_prompts[0].size()), SCREEN_HEIGHT * 6 / 20, YELLOW);
    printString(player_prompts[1], midWidth(SCREEN_WIDTH, player_prompts[1].size()), SCREEN_HEIGHT * 8 / 20, YELLOW);


    waitForKeyBoard(midWidth(SCREEN_WIDTH, "Press any key to continue . . ."), SCREEN_HEIGHT * 18 / 20);

    printString(player_prompts[2], midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 12 / 20, LIGHTCYAN);
    name = waitForInput("Enter Your Name: ", midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 13 / 20);
    
    system("cls");
    box_drawer.setBox(midWidth(SCREEN_WIDTH, player_prompts[3].size() + 6), midHeight(SCREEN_HEIGHT, 10), player_prompts[3].size() + 6, 10, WHITE, BLACK);
    box_drawer.printBorder();

    printString(player_prompts[3], midWidth(SCREEN_WIDTH, player_prompts[3].size()), midHeight(SCREEN_HEIGHT, 10) + 2, WHITE);
    printString(name, midWidth(SCREEN_WIDTH, name.size()), midHeight(SCREEN_HEIGHT, 10) + 6, LIGHTCYAN);

    waitForKeyBoard(midWidth(SCREEN_WIDTH, "Press any key to continue . . ."), SCREEN_HEIGHT * 18 / 20);
}

//Subtract some health from the player's current health.
void Player::takeDamage(int amount) {
    if (isProtected) {
        printOnDescriptionCenterAndWait(name + "got PROTECTED by the Staff of Protection!");
        isProtected = false;
        return;
    }

    health = health - amount;
}



/**
 * Try to cancel an action, such as attacking or defending.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */

bool Player::tryCancelAction() {
    return (generateRand(0, 100) < cancelActionChance) ? true : false;
}

bool Player::isAlive() {
    return health > 0;
}

void Player::displayHealth()
{
    string player_health = "[" + to_string(health) + " / " + to_string(PLAYER_BASE_HEALTH) + "]";
    printString(player_health, GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10) + STATUS_VAR[0].size(), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5, playerColor);
}

void Player::removeHealth()
{
    string player_health = "[" + to_string(health) + " / " + to_string(PLAYER_BASE_HEALTH) + "]";
    printString(string(player_health.size(), ' '), GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10) + STATUS_VAR[0].size(), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5, playerColor);
}