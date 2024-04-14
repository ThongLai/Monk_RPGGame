#pragma once
#include "CommonConfig.h"

extern string TITLE[];
extern int TITLE_HEIGHT;
extern int TITLE_WIDTH;

//Empty Room
extern string EMPTY_ROOM_ART[];
extern int EMPTY_ROOM_HEIGHT;
extern int EMPTY_ROOM_WIDTH;

//Monsters
extern string GOBLIN_ART[];
extern int GOBLIN_HEIGHT;
extern int GOBLIN_WIDTH;

//Treasure
extern string TREASURE_ART[];
extern int TREASURE_HEIGHT;
extern int TREASURE_WIDTH;


int artWidth(string* art, int height);
void drawArt(string* art, int height, int x, int y, int text_color = generateRand(1, 15), int bg_color = BLACK);
void removeArt(int height, int width, int x, int y);