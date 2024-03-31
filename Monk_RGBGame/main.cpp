<<<<<<< HEAD
#include "GameHandler.h"
=======
#include "main.h"
>>>>>>> origin/main

GameHandler gameHandler;

int main() {
    printMessCenter("LOADING ...");

<<<<<<< HEAD
    //Load and open files
    //LoadPlayerSaves();
    //LoadLeaderBoard();
    //OpenSoundFiles();

    gameHandler.Main_Menu();

    string name, description;
=======
    string name, description;
    std::cout << " ______  __ __    ___      ___ ___   ___   ____   __  _       ____   ____  ___ ___    ___ \n"
                 "|      T|  T  T  /  _]    |   T   T /   \\ |    \\ |  l/ ]     /    T /    T|   T   T  /  _]\n"
                 "|      ||  l  | /  [_     | _   _ |Y     Y|  _  Y|  ' /     Y   __jY  o  || _   _ | /  [_ \n"
                 "l_j  l_j|  _  |Y    _]    |  \\_/  ||  O  ||  |  ||    \\     |  T  ||     ||  \\_/  |Y    _]\n"
                 "  |  |  |  |  ||   [_     |   |   ||     ||  |  ||     Y    |  l_ ||  _  ||   |   ||   [_ \n"
                 "  |  |  |  |  ||     T    |   |   |l     !|  |  ||  .  |    |     ||  |  ||   |   ||     T\n"
                 "  l__j  l__j__jl_____j    l___j___j \\___/ l__j__jl__j\\_j    l___,_jl__j__jl___j___jl_____j\n"
                 " ========================================================================================= \n" << endl;
>>>>>>> origin/main

    std::cout << "You're in a fractured reality. And a dungeon, don't forget that. Once you advance through a door, there's no going back. Good luck... \n \n Now that's over, what's your name?\n";
    std::getline(std::cin, name);

    std::cout << "The powerful Monk has established his name; " << name << " \n But what's his story? \n";
    std::getline(std::cin, description);

<<<<<<< HEAD
    gameHandler.setPlayer(name, description);

    return 0;
=======
    auto * mainDungeon = new MainView();

    mainDungeon->startGame(name, description);
    return 0;
}

void MainView::startGame(string playerName, string description) {
    this->gameController = new GameHandler(playerName, description);
>>>>>>> origin/main
}