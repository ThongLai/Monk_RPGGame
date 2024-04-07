#pragma once

#include "Room.h"

class PuzzleRoom : public Room {
private:
    int puzzleId;

    vector <string> riddles;
    vector <string> answers;
public:
    PuzzleRoom();

    int getPuzzleSize();
    string getPuzzle();
    string getPuzzleAnswer();

    void setRiddles();
    void setAnswers();
    void setPuzzleId(int puzzleId);

    void Render(string = "");
    void processRoom(Player* player);
};