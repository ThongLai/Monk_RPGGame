#include "Player.h"

Player::Player() {
    setColor(PLAYER_COLOR);

    setBaseHealth(PLAYER_BASE_HEALTH);
    setHealth(PLAYER_BASE_HEALTH);
    setDamage(PLAYER_BASE_DAMAGE);

    setCancelChance(PLAYER_CANCEL_ACTION_CHANCE);

    isProtected = false;
}

bool Player::hasProtection() {
    return isProtected;
}

void Player::setHasProtection(bool isProtected) {
    this->isProtected = isProtected;
}

void Player::setPlayer()
{
    string player_prompts[5] = {
        "You're in a fractured reality. And a dungeon, don't forget that.",
        "Once you advance through a door, there's no going back. Good luck...",
        "Now please, What's your name?",
        "What's your background?",
        "Hello! Welcome to the Dungeon :)"
    };

    BOX box_drawer(midWidth(SCREEN_WIDTH, SCREEN_WIDTH * 4 / 5), SCREEN_HEIGHT * 2 / 20, SCREEN_WIDTH * 4 / 5, SCREEN_HEIGHT * 4 / 5);
    box_drawer.printBorder();
    box_drawer.setBox(midWidth(SCREEN_WIDTH, SCREEN_WIDTH * 3 / 5), SCREEN_HEIGHT * 5 / 20, SCREEN_WIDTH * 3 / 5, SCREEN_HEIGHT * 5 / 20);
    box_drawer.printBorder();

    printString(player_prompts[0], midWidth(SCREEN_WIDTH, player_prompts[0].size()), SCREEN_HEIGHT * 6 / 20, YELLOW);
    printString(player_prompts[1], midWidth(SCREEN_WIDTH, player_prompts[1].size()), SCREEN_HEIGHT * 8 / 20, YELLOW);

    waitForKeyBoard(midWidth(SCREEN_WIDTH, "Press any key to continue . . ."), SCREEN_HEIGHT * 18 / 20);

    // Ask for player's name
    printString(player_prompts[2], midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 12 / 20, LIGHTCYAN);
    setName(waitForInput("Enter Your Name: ", midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 13 / 20));
    removeString(player_prompts[2], midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 12 / 20);
    removeString("Enter Your Name: ", midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 13 / 20);

    // Ask for player's short description
    printString(player_prompts[3], midWidth(SCREEN_WIDTH, player_prompts[3].size()), SCREEN_HEIGHT * 12 / 20, LIGHTCYAN);
    setDescription(waitForInput("Enter a Short Description: ", midWidth(SCREEN_WIDTH, player_prompts[3].size()), SCREEN_HEIGHT * 13 / 20));

    system("cls");
    box_drawer.setBox(midWidth(SCREEN_WIDTH, player_prompts[4].size() + 6), midHeight(SCREEN_HEIGHT, 10), player_prompts[4].size() + 6, 10, WHITE, BLACK);
    box_drawer.printBorder();

    printString(player_prompts[4], midWidth(SCREEN_WIDTH, player_prompts[4].size()), midHeight(SCREEN_HEIGHT, 10) + 2, WHITE);
    printString(getName(), midWidth(SCREEN_WIDTH, getName().size()), midHeight(SCREEN_HEIGHT, 10) + 6, LIGHTCYAN);

    waitForKeyBoard(midWidth(SCREEN_WIDTH, "Press any key to continue . . ."), SCREEN_HEIGHT * 18 / 20);
}

//Subtract some health from the player's current health.
void Player::takeDamage(int amount) {
    if (isProtected) {
        displayHealth();
        printOnDescriptionCenterAndWait(getName() + " got PROTECTED by the Shield of Angel!", LIGHTBLUE);
        isProtected = false;
        displayProtection();
        return;
    }

    if (UNDEADCMD)
        return;

    setHealth(getHealth() - amount);
}



/**
 * Try to cancel an action, such as attacking or defending.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */

void Player::displayHealth()
{
    string player_health = "[" + to_string(getHealth()) + " / " + to_string(PLAYER_BASE_HEALTH) + "]";
    printString(player_health, GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10) + STATUS_VAR[0].size(), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5, getColor());
}

void Player::removeHealth()
{
    string player_health = "[" + to_string(getHealth()) + " / " + to_string(PLAYER_BASE_HEALTH) + "]";
    printString(string(player_health.size(), ' '), GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10) + STATUS_VAR[0].size(), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5, getColor());
}

void Player::displayDamage(int color)
{
    printString(to_string(getDamage()), GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10) + STATUS_VAR[0].size(), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + 2, color);
}

void Player::displayProtection()
{
    string prompt = "[[PROTECTED]]";

    if (isProtected)
        printString(prompt, GAMEPLAY_W + midWidth(STATUS_W, prompt.size()), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 - 3, LIGHTBLUE);
    else
        printString(string(prompt.size(), ' '), GAMEPLAY_W + midWidth(STATUS_W, prompt.size()), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 - 3, LIGHTBLUE);
}