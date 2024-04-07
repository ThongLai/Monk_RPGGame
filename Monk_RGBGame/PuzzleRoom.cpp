#include "PuzzleRoom.h"

PuzzleRoom::PuzzleRoom() : Room("Puzzle Room") {
    description = "In the puzzle room, the monk faces mind-bending challenges, testing their intellect and determination.";
    puzzleId = generateRand(0, (riddles.size() - 1));
    setRiddles();
    setAnswers();
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

void PuzzleRoom::setRiddles() {
    riddles.push_back("What has a head, a tail, is brown, and has no legs?");
    riddles.push_back("What comes once in a minute, twice in a moment, but never in a thousand years?");
    riddles.push_back("David's father has three sons : Snap, Crackle and _____ ?");
    riddles.push_back("Poor people have it. Rich people need it. If you eat it you die. what is it?");
    riddles.push_back( "If you have me, you want to share me. If you share me, you haven't got me. \n What am I?");
    riddles.push_back( "You use a knife to slice my head and weep beside me when I am dead. \n What am I?");
}

void PuzzleRoom::setAnswers() {
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

void PuzzleRoom::processRoom(Player* player) {
    cout << "There seems to be spikes in the floor. If the answer is incorrect, face a painful punishment. If the answer is correct, accept a generous reward." << endl;

    string instruction = "_";

    while (instruction != "0" && instruction != "1") {
        cout << "Does " << player->getName() << " the Monk accept the challenge? \n [0] = Yes \n [1] = No" << endl;
        cin >> instruction;
        if (instruction != "0" && instruction != "1") cout << player->getName() << " realised this wasn't an option!";
    }

    if (instruction == "0") {
        cout << "The Egyptian writing reads: \n" << endl;
        cout << getPuzzle() << endl;

        string answer;
        cin >> answer;

        if (answer == getPuzzleAnswer()) {
            cout << "The walls begin to change. The symbols fade away. " << player->getName() << " answered correctly!" << endl;
            cout << "As the symbols fade, a hole in the wall reveals a Staff of Protection. " << player->getName() << " picks it up!" << endl;
            cout << "During the next battle, the first attack from a monster will be blocked!" << endl;

            player->setHasProtection(true);
        }
        else {
            player->takeDamage(5);
            cout << "The walls begin to change. The symbols fade away. The floor begins to shake. " << player->getName() << " answered incorrectly!" << endl;
            printf("The Monk loses 5 HP for their mistake. [%d / %d] \n", player->getHealth(), PLAYER_BASE_HEALTH);
        }
    }

    cout << player->getName() << " moves on to the next room..." << endl;
}