#pragma once

#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <vector>

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

extern int GAMEPLAY_W;
extern int STATUS_W;
extern int SAVE_SIZE;
extern int LEADERBOARD_SIZE;

//Rooms Chances
extern int TREASURE_ROOM_CHANCE;
extern int PUZZLE_ROOM_CHANCE;
extern int EMPTY_ROOM_CHANCE;
extern int MONSTER_ROOM_CHANCE;

//Entities Parameters
extern int PLAYER_BASE_HEALTH;
extern int PLAYER_BASE_DAMAGE;

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

int midWidth(int width, string message);
int midWidth(int width, int content_width);
int midHeight(int height, int content_height);
void printMessCenter(string message, int text_color = WHITE, int bg_color = BLACK);

int generateRand(int from, int to);

// Sounds and Musics
void SetAllVolumes(int volume);


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