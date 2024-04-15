#pragma once

#include "CommonConfig.h"

class BOX
{
private:
	string content;
protected:
	int x, y;
	int width, height;
	int text_color, bg_color;
public:
	BOX();
	BOX(int _x, int _y, int _width, int _height, int _text_color = WHITE, int _bg_color = BLACK, string _content = "");

	void setBox(int _x, int _y, int _width, int _height, int _text_color = WHITE, int _bg_color = BLACK, string _content = "");
	void setPosition(int _x, int _y);
	void setFormat(int _w, int _h, int _text_color, int _bg_color);
	void setContent(string _content);

	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	string getContent() const;

	void printBox();
	void printBorder();
	void printContent();
	void printContent(int _text_color, int _bg_color);
	void removeBox();
};
