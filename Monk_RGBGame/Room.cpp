#include "Room.h"

Room::Room(string type, bool isClear)
{
    this->type = type;

    if (type == "Empty Room")
        this->id = 0;
    else if (type == "Monster Room")
        this->id = 1;
    else if (type == "Treasure Room")
        this->id = 2;
    else if (type == "Puzzle Room")
        this->id = 3;
}

Room::~Room()
{
    delete leftRoom;
    delete rightRoom;
}

int Room::getRoomId()
{
    return id;
}

Room* Room::getLeftRoom() {
    return leftRoom;
}

Room* Room::getRightRoom() {
    return rightRoom; 
}

void Room::setLeftRoom(Room *left) {
    leftRoom = left;
}

void Room::setRightRoom(Room *right) {
    rightRoom = right;
}