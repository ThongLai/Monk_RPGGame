#include "Player.h"

Player::Player(string name, int health, int damage) {
    this->name = name;
    this->health = health;
    this->damage = damage;
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

    printMess(player_prompts[0], midWidth(SCREEN_WIDTH, player_prompts[0].size()), SCREEN_HEIGHT * 6 / 20, YELLOW);
    printMess(player_prompts[1], midWidth(SCREEN_WIDTH, player_prompts[1].size()), SCREEN_HEIGHT * 8 / 20, YELLOW);


    waitForKeyBoard(midWidth(SCREEN_WIDTH, "Press any key to continue . . ."), SCREEN_HEIGHT * 18 / 20);

    printMess(player_prompts[2], midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 12 / 20, LIGHTCYAN);
    name = waitForInput("Enter Your Name: ", midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 13 / 20);
    
    system("cls");
    box_drawer.setBox(midWidth(SCREEN_WIDTH, player_prompts[3].size() + 6), midHeight(SCREEN_HEIGHT, 10), player_prompts[3].size() + 6, 10, WHITE, BLACK);
    box_drawer.printBorder();

    printMess(player_prompts[3], midWidth(SCREEN_WIDTH, player_prompts[3].size()), midHeight(SCREEN_HEIGHT, 10) + 2, WHITE);
    printMess(name, midWidth(SCREEN_WIDTH, name.size()), midHeight(SCREEN_HEIGHT, 10) + 6, LIGHTCYAN);

    waitForKeyBoard(midWidth(SCREEN_WIDTH, "Press any key to continue . . ."), SCREEN_HEIGHT * 18 / 20);
}

//Subtract some health from the player's current health.
void Player::takeDamage(int amount) {
    health = health - amount;
    if(health < 1) {
        Die();
    }
}

/**
 * Try to complete an action, such as attacking or defending from a monster.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */
bool Player::tryAction() {
    return (generateRand(0, 1) == 1);
}

void Player::Die() {
    cout << name << " died in battle! The treasure was never found..." << endl;
    system("pause");
    exit(0);
}