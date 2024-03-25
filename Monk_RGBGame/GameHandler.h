#pragma once

#include "CommonConfig.h"


// Controller Dependencies
#include "MonsterController.h"
#include "LogController.h"

// Model Dependencies
#include "PlayerModel.h"
#include "MonsterModel.h"

// Room Dependencies
#include "MonsterRoom.h"
#include "EmptyRoom.h"
#include "TreasureRoom.h"
#include "RandomController.h"
#include "PuzzleRoom.h"

class GameHandler {
public:
    GameHandler(string playerName, string description);
    void increaseRoomCount() { roomsExplored ++; }
    int getRoomCount() { return roomsExplored; }
    void GenerateRoom(Room*, string);
    void BeginCombat();
    void BeginPuzzle();
    int rngRoomId();
    void ExploreEmptyRoom();
    void MoveRoom();
    void CombatTryAttack(MonsterRoom*, int);
    void CombatTryDefend(MonsterRoom*, int);
private:
    MonsterController* monsterController;
    PlayerController* playerController;
    MonsterModel* monsterModel;
    LogController* logController;
    MonsterRoom* monsterRoom;
    RandomController* randomController;
    int roomsExplored = 0;

    int treasureChance  = 5;
    int emptyChance     = 27;
    int monsterChance   = 58;
    int puzzleChance    = 10;

    Room* currentRoom;
};