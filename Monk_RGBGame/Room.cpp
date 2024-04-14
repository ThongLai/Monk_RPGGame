#include "Room.h"

Room::Room(string roomName, int nameColor, int descColor)
{
    this->roomName = roomName;
    this->nameColor = nameColor;
    this->descColor = descColor;
    this->leftRoom = this->rightRoom = NULL;
}

Room::~Room()
{
    removeMess(roomName, midWidth(GAMEPLAY_W, roomName.size()), GAMEPLAY_H + 1);

    delete leftRoom;
    delete rightRoom;
}

void Room::setDescription(string description)
{
    this->description = description;
}

void Room::setLeftRoom(Room *left) {
    leftRoom = left;
}

void Room::setRightRoom(Room *right) {
    rightRoom = right;
}

string Room::getName()
{
    return roomName;
}

string Room::getDescription()
{
    return description;
}

Room* Room::getLeftRoom() {
    return leftRoom;
}

Room* Room::getRightRoom() {
    return rightRoom;
}

void Room::displayRoomNameAndDesc()
{
    printString(roomName, midWidth(GAMEPLAY_W, roomName.size()), GAMEPLAY_H + 1, nameColor);
    printOnDescriptionAndWait(description, midWidth(GAMEPLAY_W, description.size()), GAMEPLAY_H + midHeight(DESCRIPTION_H, 1), descColor);
}

void Room::removeRoomName()
{
    printString(string(roomName.size(), ' '), midWidth(GAMEPLAY_W, roomName.size()), GAMEPLAY_H + 1, nameColor);
}