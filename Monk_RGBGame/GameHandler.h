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

extern string MOVEROOM_PROMPT[];
extern int MOVEROOM_PROMPT_SIZE;

class GameHandler {
private:
    Player* player;
    Room* curRoom;

    int roomsExplored;

    //Timer indices
    clock_t START_TIME;
    clock_t TIME;
    clock_t PAUSE_TIME;

    //Pause game process
    bool isPause;

public:
    GameHandler();
    ~GameHandler();


    void StartUp(); //Set up when start up
    void init(); //Initialize important parameters in the game
    void subThread();

    void resetData(); //Reset values all of the attributes
    void deleteData();

    void resetGame(); //Operate the reset game process
    void processGame(); 
    void pauseGame();

    void drawGame(); //Wrap function to call all draw functions
    void drawStatus();
    void drawGUI();
    void updateTime();

    void increaseRoomCount() { roomsExplored ++; }
    int getRoomCount() { return roomsExplored; }

    void GenerateNewRooms();
    void MoveRoom();

    void Main_Menu();
    void Settings_Menu();
    int WindowMode_Settings();
    int Volumes_Settings();
};