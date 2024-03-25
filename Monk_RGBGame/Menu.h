#pragma once
#include "Box.h"

class MENU : public BOX
{
private:
	BOX* nBox;
	int n;
	string title;
public:
	MENU();
	MENU(string title, string* content, int n, int x, int y, int width, int height, int text_color, int bg_color);
	~MENU();

	void setMenu(string title, string* content, int n, int x, int y, int width, int height, int text_color, int bg_color);
	void setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color);
	void setBoxPosition(int box_index, int _x, int _y);
	void setBoxFormat(int box_index, int _width, int _height, int _text_color, int _bg_color);
	void setBoxContent(string* content);
	void setTitle(string _title);

	void printMenu();
	void printTitle();
	void selectedBox(int index);

	int inputMenu();
};
