//
// Created by Mike on 21/03/2019.
//

#ifndef MONKASSIGNMENT_PUZZLEROOM_H
#define MONKASSIGNMENT_PUZZLEROOM_H


#include "Room.h"

class PuzzleRoom : public Room {
public:
    PuzzleRoom(Room *);

    void Generate() override;

    void Render(string) override;

    bool puzzleCompleted;

    int getPuzzleSize();

    string getPuzzle();

    string getPuzzleAnswer();

    void SetRiddles();

    void SetAnswers();

    void setPuzzleId(int puzzleId);

private:
    int puzzleId;
};


#endif //MONKASSIGNMENT_PUZZLEROOM_H
