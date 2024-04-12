#pragma once

// Game Objects Dependencies
#include "Menu.h"
#include "ModelArts.h"
#include "CommonConfig.h"

// Entites Dependencies
#include "Monster.h"
#include "Player.h"

// Room Dependencies
#include "MonsterRoom.h"
#include "EmptyRoom.h"
#include "TreasureRoom.h"
#include "PuzzleRoom.h"

extern string STATUS_VAR[];
extern int STATUS_VAR_SIZE;

extern string GUIDEBUTTONS[];
extern int GUIDEBUTTONS_SIZE;   

class GameHandler {
private:
    Player* player;
    Room* curRoom;

    int roomsExplored = 0;

    //Timer indices
    clock_t START_TIME;
    clock_t TIME;
    clock_t PAUSE_TIME;

public:
    GameHandler();
    ~GameHandler();

    
    void StartUp(); //Set up when start up
    void init(); //Initialize important parameters in the game
    void resetData(); //Reset values all of the attributes
    void deleteData();

    void resetGame(); //Operate the reset game process
    void startGame(); 

    void drawGame(); //Wrap function to call all draw functions
    void drawStatus();
    void drawGUI();

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