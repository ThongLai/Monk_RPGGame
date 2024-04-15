#pragma once

#include "CommonConfig.h"
#include "Player.h"
#include "Menu.h"
#include "ModelArts.h"

class Room {
private:
    Room* leftRoom;
    Room* rightRoom;

    string roomName;
    string description;

    int nameColor;
    int descColor;
public:
    Room(string roomName, int nameColor = WHITE, int descColor = WHITE);
    ~Room();

    void setDescription(string description);
    void setLeftRoom(Room *left);
    void setRightRoom(Room* right);

    string getName();
    string getDescription();
    Room *getLeftRoom();
    Room *getRightRoom();

    void displayRoomNameAndDesc();
    void removeRoomName();
    virtual bool processRoom(Player* player) = 0;
};