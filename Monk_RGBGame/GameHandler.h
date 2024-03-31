#pragma once

<<<<<<< HEAD
// Game Objects Dependencies
#include "Menu.h"
#include "ModelArts.h"
=======
#include "CommonConfig.h"
>>>>>>> origin/main


// Controller Dependencies
#include "MonsterController.h"
<<<<<<< HEAD
#include "Logs.h"
=======
#include "LogController.h"
>>>>>>> origin/main

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
<<<<<<< HEAD
private:
    MonsterController* monsterController;
    PlayerController* playerController;
    MonsterModel* monsterModel;
    MonsterRoom* monsterRoom;
    RandomController* randomController;
    int roomsExplored = 0;

    int treasureChance = 5;
    int emptyChance = 27;
    int monsterChance = 58;
    int puzzleChance = 10;

    Room* currentRoom;

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
=======
public:
    GameHandler(string playerName, string description);
>>>>>>> origin/main
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
<<<<<<< HEAD

    void Main_Menu();
    void Settings_Menu();
    int WindowMode_Settings();
    int Volumes_Settings();

=======
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
>>>>>>> origin/main
};