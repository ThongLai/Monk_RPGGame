#pragma once

#include "Box.h"

extern string MAINMENU[];
extern int MAINMENU_SIZE;

extern string SETTINGS[];
extern int SETTINGS_SIZE;

class MENU : public BOX
{
private:
	BOX* nBox;
	int n;
	string title;
	int x_title, y_title;
public:
	MENU();
	MENU(string title, string* content, int n, int x, int y, int width, int height, int text_color = WHITE, int bg_color = BLACK);
	~MENU();

	void setMenu(string title, string* content, int n, int x, int y, int width, int height, int text_color = WHITE, int bg_color = BLACK);
	void setBox(int _x, int _y, int _width, int _height, int _text_color = WHITE, int _bg_color = BLACK);
	void setBoxPosition(int box_index, int _x, int _y);
	void setBoxFormat(int box_index, int _width, int _height, int _text_color, int _bg_color);
	void setBoxContent(string* content);
	void setTitle(string _title);
	void setTitlePosition(int x, int y);

	void printMenu();
	void printTitle();
	void removeMenu();
	void selectedBox(int index);

	int inputMenu();
};
