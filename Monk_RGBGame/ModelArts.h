#pragma once
#include "CommonConfig.h"

extern string title[];
extern int title_height;
extern int title_width;

int artWidth(string* art, int height);
void drawArt(string* art, int height, int x, int y, int text_color = generateRand(1, 15), int bg_color = BLACK);