#pragma once

// Game Objects Dependencies
#include "Menu.h"
#include "ModelArts.h"
#include "CommonConfig.h"
#include "Logs.h"

// Entites Dependencies
#include "Monster.h"
#include "Player.h"

// Room Dependencies
#include "MonsterRoom.h"
#include "EmptyRoom.h"
#include "TreasureRoom.h"
#include "PuzzleRoom.h"

class GameHandler {
private:
    Player* player;
    Room* curRoom;

    int roomsExplored = 0;

    //Timer indices
    clock_t START_TIME;
    clock_t TIME;
    clock_t PAUSE_TIME;

    //Logs modifier
    Logs* logs;

public:
    GameHandler();
    ~GameHandler();

    
    void StartUp(); //Set up when start up
    void init(); //Initialize important parameters in the game
    void resetData(); //Reset values all of the attributes
    void deleteData();

    void resetGame(); //Operate the reset game process
    void startGame(); 

    void increaseRoomCount() { roomsExplored ++; }
    int getRoomCount() { return roomsExplored; }

    void GenerateNewRooms();
    void MoveRoom();

    void BeginCombat();
    void BeginPuzzle();
    void ExploreEmptyRoom();
    void CombatTryAttack(Monster*, int);
    void CombatTryDefend(Monster*, int);

    void Main_Menu();
    void Settings_Menu();
    int WindowMode_Settings();
    int Volumes_Settings();
};