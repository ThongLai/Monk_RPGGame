//
// Created by Mike on 08/03/2019.
//

#include "MonsterController.h"
#include <list>
#include <random>

MonsterController::MonsterController(int monsterId) {
    _model = new MonsterModel();

    // Randomise the monster type. 0 = Troll, 1 = Zombie, 2 = Vampire.
    // Troll: Health = 4, Attack = 2, Defence = 3
    // Zombie: Health = 3, Attack = 4, Defence = 1
    // Vampire: Health = 3, Attack = 2, Defence = 4

    switch(monsterId) {
        default: // Default to case 0 (Troll monster)
        case(0):
            _model->setName("Goblin");
            _model->setBaseHealth(10);
            _model->setHealth(_model->getBaseHealth());
            _model->setAttack(2);
            _model->setIntroductionNoise("Groan!");
            _model->attackChance = 30;
            _model->defendChance = 70;
            break;
        case(1):
            _model->setName("Zombie");
            _model->setBaseHealth(8);
            _model->setHealth(_model->getBaseHealth());
            _model->setAttack(3);
            _model->setIntroductionNoise("Blurrrrrghhh!");
            _model->attackChance = 95;
            _model->defendChance = 5;
            break;
        case(2):
            _model->setName("Vampire");
            _model->setBaseHealth(12);
            _model->setHealth(_model->getBaseHealth());
            _model->setAttack(2);
            _model->setIntroductionNoise("Mwuahahahaha!");
            _model->defendChance = 65;
            _model->attackChance = 35;
            break;
    }
}

int MonsterController::getMonsterHealth() {
    return _model->getHealth();
}

string MonsterController::getMonsterName() {
    return _model->getName();
}

string MonsterController::getMonsterNoise() {
    return _model->getIntroductionNoise();
}

int MonsterController::getMonsterBaseHealth() {
    return _model->getBaseHealth();
}

void MonsterController::setMonsterHealth(int value) {
    _model->setHealth(value);
}

void MonsterController::subtractMonsterHealth(int value) {
    _model->setHealth(_model->getHealth() - value);
}

int MonsterController::getMonsterAttackPoints() {
    return _model->getAttackPoints();
}

/**
 * Try to complete an action, such as attacking or defending from a monster.
 * tryAction generates a number between 0 or 1, determining whether the action attempted was successful.
 * 0 = unsuccessful
 * 1 = successful
 *
 * @return Boolean of whether the action was successful or not.
 */
bool MonsterController::tryAction() {
    int actionInt = rngAction(0, 1);

    return (actionInt == 1);
}

int MonsterController::actionToPerform() {
    const int ATTACK = 0, DEFEND = 1;

    int action = rngAction(0, 100);

    if(action < _model->attackChance) {
        return ATTACK;
    }
    else {
        return DEFEND;
    }
}

int MonsterController::rngAction(int from, int to) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(from, to); // define the range

    int actionInt = distr(eng);
    return actionInt;
}