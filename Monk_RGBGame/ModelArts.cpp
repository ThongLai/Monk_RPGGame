#include "ModelArts.h"

string title[] =
{
"     ______  _______           _____  _____   ______    ____    ____  ",
"    |      \\/       \\     ____|\\    \\|\\    \\ |\\     \\  |    |  |    | ",
"   /          /\\     \\   /     /\\    \\\\\\    \\| \\     \\ |    |  |    | ",
"  /     /\\   / /\\     | /     /  \\    \\\\|    \\  \\     ||    | /    // ",
" /     /\\ \\_/ / /    /||     |    |    ||     \\  |    ||    |/ _ _//  ",
"|     |  \\|_|/ /    / ||     |    |    ||      \\ |    ||    |\\    \\'  ",
"|     |       |    |  ||\\     \\  /    /||    |\\ \\|    ||    | \\    \\  ",
"|\\____\\       |____|  /| \\_____\\/____/ ||____||\\_____/||____|  \\____\\ ",
"| |    |      |    | /  \\ |    ||    | /|    |/ \\|   |||    |   |    |",
" \\|____|      |____|/    \\|____||____|/ |____|   |___|/|____|   |____|",
"    \\(          )/          \\(    )/      \\(       )/    \\(       )/  ",
"     '          '            '    '        '       '      '       '   ",
};
int title_height = sizeof(title) / sizeof(string);
int title_width = artWidth(title, title_height);


int artWidth(string* art, int height)
{
	int width = (int)art[0].size();
	for (int i = 0; i < height; i++)
		if (width < art[i].size())
			width = (int)art[i].size();

	return width;
}