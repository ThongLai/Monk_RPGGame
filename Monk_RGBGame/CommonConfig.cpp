#include "CommonConfig.h"

int SCREEN_WIDTH_PXL = 1633;
int SCREEN_HEIGHT_PXL = 900;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

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
void printMessCenter(string message)
{
    Status SavedStatus;

    GotoXY(midWidth(SCREEN_WIDTH, message), midHeight(SCREEN_HEIGHT, 1));
    cout << message;
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