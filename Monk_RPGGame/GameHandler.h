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

    //Catch other buttons from the keyboard to check whether it is a command or not
    string buf;

    int treasure_room_chance;
    int empty_room_chance;
    int monster_room_chance;
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

    void drawGame(); //Wrap function to call all draw functions
    void drawStatus();
    void drawGUI();
    void checkUnDeadCMD(); //Check whether the player types a command or not
    void addBuf(char key); //Catch a key from keyboard
    void displayCommand();

    void GenerateNewRooms();
    void MoveRoom();

    void Main_Menu();
    void Settings_Menu();
    int WindowMode_Settings();
};