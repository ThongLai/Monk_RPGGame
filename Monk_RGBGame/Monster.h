#pragma once

#include "CommonConfig.h"
#include "ModelArts.h"

class Monster {
private:
    string name;
    string description;
    int monsterColor;

    int health;
    int baseHealth;
    int damage;

    string* artModel;
    int artHeight;
    int artWidth;
protected:
    int cancel_chance;
    int attack_chance;
public:
    Monster();
    
    string getName();
    string getDescription();
    int getMonsterColor();
    int getHealth();
    int getDamage();
    int getBaseHealth();
    string* getArtModel();
    int getArtHeight();
    int getArtWidth();

    void setName(string monsterName);
    void setDescription(string noise);
    void setMonsterColor(int monsterColor);
    void setHealth(int health);
    void setDamage(int damage);
    void setBaseHealth(int base);
    void setArtModel(string* artModel);
    void setArtHeight(int artHeight);
    void setArtWidth(int artWidth);

    void takeDamage(int amount);
    bool tryCancelAction();
    int actionToPerform();
    bool isAlive();

    void displayHealth();
    void removeHealth();
};