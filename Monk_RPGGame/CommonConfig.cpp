#include "CommonConfig.h"

int SCREEN_WIDTH_PXL = 1633;
int SCREEN_HEIGHT_PXL = 900;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

string STATUS_VAR[] = {
    "Health: ",
    "Attack: ",
    "Rooms: ",
};
int STATUS_VAR_SIZE = sizeof(STATUS_VAR) / sizeof(string);

string GUIDEBUTTONS[] =
{
    "<P> - Pause/Continue",
    "<R> - Reset Game",
    "<Esc> - Return to Main Menu"
};
int GUIDEBUTTONS_SIZE = sizeof(GUIDEBUTTONS) / sizeof(string);

int GAMEPLAY_W;
int GAMEPLAY_H;
int DESCRIPTION_H;
int STATUS_W;

int BUF;
string CHEATCODE = "THONG";
bool UNDEADCMD = false; //Indicate the UNDEAD mode (for testing game)

// Default Chances: 5/35/60
int TREASURE_ROOM_CHANCE = 5;
int EMPTY_ROOM_CHANCE = 35;
int MONSTER_ROOM_CHANCE = 60;

int TREASURE_ROOM_COLOR = YELLOW;
int EMPTY_ROOM_COLOR = CYAN;
int MONTER_ROOM_COLOR = LIGHTRED;

// Items Chances: 20/20/30/50
int ITEM_CHANCE = 20;
int SWORD_CHANCE = 20;
int SHEILD_CHANCE = 30;
int CACTUS_CHANCE = 50;

// Entities Parameters
// Player: Health = 15, Attack = 3, Cancel Chance = 30
int PLAYER_COLOR = LIGHTCYAN;
int PLAYER_BASE_HEALTH = 15;
int PLAYER_BASE_DAMAGE = 3;
int PLAYER_CANCEL_ACTION_CHANCE = 50;

// Goblin: Health = 10, Attack = 3, Cancel Chance = 15, ATK/DEF Chance = 30
int GOBLIN_COLOR = GREEN;
int GOBLIN_BASE_HEALTH = 10;
int GOBLIN_BASE_DAMAGE = 2;
int GOBLIN_CANCEL_ACTION_CHANCE = 15;
int GOBLIN_ATK_DEF_CHANCE = 30;

// Chupacabra: Health = 20, Attack = 4, Cancel Chance = 30, ATK/DEF Chance = 50
int CHUPACABRA_COLOR = DARKGRAY;
int CHUPACABRA_BASE_HEALTH = 15;
int CHUPACABRA_BASE_DAMAGE = 4;
int CHUPACABRA_CANCEL_ACTION_CHANCE = 30;
int CHUPACABRA_ATK_DEF_CHANCE = 50;

// Foot: Health = 8, Attack = 1, Cancel Chance = 50, ATK/DEF Chance = 30
int FOOT_COLOR = BROWN;
int FOOT_BASE_HEALTH = 8;
int FOOT_BASE_DAMAGE = 1;
int FOOT_CANCEL_ACTION_CHANCE = 50;
int FOOT_ATK_DEF_CHANCE = 30;

// Set up when starting up functions
void setRasterFonts()
{
    CONSOLE_FONT_INFOEX cf = { 0 };
    cf.cbSize = sizeof cf;
    cf.dwFontSize.X = 10;
    cf.dwFontSize.Y = 18;
    wcscpy_s(cf.FaceName, L"Terminal");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
}
void SetWindowSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    //MoveWindow(window_handle, x, y, width, height, redraw_window);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void HideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void SetUpParameters()
{
    GetWindowSize();
    GAMEPLAY_W = int(0.75 * SCREEN_WIDTH);
    GAMEPLAY_H = int(0.75 * SCREEN_HEIGHT);
    DESCRIPTION_H = SCREEN_HEIGHT - GAMEPLAY_H;
    STATUS_W = SCREEN_WIDTH - GAMEPLAY_W;
}

void FullScreenMode()
{
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void WindowedMode()
{
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, 0);
}
void GetWindowSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    SCREEN_WIDTH = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SCREEN_HEIGHT = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
WORD DefineColor(int t_color, int t_background)
{
    return ((t_background & 0x0F) << 4) + (t_color & 0x0F);
}
void SetTextColor(WORD wColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void GotoXY(int x, int y) {
    COORD coord = { (short)x, (short)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
bool GetXY(int& x, int& y) {
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hStd, &screenBufferInfo)) {
        cout << "GetConsoleScreenBufferInfo (" << GetLastError() << ")\n";
        return false;
    }
    x = screenBufferInfo.dwCursorPosition.X;
    y = screenBufferInfo.dwCursorPosition.Y;
    return true;
}
bool GetColor(int& color) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info)) {
        cout << "GetConsoleScreenBufferInfo (" << GetLastError() << ")\n";
        return false;
    }
    color = info.wAttributes;
    return true;
}

int generateRand(int from, int to)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(from, to);

    return dis(gen);
}
int midWidth(int width, string message)
{
    return (int)(width - message.size()) / 2;
}
int midWidth(int width, int content_width)
{
    return (width - content_width) / 2;
}
int midHeight(int height, int content_height)
{
    return (height - content_height) / 2;
}

void printString(string message, int X, int Y, int text_color, int bg_color)
{
    Status SavedStatus;
    SetTextColor(DefineColor(text_color, bg_color));

    GotoXY(X, Y);
    cout << message;
}

void printStringCenter(string message, int text_color, int bg_color)
{
    printString(message, midWidth(SCREEN_WIDTH, message), midHeight(SCREEN_HEIGHT, 1));
}

void printStringCenterGameplay(string message, int text_color, int bg_color)
{
    printString(message, midWidth(GAMEPLAY_W, message), midHeight(GAMEPLAY_H, 1));
}

void removeString(string message, int X, int Y)
{
    printString(string(message.size(), ' '), X, Y);
}

void removeStringCenter(string message)
{
    removeString(message, midWidth(GAMEPLAY_W, message), midHeight(GAMEPLAY_H, 1));
}


void printOnDescriptionAndWait(string prompt, int X, int Y, int text_color, int bg_color)
{
    printString(prompt, X, Y, text_color, bg_color);

    waitForKeyBoard();
    printString(string(prompt.size(), ' '), X, Y);
}

void printOnDescriptionCenterAndWait(string prompt, int text_color, int bg_color)
{
    printOnDescriptionAndWait(prompt, midWidth(GAMEPLAY_W, prompt.size()), GAMEPLAY_H + midHeight(DESCRIPTION_H, 1), text_color, bg_color);
}

void printOnGameplayAndWait(string prompt, int X, int Y, int text_color, int bg_color)
{
    printString(prompt, X, Y, text_color, bg_color);

    waitForKeyBoard();
    printString(string(prompt.size(), ' '), X, Y);
}

void printOnGameplayCenterAndWait(string prompt, int text_color, int bg_color)
{
    printOnGameplayAndWait(prompt, midWidth(GAMEPLAY_W, prompt.size()), midHeight(GAMEPLAY_H, 1), text_color, bg_color);
}

void waitForKeyBoard(int X, int Y)
{
    GotoXY(X, Y);
    system("pause");

    removeString("Press any key to continue . . .", X, Y);
}

string waitForInput(string prompt, int X, int Y, int text_color, int bg_color)
{
    Status SavedStatus;
    SetTextColor(DefineColor(text_color, bg_color));

    GotoXY(X, Y);
    cout << prompt;

    string input;
    getline(cin, input);

    return input;
}

/// Status class defnitions
Status::Status()
{
    GetXY(X, Y);
    GetColor(COLOR);
}

Status::~Status()
{
    ResetToCurrent();
}

int Status::getX()
{
    return X;
}

int Status::getY()
{
    return Y;
}

int Status::getColor()
{
    return COLOR;
}

void Status::ResetToCurrent()
{
    GotoXY(X, Y);
    SetTextColor(COLOR);
}