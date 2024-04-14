#include "Monster.h"

Monster::Monster() {
    name = description = "";
    monsterColor = WHITE;
    health = baseHealth = damage = cancel_chance = attack_chance = 0;
}

int Monster::getHealth() { 
    return health; 
}

void Monster::setHealth(int h) {
    health = h; 
}

int Monster::getBaseHealth() { 
    return baseHealth; 
}

void Monster::setBaseHealth(int base) {
    baseHealth = base; 
}

void Monster::takeDamage(int amount) {
    health -= amount; 
}

void Monster::setName(string monsterName) { 
    name = monsterName; 
}

string Monster::getName() {
    return name; 
}

void Monster::setDamage(int attack) { 
    damage = attack; 
}

int Monster::getDamage() { 
    return damage; 
}

string Monster::getDescription() { 
    return description; 
}

int Monster::getMonsterColor()
{
    return monsterColor;
}

void Monster::setDescription(string noise) { 
    description = noise; 
}

void Monster::setMonsterColor(int monsterColor)
{
    this->monsterColor = monsterColor;
}

/**
 * Try to cancel an action, such as attacking or defending.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */
bool Monster::tryCancelAction() {
    return (generateRand(0, 100) < cancel_chance) ? true : false;
}

int Monster::actionToPerform() {
    return (generateRand(0, 100) < attack_chance) ? 0 : 1;
}

bool Monster::isAlive() {
    return health > 0;
}

void Monster::displayHealth()
{
    string monster_health = name + ": [" + to_string(health) + " / " + to_string(baseHealth) + "]";
    printString(monster_health, midWidth(GAMEPLAY_W, monster_health.size()), GAMEPLAY_H + DESCRIPTION_H * 1 / 4, monsterColor);
}

void Monster::removeHealth()
{
    string monster_health = name + ": [" + to_string(health) + " / " + to_string(baseHealth) + "]";
    printString(string(monster_health.size(), ' '), midWidth(GAMEPLAY_W, monster_health.size()), GAMEPLAY_H + DESCRIPTION_H * 1 / 4);
}