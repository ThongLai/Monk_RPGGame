#pragma once

#include "CommonConfig.h"

class Room {
private:
    Room* leftDoor;
    Room* rightDoor;
    
    // If the room's actions have been completed and ready to Generate the next.
    bool isClear;

    string type;
protected:
    string description;
public:
    Room(string type, bool isClear = false);
    ~Room();

    

    virtual void Render(string = "") = 0;
    virtual void Generate(int = 0) = 0;

    virtual void setLeftRoom(Room *left);
    virtual void setRightRoom(Room *right);
    void setRoomClear(bool);

    virtual Room *getLeftRoom();
    virtual Room *getRightRoom();
    bool isRoomClear();

    virtual bool isTreasureRoom () { return false; }
};