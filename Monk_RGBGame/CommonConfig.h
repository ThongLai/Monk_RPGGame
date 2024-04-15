#pragma once

#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <random>
#include <thread>
#include <iomanip>

using namespace std;
#pragma comment(lib, "Winmm.lib")

// Define keys from keyboards
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESC 27

// Define Color's Codes
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15

// Gameplay Parameters
extern int SCREEN_WIDTH_PXL;
extern int SCREEN_HEIGHT_PXL;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern string STATUS_VAR[];
extern int STATUS_VAR_SIZE;

extern string GUIDEBUTTONS[];
extern int GUIDEBUTTONS_SIZE;

extern int GAMEPLAY_W;
extern int GAMEPLAY_H;
extern int DESCRIPTION_H;
extern int STATUS_W;

extern int BUF;
extern string CHEATCODE;
extern bool UNDEADCMD;


//Rooms Chances
extern int TREASURE_ROOM_CHANCE;
extern int EMPTY_ROOM_CHANCE;
extern int MONSTER_ROOM_CHANCE;

extern int TREASURE_ROOM_COLOR;
extern int EMPTY_ROOM_COLOR;
extern int MONTER_ROOM_COLOR;

//Item Chances
extern int ITEM_CHANCE;
extern int SWORD_CHANCE;
extern int SHEILD_CHANCE;
extern int CACTUS_CHANCE;

//Entities Parameters
// Player
extern int PLAYER_COLOR;
extern int PLAYER_BASE_HEALTH;
extern int PLAYER_BASE_DAMAGE;
extern int PLAYER_CANCEL_ACTION_CHANCE;

// Monsters
extern int GOBLIN_COLOR;
extern int GOBLIN_BASE_HEALTH;
extern int GOBLIN_BASE_DAMAGE;
extern int GOBLIN_CANCEL_ACTION_CHANCE;
extern int GOBLIN_ATK_DEF_CHANCE;

extern int CHUPACABRA_COLOR;
extern int CHUPACABRA_BASE_HEALTH;
extern int CHUPACABRA_BASE_DAMAGE;
extern int CHUPACABRA_CANCEL_ACTION_CHANCE;
extern int CHUPACABRA_ATK_DEF_CHANCE;

extern int FOOT_COLOR;
extern int FOOT_BASE_HEALTH;
extern int FOOT_BASE_DAMAGE;
extern int FOOT_CANCEL_ACTION_CHANCE;
extern int FOOT_ATK_DEF_CHANCE;


// Set up when starting up functions
void setRasterFonts();
void SetWindowSize(int width, int height);
void FixConsoleWindow();
void HideCursor();
void SetUpParameters();

void FullScreenMode();
void WindowedMode();
void GetWindowSize();
WORD DefineColor(int t_color, int t_background);
void SetTextColor(WORD wColor);
void GotoXY(int x, int y);
bool GetXY(int& x, int& y);
bool GetColor(int& color);

int generateRand(int from, int to);
int midWidth(int width, string message);
int midWidth(int width, int content_width);
int midHeight(int height, int content_height);

void printString(string message, int X, int Y, int text_color = WHITE, int bg_color = BLACK);
void printStringCenter(string message, int text_color = WHITE, int bg_color = BLACK);
void printStringCenterGameplay(string message, int text_color = WHITE, int bg_color = BLACK);
void removeString(string message, int X, int Y);
void removeStringCenter(string message);

void printOnDescriptionAndWait(string prompt, int X, int Y = GAMEPLAY_H + midHeight(DESCRIPTION_H, 1), int text_color = WHITE, int bg_color = BLACK);
void printOnDescriptionCenterAndWait(string prompt, int text_color = WHITE, int bg_color = BLACK);

void printOnGameplayAndWait(string prompt, int X, int Y = midHeight(GAMEPLAY_H, 1), int text_color = WHITE, int bg_color = BLACK);
void printOnGameplayCenterAndWait(string prompt, int text_color = WHITE, int bg_color = BLACK);

void waitForKeyBoard(int X = SCREEN_WIDTH / 20, int Y = SCREEN_HEIGHT / 20);
string waitForInput(string prompt, int X, int Y, int text_color = WHITE, int bg_color = BLACK);

//Save status of coordinates and text/background color
class Status
{
private:
    int X, Y;
    int COLOR;
public:
    Status();
    ~Status();
    int getX();
    int getY();
    int getColor();

    void ResetToCurrent();
};