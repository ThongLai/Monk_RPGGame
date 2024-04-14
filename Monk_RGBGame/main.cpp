#include "GameHandler.h"

GameHandler gameHandler;


int main() {
    printStringCenter("LOADING ...");
    
    //Load and open files
    //LoadPlayerSaves();
    //LoadLeaderBoard();
    //OpenSoundFiles();

    gameHandler.Main_Menu();

    return 0;
}