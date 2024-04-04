#include "Room.h"

Room::Room(string type, bool isClear)
{
    this->type = type;
    this->isClear = isClear;
}

Room::~Room()
{
    delete leftDoor;
    delete rightDoor;
}

void Room::Generate(int)
{
}

bool Room::isRoomClear()
{
    return isClear;
}

Room* Room::getLeftRoom() {
    return leftDoor;
}

Room* Room::getRightRoom() {
    return rightDoor; 
}

void Room::setLeftRoom(Room *left) {
    leftDoor = left;
}

void Room::setRoomClear(bool isClear)
{
    this->isClear = isClear;
}

void Room::setRightRoom(Room *right) {
    rightDoor = right;
}