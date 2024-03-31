//
// Created by Mike on 08/03/2019.
//
#pragma once

#ifndef MONKASSIGNMENT_ROOM_H
#define MONKASSIGNMENT_ROOM_H

#include "MonsterController.h"
#include "PlayerController.h"

using namespace std;

class Room {
public:
    Room();
    Room(Room*);
    virtual void Generate(){};
    virtual void setEnteredFrom(Room *previousRoom); // Set the exit to the previous room.
    virtual void Render(){};
    virtual void Render(string){};
    virtual void Generate(int){};

    virtual void setLeftRoom(Room *left);

    virtual void setRightRoom(Room *right);

    virtual Room *getLeftRoom();

    virtual Room *getRightRoom();
    bool isRoomComplete = false; // If the room's actions have been completed and ready to Generate the next.
    virtual bool isTreasureRoom () { return false; }

    /*virtual bool isMonsterAlive();

    // Methods from the MonsterController
    virtual int getMonsterHealth();
    virtual int getMonsterBaseHealth();
    virtual string getMonsterName();
    virtual string getMonsterNoise();
    virtual void setMonsterHealth(int value);
    virtual void subtractMonsterHealth(int value);
    virtual int getMonsterAttackPoints();
    virtual bool monsterTryAction();
    virtual int monsterActionToPerform();*/
private:
    Room* enteredFrom;
    Room* leftDoor;
    Room* rightDoor;
};
/*

class EmptyRoom {
public:
    EmptyRoom();
private:
};

class MonsterRoom {
public:
    MonsterRoom(MonsterController* monster);
    MonsterController * getMonster();

private:
    MonsterController* monster;
};

class TreasureRoom {
public:
    bool collected;

private:

};
*/

#endif //MONKASSIGNMENT_ROOM_H
