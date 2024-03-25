#pragma once

#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
//#include <random>
using namespace std;
#pragma comment(lib, "Winmm.lib")

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESC 27

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

WORD DefineColor(int t_color, int t_background);
void SetTextColor(WORD wColor);
void GotoXY(int x, int y);
bool GetXY(int& x, int& y);
bool GetColor(int& color);
int midWidth(int width, string message);
int midWidth(int width, int content_width);
int midHeight(int height, int content_height);
void printMessCenter(string message);


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