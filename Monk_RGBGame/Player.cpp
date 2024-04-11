#include "Player.h"

Player::Player(string name, string description, int health, int damage) {
    this->name = name;
    this->description = description;
    this->health = health;
    this->damage = damage;
}

// Getters
string Player::getName() {
    return name;
}

string Player::getDescription() {
    return description;
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

void Player::setDescription(string description) {
    this->description = description;
}

void Player::setHealth(int health) {
    this->health = health;
}

void Player::setHasProtection(bool isProtected) {
    this->isProtected = isProtected;
}

void Player::setPlayer()
{
    string player_prompts[3] = {
        "You're in a fractured reality. And a dungeon, don't forget that. Once you advance through a door, there's no going back. Good luck... ",
        "Now that's over, what's your name?",
        "The powerful Monk has established his name. But what's his story?"
    };

    system("cls");

    printMess(player_prompts[0], midWidth(SCREEN_WIDTH, player_prompts[0].size()), SCREEN_HEIGHT * 4 / 20);
    printMess(player_prompts[1], midWidth(SCREEN_WIDTH, player_prompts[1].size()), SCREEN_HEIGHT * 6 / 20);

    GotoXY(midWidth(SCREEN_WIDTH, player_prompts[1].size()), SCREEN_HEIGHT * 7 / 20);
    cout << "Enter Your Name: ";
    getline(cin, name);

    printMess(player_prompts[2], midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 9 / 20);

    GotoXY(midWidth(SCREEN_WIDTH, player_prompts[2].size()), SCREEN_HEIGHT * 10 / 20);
    cout << "Enter Your Description: ";
    getline(cin, description);
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