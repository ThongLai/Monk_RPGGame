//
// Created by Mike on 08/03/2019.
//

#ifndef MONKASSIGNMENT_MONSTERMODEL_H
#define MONKASSIGNMENT_MONSTERMODEL_H

#include <string>
using namespace std;

class MonsterModel {
public:
    int getHealth(){ return health; }
    void setHealth(int h) { health = h; }
    int getBaseHealth() { return totalHealth; }
    void setBaseHealth(int base) { totalHealth = base; }
    void subtractHealth(int amount) { health -= amount; }
    void setName(string monsterName) { name = monsterName; }
    string getName() { return name; }
    void setAttack(int attack) { attackPoints = attack; }
    int getAttackPoints() { return attackPoints; }
    string getIntroductionNoise() { return introNoise; }
    void setIntroductionNoise (string noise) { introNoise = std::move(noise); }
    int attackChance;
    int defendChance;
private:
    int health;
    int totalHealth;
    int attackPoints;
    string name;
    string introNoise;
};


#endif //MONKASSIGNMENT_MONSTERMODEL_H
