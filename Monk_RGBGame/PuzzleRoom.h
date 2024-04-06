#pragma once

#include "Room.h"

class PuzzleRoom : public Room {
private:
    int puzzleId;

    vector <string> riddles;
    vector <string> answers;
public:
    PuzzleRoom();
    
    void Render(string = "");

    int getPuzzleSize();

    string getPuzzle();

    string getPuzzleAnswer();

    void SetRiddles();

    void SetAnswers();

    void setPuzzleId(int puzzleId);
};