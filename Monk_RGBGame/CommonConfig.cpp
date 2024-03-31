#include "CommonConfig.h"

int SCREEN_WIDTH_PXL = 1633;
int SCREEN_HEIGHT_PXL = 900;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int GAMEPLAY_W;
int STATUS_W;
int SAVE_SIZE;
int LEADERBOARD_SIZE;

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
    GAMEPLAY_W = 0.75 * SCREEN_WIDTH;
    STATUS_W = SCREEN_WIDTH - GAMEPLAY_W;
    LEADERBOARD_SIZE = SCREEN_HEIGHT * 0.8 / 3 - 1;
    SAVE_SIZE = SCREEN_HEIGHT * 0.8 / 5 - 3;
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
void printMessCenter(string message, int text_color, int bg_color)
{
    Status SavedStatus;
    SetTextColor(DefineColor(text_color, bg_color));

    GotoXY(midWidth(SCREEN_WIDTH, message), midHeight(SCREEN_HEIGHT, 1));
    cout << message;
}

//Sounds and Musics
void SetAllVolumes(int volume)
{
    mciSendStringA(string("setaudio Menu_Theme volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Gameplay_Theme volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Van_Crash volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Car_Crash volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Alien_Crash volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Bird_Crash volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Menu_Select volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Plus_Point volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Next_Level volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
    mciSendStringA(string("setaudio Finish_Game volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
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