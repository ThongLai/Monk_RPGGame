#include "TreasureRoom.h"

TreasureRoom::TreasureRoom() : Room("Treasure Room") {  
    description = "In the treasure room, the monk is surrounded by dazzling wealth and priceless artifacts, offering boundless opportunities for fortune and abundance.";
}

void TreasureRoom::Generate(int) {
    isTreasureCollected = false;
}

void TreasureRoom::Render(string playerName) {
    string instruction = "1";
    cout << "You enter a dark room. As you walk forward, you can smell a strange scent coming from in front of you. \n "
            "Your stomach rumbles. Your inside, ready. This is it. It's the Treasure Room!\n \n Right in front of you, "
            "is a Domino's Meateor pizza." << endl;

    cout << "      ____...------------...____\n"
            "               _.-\"` /o/__ ____ __ __  __ \\o\\_`\"-._\n"
            "             .'     / /                    \\ \\     '.\n"
            "             |=====/o/======================\\o\\=====|\n"
            "             |____/_/________..____..________\\_\\____|\n"
            "             /   _/ \\_     <_o#\\__/#o_>     _/ \\_   \\\n"
            "             \\_________\\####/_________/\n"
            "              |===\\!/========================\\!/===|\n"
            "              |   |=|          .---.         |=|   |\n"
            "              |===|o|=========/     \\========|o|===|\n"
            "              |   | |         \\() ()/        | |   |\n"
            "              |===|o|======{'-.) A (.-'}=====|o|===|\n"
            "              | __/ \\__     '-.\\uuu/.-'    __/ \\__ |\n"
            "              |==== .'.'^'.'.====|\n"
            "              |  _\\o/   __  {.' __  '.} _   _\\o/  _|\n"
            "              `\"\"\"\"-\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"-\"\"\"\"`\n";

    while(instruction != "0") {
        cout << " What will you do? \n [0] = Collect Treasure" << endl;
        cin >> instruction;
        if(instruction != "0") cout << "Why would you want to do anything else when there's yummy treasure in front of you?! " << endl;
    }

    TreasureCollected(playerName);
}

void TreasureRoom::TreasureCollected(string playerName) {
    cout << playerName << " The Monk collected the treasure, and makes their way out of the dungeon!" << endl;
    system("pause");
    exit(0);
}