#include "Box.h"

//BOX
BOX::BOX()
{
	setBox(0, 0, 0, 0, WHITE, BLACK, "");
}

BOX::BOX(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content)
{
	setBox(_x, _y, _width, _height, _text_color, _bg_color, _content);
}

BOX::BOX(int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	setBox(_x, _y, _width, _height, _text_color, _bg_color, "");
}

void BOX::setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content)
{
	setPosition(_x, _y);
	setFormat(_width, _height, _text_color, _bg_color);
	setContent(_content);

}

void BOX::setPosition(int _x, int _y)
{
	x = _x; y = _y;
}

void BOX::setFormat(int _w, int _h, int _text_color, int _bg_color)
{
	width = _w; height = _h;
	text_color = _text_color; bg_color = _bg_color;
}

void BOX::setContent(string _content)
{
	content = _content;
}

void BOX::printBox()
{
	printBorder();
	printContent();
}

int BOX::getX() const
{
	return x;
}

int BOX::getY() const
{
	return y;
}

int BOX::getWidth() const
{
	return width;
}

int BOX::getHeight() const
{
	return height;
}

string BOX::getContent() const
{
	return content;
}

void BOX::printBorder()
{
	if (height <= 1 || width <= 1) return;
	Status SavedState;
	SetTextColor(DefineColor(text_color, bg_color));

	GotoXY(x, y);
	cout << char(201);
	GotoXY(x, y + height - 1);
	cout << char(200);

	GotoXY(x + width - 1, y);
	cout << char(187);
	GotoXY(x + width - 1, y + height - 1);
	cout << char(188);


	for (int ix = x + 1; ix < x + width - 1; ix++)
	{
		GotoXY(ix, y);
		cout << char(205);
		GotoXY(ix, y + height - 1);
		cout << char(205);
	}

	for (int iy = y + 1; iy < y + height - 1; iy++)
	{
		GotoXY(x, iy);
		cout << char(186);
		GotoXY(x + width - 1, iy);
		cout << char(186);
	}
}

void BOX::printContent()
{
	if (height <= 1 || width <= 1) return;
	Status SavedState;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int iy = y + 1; iy < y + height - 1; iy++) {
		for (int ix = x + 1; ix < x + width - 1; ix++)
		{
			GotoXY(ix, iy);
			cout << " ";
		}
	}

	GotoXY(x + midWidth(width, content), y + midHeight(height, 1));
	cout << content;
}

void BOX::printContent(int _text_color, int _bg_color)
{
	if (height <= 1 || width <= 1) return;
	Status SavedState;
	SetTextColor(DefineColor(_text_color, _bg_color));

	for (int iy = y + 1; iy < y + height - 1; iy++) {
		for (int ix = x + 1; ix < x + width - 1; ix++)
		{
			GotoXY(ix, iy);
			cout << " ";
		}
	}

	GotoXY(x + midWidth(width, content), y + midHeight(height, 1));
	cout << content;
}

void BOX::removeBox()
{
	if (height <= 1 || width <= 1) return;
	Status SavedState;
	SetTextColor(SavedState.getColor());

	for (int ix = x; ix < x + width; ix++)
	{
		for (int iy = y; iy < y + height; iy++) {
			GotoXY(ix, iy);
			cout << " ";
		}
	}
}
