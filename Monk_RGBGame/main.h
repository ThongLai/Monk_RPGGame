#pragma once

#include "GameHandler.h"

class MainView {
public:
    void startGame(string playerName, string description);

private:
    GameHandler* gameController;
};