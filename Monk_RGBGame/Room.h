#pragma once

#include "CommonConfig.h"
#include "Player.h"

class Room {
private:
    Room* leftRoom;
    Room* rightRoom;

    string type;
    int id;
protected:
    string description;
public:
    Room(string type, bool isClear = false);
    ~Room();

    void setLeftRoom(Room *left);
    void setRightRoom(Room *right);

    Room *getLeftRoom();
    Room *getRightRoom();
    int getRoomId();

    virtual void Render(string = "") = 0;
    virtual void processRoom(Player* player) = 0;
};