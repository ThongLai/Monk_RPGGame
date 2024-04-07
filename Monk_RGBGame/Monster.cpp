#include "Monster.h"

Monster::Monster(int monsterId) {
    // Randomise the monster type. 0 = Troll, 1 = Zombie, 2 = Vampire.
    // Troll: Health = 4, Attack = 2, Defence = 3
    // Zombie: Health = 3, Attack = 4, Defence = 1
    // Vampire: Health = 3, Attack = 2, Defence = 4

    switch (monsterId) {
    default: // Default to case 0 (Troll monster)
    case(0):
        this->setName("Goblin");
        this->setBaseHealth(10);
        this->setHealth(this->getBaseHealth());
        this->setDamage(2);
        this->setDescription("Groan!");
        this->attackChance = 30;
        this->defendChance = 70;
        break;
    case(1):
        this->setName("Zombie");
        this->setBaseHealth(8);
        this->setHealth(this->getBaseHealth());
        this->setDamage(3);
        this->setDescription("Blurrrrrghhh!");
        this->attackChance = 95;
        this->defendChance = 5;
        break;
    case(2):
        this->setName("Vampire");
        this->setBaseHealth(12);
        this->setHealth(this->getBaseHealth());
        this->setDamage(2);
        this->setDescription("Mwuahahahaha!");
        this->defendChance = 65;
        this->attackChance = 35;
        break;
    }
}

int Monster::getHealth() { 
    return health; 
}

void Monster::setHealth(int h) {
    health = h; 
}

int Monster::getBaseHealth() { 
    return totalHealth; 
}

void Monster::setBaseHealth(int base) {
    totalHealth = base; 
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

void Monster::setDescription(string noise) { 
    description = noise; 
}

/**
 * Try to complete an action, such as attacking or defending from a monster.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */
bool Monster::tryAction() {
    return generateRand(0, 1) == 1;
}

int Monster::actionToPerform() {
    return (generateRand(0, 100) < this->attackChance) ? 0 : 1;
}