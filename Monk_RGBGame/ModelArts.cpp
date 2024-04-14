#include "ModelArts.h"

string TITLE[] =
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
int TITLE_HEIGHT = sizeof(TITLE) / sizeof(string);
int TITLE_WIDTH = artWidth(TITLE, TITLE_HEIGHT);

string EMPTY_ROOM_ART[] =
{
	"         \\\\                *                      ",
	"                                   *              ",
	"  \\\\          *                          \\\\       ",
	"                    \\.  \\  ./                     ",
	"               \\  \\ '.  /  .' /  /                ",
	"             \\  \\  | '\\ | /' |  /  /        *     ",
	" *        ''. `. '. \\ \\ / / / .' .' .''           ",
	"         .   \\. \\ '._'. \\ .'_.' / ./   .          ",
	"        _ ''.  '.\\           ' /.'  .'' _         ",
	"      .' '-._''. -       *     - .''_.-' '.     \\\\",
	"      ___   '\\._                 _./'   ___       ",
	"\\\\      ''---...       /(    *   ...---''         ",
	"      ..........       ))\\       ..........   *   ",
	"           __...  *   ((^))      ...__            ",
	"     .--'''  _.'        |        '._  '''--.      ",
	" *     _..--' ./'.    .'\"'.    .'\\. '--.._      //",
	"       '   ./' _/' /..|   |..\\ '\\_ '\\.   '        ",
	"        ./'  _/' .' /'| ' |'\\ '. '\\_  '\\.      *  ",
	"           _/' .'  |' |  || '|  '. '\\_            ",
	"           '  /   /' ||   || '\\   \\  '            ",
	"                 |   /|  ,|\\   |   '       *      ",
	"   \\\\              . '|_  |' .                    ",
	"                      |   |          //           ",
	"          *           | '_|                   \\\\  ",
	"              .--.    |   |     *       .-.       ",
	"             /.--.\\   |   |            (..)`      ",
	"  .-. _____ ((_)) \\\\  |   |   _________('-')______",
	" (..)`  ___  `-'  // .':\":'.    _____  )___( ____ ",
	" ('-')  ________ ( `-'_____'-'.    _____________  ",
	" )___( _________  `-----------` ________  ____    ",
	"   ______________________________________________ "
};
int EMPTY_ROOM_HEIGHT = sizeof(EMPTY_ROOM_ART) / sizeof(string);
int EMPTY_ROOM_WIDTH = artWidth(EMPTY_ROOM_ART, EMPTY_ROOM_HEIGHT);

string GOBLIN_ART[] = 
{
	"                   (    )",
	"                  ((((()))",
	"                  |o\\ /o)|",
	"                  ( (  _')",
	"                   (._.  /\\__",
	"                  ,\\___,/ '  ')",
	"    '.,_,,       (  .- .   .    )",
	"     \\   \\\\     ( '        )(    )",
	"      \\   \\\\    \\.  _.__ ____( .  |",
	"       \\  /\\\\   .(   .'  /\\  '.  )",
	"        \\(  \\\\.-' ( /    \\/    \\)",
	"         '  ()) _'.-|/\\/\\/\\/\\/\\|",
	"             '\\\\ .( |\\/\\/\\/\\/\\/|",
	"               '((  \\    /\\    /",
	"               ((((  '.__\\/__.')",
	"                ((,) /   ((()   )",
	"                 \"..-,  (()(\"   /",
	"                  _//.   ((() .\"",
	"          _____ //,/\" ___ ((( ', ___",
	"                           ((  )",
	"                            / /",
	"                          _/,/'",
	"                        /,/,\"",
	"------------------------------------------------",
};
int GOBLIN_HEIGHT = sizeof(GOBLIN_ART) / sizeof(string);
int GOBLIN_WIDTH = artWidth(GOBLIN_ART, GOBLIN_HEIGHT);

string TREASURE_ART[] =
{
	"*******************************************************************************",
	"          |                   |                  |                     |       ",
	" _________|________________.=\"\"_;=.______________|_____________________|_______",
	"|                   |  ,-\"_,=\"\"     `\"=.|                  |                   ",
	"|___________________|__\"=._o`\"-._        `\"=.______________|___________________",
	"          |                `\"=._o`\"=._      _`\"=._                     |       ",
	" _________|_____________________:=._o \"=._.\"_.-=\"'\"=.__________________|_______",
	"|                   |    __.--\" , ; `\"=._o.\" ,-\"\"\"-._ \".   |                   ",
	"|___________________|_._\"  ,. .` ` `` ,  `\"-._\"-._   \". '__|___________________",
	"          |           |o`\"=._` , \"` `; .\". ,  \"-._\"-._; ;              |       ",
	" _________|___________| ;`-.o`\"=._; .\" ` '`.\"\\` . \"-._ /_______________|_______",
	"|                   | |o;    `\"-.o`\"=._``  '` \" ,__.--o;   |                   ",
	"|___________________|_| ;     (#) `-.o `\"=.`_.--\"_o.-; ;___|___________________",
	"____/______/______/___|o;._    \"      `\".o|o_.--\"    ;o;____/______/______/____",
	"/______/______/______/_\"=._o--._        ; | ;        ; ;/______/______/______/_",
	"____/______/______/______/__\"=._o--._   ;o|o;     _._;o;____/______/______/____",
	"/______/______/______/______/____\"=._o._; | ;_.--\"o.--\"_/______/______/______/_",
	"____/______/______/______/______/_____\"=.o|o_.--\"\"___/______/______/______/____",
	"/______/______/______/______/______/______/______/______/______/______/[TomekK]",
	"*******************************************************************************"
};
int TREASURE_HEIGHT = sizeof(TREASURE_ART) / sizeof(string);
int TREASURE_WIDTH = artWidth(TREASURE_ART, TREASURE_HEIGHT);


int artWidth(string* art, int height)
{
	int width = (int)art[0].size();
	for (int i = 0; i < height; i++)
		if (width < art[i].size())
			width = (int)art[i].size();

	return width;
}
void drawArt(string* art, int height, int x, int y, int text_color, int bg_color)
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int i = 0; i < height; i++)
	{
		GotoXY(x, y + i);
		cout << art[i];
	}
}
void removeArt(int height, int width, int x, int y)
{
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	for (int i = 0; i < height; i++)
	{
		GotoXY(x, y + i);
		cout << string(width, ' ');
	}
}