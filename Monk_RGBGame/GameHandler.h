#pragma once

// Game Objects Dependencies
#include "Menu.h"
#include "ModelArts.h"
#include "CommonConfig.h"

// Controller Dependencies
#include "MonsterController.h"
#include "PlayerController.h"
#include "Logs.h"

// Model Dependencies
#include "PlayerModel.h"
#include "MonsterModel.h"

// Room Dependencies
#include "MonsterRoom.h"
#include "EmptyRoom.h"
#include "TreasureRoom.h"
#include "PuzzleRoom.h"

class GameHandler {
private:
    MonsterController* monsterController;
    PlayerController* playerController;
    MonsterModel* monsterModel;
    MonsterRoom* monsterRoom;
    int roomsExplored = 0;

    int treasureChance = 5;
    int emptyChance = 27;
    int monsterChance = 58;
    int puzzleChance = 10;

    Room* curRoom;

    //Timer indices
    clock_t START_TIME;
    clock_t TIME;
    clock_t PAUSE_TIME;

    //Logs modifier
    Logs* logs;

public:
    GameHandler();
    
    void StartUp(); //Set up when start up
    void init(); //Initialize important parameters in the game
    void resetData(); //Reset values all of the attributes

    void resetGame(); //Operate the reset game process


    void setPlayer(string playerName, string description);

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

    void Main_Menu();
    void Settings_Menu();
    int WindowMode_Settings();
    int Volumes_Settings();
};