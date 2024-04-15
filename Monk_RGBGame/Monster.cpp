#include "Monster.h"

Monster::Monster() : Entity()
{
    artModel = NULL;
    artHeight = artWidth = 0;
    attack_chance = 0;
}

string* Monster::getArtModel()
{
    return artModel;
}

int Monster::getArtHeight()
{
    return artHeight;
}

int Monster::getArtWidth()
{
    return artWidth;
}

void Monster::setArtModel(string* artModel)
{
    this->artModel = artModel;
}

void Monster::setArtHeight(int artHeight)
{
    this->artHeight = artHeight;
}

void Monster::setArtWidth(int artWidth)
{
    this->artWidth = artWidth;
}

void Monster::setAttackChance(int attack_chance)
{
    this->attack_chance = attack_chance;
}

int Monster::actionToPerform() {
    return (generateRand(0, 100) < attack_chance) ? 0 : 1;
}