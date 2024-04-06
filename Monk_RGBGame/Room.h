#pragma once

#include "CommonConfig.h"

class Room {
private:
    Room* leftRoom;
    Room* rightRoom;
    
    // If the room's actions have been completed and ready to Generate the next.
    bool isClear;

    string type;
    int id;
protected:
    string description;
public:
    Room(string type, bool isClear = false);
    ~Room();

    virtual void Render(string = "") = 0;

    void setLeftRoom(Room *left);
    void setRightRoom(Room *right);
    void setRoomClear(bool);

    Room *getLeftRoom();
    Room *getRightRoom();
    bool isRoomClear();
    int getRoomId();

    virtual bool isTreasureRoom () { return false; }
};