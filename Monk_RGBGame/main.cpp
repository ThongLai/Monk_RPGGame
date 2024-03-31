#include "GameHandler.h"

GameHandler gameHandler;

int main() {
    printMessCenter("LOADING ...");
    
    //Load and open files
    //LoadPlayerSaves();
    //LoadLeaderBoard();
    //OpenSoundFiles();

    gameHandler.Main_Menu();

    string name, description;

    std::cout << "You're in a fractured reality. And a dungeon, don't forget that. Once you advance through a door, there's no going back. Good luck... \n \n Now that's over, what's your name?\n";
    std::getline(std::cin, name);

    std::cout << "The powerful Monk has established his name; " << name << " \n But what's his story? \n";
    std::getline(std::cin, description);

    gameHandler.setPlayer(name, description);

    return 0;
}