//
// Created by Mike on 15/03/2019.
//
#include <iostream>
#include <random>

#include "PlayerController.h"

using namespace std;

/**
 * Initialise the Player object, as well as the data model, and set some basic values.
 * @param attack Sets the players Attack points dealt to monsters during combat.
 * @param playerName The Player's name which is provided when the game starts
 * @param playerDescription The description of the Monk, provided by the player at the start.
 */
PlayerController::PlayerController(int damage, string playerName, string playerDescription) {
    this->player = new PlayerModel(damage, playerName, playerDescription); // Initialise the player Model

}
/**
 * Get the player's current health points
 * @return Integer representing the player's current health
 */
int PlayerController::getPlayerHealth() {
    return player->getHealth();
}
/**
 * Override the player's current health to a provided integer.
 * @param value The value to set the player's health to.
 */
void PlayerController::setPlayerHealth(int value) {
    player->setHealth(value);
}
/**
 * Subtract some health from the player's current health.
 * @param value The amount of health points to subtract from the player's health.
 */
void PlayerController::subtractPlayerHealth(int value) {
    player->setHealth(player->getHealth() - value);
    if(player->getHealth() < 1) {
        Die();
    }
}

/**
 * Gets the description of the Monk, which is provided when the game starts.
 * @return The description of the Monk.
 */
string PlayerController::getPlayerDescription() {
    return player->getDescription();
}

/**
 * Gets the name of the player, which was provided when the game started.
 * @return A string representing the player's name.
 */
string PlayerController::getPlayerName() {
    return player->getName();
}

/**
 * The Base Health is the maximum health that the player starts the game with.
 * @return Integer representing the maximum health of the player.
 */
int PlayerController::getPlayerBaseHealth() {
    return player->getBase();
}

/**
 * Gets the player's damage from the model.
 * @return An integer of the player's damage points.
 */
int PlayerController::getPlayerDamage() {
    return player->getDamage();
}

/**
 * Try to complete an action, such as attacking or defending from a monster.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */
bool PlayerController::tryAction() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 1); // define the range

    int actionInt = distr(eng);
    return (actionInt == 1);
}

void PlayerController::setPlayerProtection(bool toggle) {
    player->hasProtection = toggle;
}

bool PlayerController::playerHasProtection() {
    return player->hasProtection;
}

void PlayerController::Die() {
    cout << getPlayerName() << " died in battle! The treasure was never found..." << endl;
    system("pause");
    exit(0);
}