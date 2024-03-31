//
// Created by Mike on 09/03/2019.
//

#include "PlayerModel.h"

PlayerModel::PlayerModel(int baseDamage, const string &playerName, const string &description) {
    this->name = playerName;
    this->health = BASE_HEALTH;
    this->damage = baseDamage;
    this->description = description;
}

const string &PlayerModel::getName() const {
    return name;
}

void PlayerModel::setName(const string &name) {
    PlayerModel::name = name;
}

const string &PlayerModel::getDescription() const {
    return description;
}

void PlayerModel::setDescription(const string &description) {
    PlayerModel::description = description;
}

int PlayerModel::getHealth() {
    return this->health;
}

void PlayerModel::setHealth(int value) {
    this->health = value;
}

int PlayerModel::getDamage() {
    return this->damage;
}

int PlayerModel::getBase() {
    return BASE_HEALTH;
}
