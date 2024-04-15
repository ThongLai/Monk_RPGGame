#include "Entity.h"

Entity::Entity() {
    name = description = "";
    color = WHITE;
    health = baseHealth = damage = cancel_chance = 0;
}

// Getters
int Entity::getHealth() { 
    return health; 
}

void Entity::setHealth(int health) {
    this->health = health < baseHealth ? health : baseHealth;
}

int Entity::getBaseHealth() { 
    return baseHealth; 
}

// Setters
void Entity::setBaseHealth(int baseHealth) {
    this->baseHealth = baseHealth;
}

void Entity::setCancelChance(int cancel_chance)
{
    this->cancel_chance = cancel_chance;
}

void Entity::takeDamage(int amount) {
    health -= amount; 
}

void Entity::setName(string monsterName) { 
    name = monsterName; 
}

string Entity::getName() {
    return name; 
}

void Entity::setDamage(int attack) { 
    damage = attack; 
}

int Entity::getDamage() { 
    return damage; 
}

string Entity::getDescription() { 
    return description; 
}

int Entity::getColor()
{
    return color;
}

void Entity::setDescription(string description) {
    this->description = description;
}

void Entity::setColor(int monsterColor)
{
    this->color = monsterColor;
}

/**
 * Try to cancel an action, such as attacking or defending.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */
bool Entity::tryCancelAction() {
    return (generateRand(0, 100) < cancel_chance) ? true : false;
}   

bool Entity::isAlive() {
    return health > 0;
}

void Entity::displayHealth()
{
    string monster_health = name + ": [" + to_string(health) + " / " + to_string(baseHealth) + "]";
    printString(monster_health, midWidth(GAMEPLAY_W, monster_health.size()), GAMEPLAY_H + DESCRIPTION_H * 1 / 4, color);
}

void Entity::removeHealth()
{
    string monster_health = name + ": [" + to_string(health) + " / " + to_string(baseHealth) + "]";
    printString(string(monster_health.size(), ' '), midWidth(GAMEPLAY_W, monster_health.size()), GAMEPLAY_H + DESCRIPTION_H * 1 / 4);
}