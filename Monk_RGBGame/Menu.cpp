#include "Menu.h"

string MAINMENU[] =
{
	"Play",
	"Load Game",
	"Leader Board",
	"Instruction",
	"Settings",
	"Credits",
	"Quit",
};
int MAINMENU_SIZE = sizeof(MAINMENU) / sizeof(string);

string SETTINGS[] =
{
	"Window",
	"Audio",
	"Return"
};
int SETTINGS_SIZE = sizeof(SETTINGS) / sizeof(string);


//MENU
MENU::MENU() : n(1), title("") {
	nBox = new BOX[n];
}

MENU::MENU(string _title, string* content, int _n, int _x, int _y, int _width, int _height, int _text_color, int _bg_color) : n(_n)
{
	nBox = new BOX[n];
	setMenu(_title, content, _n, _x, _y, _width, _height, _text_color, _bg_color);
}

MENU::~MENU()
{
	delete[]nBox;
}

void MENU::setMenu(string _title, string* _content, int _n, int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	n = _n;
	setBox(_x, _y, _width, _height, _text_color, _bg_color);
	setBoxContent(_content);
	setTitle(_title);
}

void MENU::setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	setFormat(_width, _height, _text_color, _bg_color);
	setPosition(_x, _y);

	for (int i = 0; i < n; i++)
	{
		setBoxPosition(i, _x, _y + i * (_height));
		setBoxFormat(i, _width, _height, _text_color, _bg_color);
	}
}

void MENU::setBoxPosition(int box_index, int _x, int _y)
{
	nBox[box_index].setPosition(_x, _y);
}

void MENU::setBoxFormat(int box_index, int _width, int _height, int _text_color, int _bg_color)
{
	nBox[box_index].setFormat(_width, _height, _text_color, _bg_color);
}

void MENU::setBoxContent(string* content)
{
	for (int i = 0; i < n; i++)
		nBox[i].setContent(content[i]);
}

void MENU::setTitle(string _title)
{
	title = _title;
}

void MENU::printMenu()
{
	printTitle();

	for (int i = 0; i < n; i++)
		nBox[i].printBox();
}

void MENU::printTitle()
{
	Status SavedState;
	SetTextColor(DefineColor(text_color, bg_color));

	GotoXY(x + midWidth(width, title), y - height);
	cout << title;
}

void MENU::selectedBox(int index)
{
	nBox[index].printContent(BLACK, LIGHTGRAY);
}

int MENU::inputMenu()
{
	int i = 0;
	char input;
	bool isPress = false;
	while (true)
	{
		if (isPress) {
			selectedBox(i);
			isPress = false;	
		}

		if (_kbhit())
		{
			mciSendString(TEXT("play Menu_Select from 0"), NULL, 0, NULL);

			isPress = true;
			input = toupper(_getch());

			if (input == -32)
				input = toupper(_getch());

			if (input == KEY_UP || input == 'W')
			{
				nBox[i].printContent();
				i = (i == 0) ? i = n - 1 : i -= 1;
			}
			else if (input == KEY_DOWN || input == 'S')
			{
				nBox[i].printContent();
				i = (i == n - 1) ? i = 0 : i += 1;
			}
			else if (input == ENTER)
			{
				return i;
			}
			else if (input == ESC)
			{
				return -1;
			}
		}
	}
}