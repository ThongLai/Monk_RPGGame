#include "PuzzleRoom.h"

PuzzleRoom::PuzzleRoom() : Room("Puzzle Room") {
    description = "In the puzzle room, the monk faces mind-bending challenges, testing their intellect and determination.";
}

void PuzzleRoom::Generate(int) {
    puzzleCompleted = false;
    SetRiddles();
    SetAnswers();
}

void PuzzleRoom::Render(string) {
    cout << description << endl;
}

int PuzzleRoom::getPuzzleSize() {
    return riddles.size();
}

string PuzzleRoom::getPuzzle() {
    return riddles[puzzleId];
}

string PuzzleRoom::getPuzzleAnswer() {
    return answers[puzzleId];
}

void PuzzleRoom::SetRiddles() {
    riddles.push_back("What has a head, a tail, is brown, and has no legs?");
    riddles.push_back("What comes once in a minute, twice in a moment, but never in a thousand years?");
    riddles.push_back("David's father has three sons : Snap, Crackle and _____ ?");
    riddles.push_back("Poor people have it. Rich people need it. If you eat it you die. what is it?");
    riddles.push_back( "If you have me, you want to share me. If you share me, you haven't got me. \n What am I?");
    riddles.push_back( "You use a knife to slice my head and weep beside me when I am dead. \n What am I?");
}

void PuzzleRoom::SetAnswers() {
    answers.push_back("penny");
    answers.push_back("m");
    answers.push_back("david");
    answers.push_back("nothing");
    answers.push_back( "secret");
    answers.push_back("onion");
}

void PuzzleRoom::setPuzzleId(int puzzleId) {
    this->puzzleId = puzzleId;
}
