#include "GameHandler.h"

string STATUS_VAR[] = {
    "Time: ",
    "Level: ",
    "Scores: "
};
int STATUS_VAR_SIZE = sizeof(STATUS_VAR) / sizeof(string);

string GUIDEBUTTONS[] =
{
    "<P> - Pause/Continue", 
    "<R> - Reset Game",
    "<M> - Save Game",
    "<L> - Load Game",
    "<Esc> - Return to Main Menu"

};
int GUIDEBUTTONS_SIZE = sizeof(GUIDEBUTTONS) / sizeof(string);

GameHandler::GameHandler()
{
    StartUp();

    init();
}

GameHandler::~GameHandler()
{
    deleteData();
}

void GameHandler::StartUp()
{
    srand(time(NULL));
    //FullScreenMode();
    setRasterFonts();
    SetWindowSize(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL);
    FixConsoleWindow();
    HideCursor();
    SetUpParameters();
}

void GameHandler::init()
{

}

void GameHandler::resetData()
{
    //removeArts();

    deleteData();

    player = new Player;
    curRoom = new EmptyRoom;

    //level = 0;
    //score = 0;

    START_TIME = clock() / CLOCKS_PER_SEC;
    TIME = 0;
    PAUSE_TIME = 0;

    //UnDeadCMD = false;

    //vans.clear();
    //cars.clear();
    //birds.clear();
    //aliens.clear();
}

void GameHandler::deleteData()
{
    delete curRoom;
    delete player;
}

void GameHandler::resetGame()
{
    resetData();

    init();
}

void GameHandler::startGame()
{
    player->setPlayer();

    do
    {
        drawGame();

        curRoom->Render();
        curRoom->processRoom(player);

    } while (curRoom->getRoomId() == 2);
}

void GameHandler::drawGame()
{
    drawStatus();
    drawGUI();
}

void GameHandler::drawStatus()
{
    BOX StatusBox(GAMEPLAY_W, 0, STATUS_W, SCREEN_HEIGHT, LIGHTMAGENTA);
    StatusBox.printBox();

    for (int i = 0; i < STATUS_VAR_SIZE; i++)
    {
        GotoXY(GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + i * 2);
        cout << STATUS_VAR[i];
    }

    for (int i = 0; i < GUIDEBUTTONS_SIZE; i++)
    {
        GotoXY(GAMEPLAY_W + midWidth(STATUS_W, GUIDEBUTTONS[GUIDEBUTTONS_SIZE - 1]), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 2 + i * 2);
        cout << GUIDEBUTTONS[i];
    }
}

void GameHandler::drawGUI()
{
    BOX side[2];

    side[0].setBox(0, 0, GAMEPLAY_W, GAMEPLAY_H, GREEN, BLACK, "GAMEPLAY");
    side[0].printBox();

    side[1].setBox(0, GAMEPLAY_H, GAMEPLAY_W, DESCRIPTION_H, GREEN, BLACK, "DESCRIPTION");
    side[1].printBox();
}

void GameHandler::GenerateNewRooms() {
    roomsExplored += 1;

    printMessCenter("Generating new room... ");

    cout << player->getName() << " The Monk has explored " << roomsExplored << " room(s) in the dungeon.\n";

    /*
       Set the chance of finding a treasure gradually higher, and the chance of finding an empty room to heal lower.
       This behaviour should encourage an end-game. Whether it be defeat due to a lower chance of healing, or win if
       the treasure room is found. This prevents the game from running for too long.
    */
    if (roomsExplored > 10) {
        TREASURE_ROOM_CHANCE = TREASURE_ROOM_CHANCE + 35;
        EMPTY_ROOM_CHANCE = EMPTY_ROOM_CHANCE - 14;
        MONSTER_ROOM_CHANCE = 47;
        cout << "The Player has explored more than 10 rooms - increasing the chance of treasure rooms.";
    }
    else if (roomsExplored > 5) {
        TREASURE_ROOM_CHANCE = 15;
        MONSTER_ROOM_CHANCE = 55;
        cout << "The Player has explored more than 5 rooms - increasing the chance of treasure rooms slightly";
    }

    cout << "Generating new room....";
    
    int roomChance = generateRand(1, 100);
    Room* leftRoom, * rightRoom;

    if (roomChance < TREASURE_ROOM_CHANCE)
        leftRoom = new TreasureRoom;
    else if (roomChance < PUZZLE_ROOM_CHANCE)
        leftRoom = new PuzzleRoom;
    else if (roomChance < EMPTY_ROOM_CHANCE)
        leftRoom = new EmptyRoom;
    else
        leftRoom = new MonsterRoom;

    roomChance = generateRand(1, 100);
    if (roomChance < TREASURE_ROOM_CHANCE)
        rightRoom = new TreasureRoom;
    else if (roomChance < PUZZLE_ROOM_CHANCE)
        rightRoom = new PuzzleRoom;
    else if (roomChance < EMPTY_ROOM_CHANCE)
        rightRoom = new EmptyRoom;
    else
        rightRoom = new MonsterRoom;

    curRoom->setLeftRoom(leftRoom);
    curRoom->setRightRoom(rightRoom);
}

void GameHandler::MoveRoom() {
    GenerateNewRooms();

    int input = -1;

    cout << "Which way does " << player->getName() << " go?\n [0] = Left \n [1] = Right \n";
    while (true) {
        if (_kbhit()) {
            input = toupper(_getch());

            if (input == '0' || input == '1')
                break;
            else
                cout << "The Monk realises this isn't a direction..." << endl;
        }
    }

    cout << "Go to next room";

    curRoom = (input == '0') ? curRoom->getLeftRoom() : curRoom->getRightRoom();

    switch (curRoom->getRoomId()) {
    case (0):
        curRoom->Render();
        ExploreEmptyRoom();
        break;
    case (1): 
        curRoom->Render();
        BeginCombat();
        break;
    case (2): 
        curRoom->Render(player->getName());
        break;
    case (3): 
        curRoom->Render(player->getName());
        BeginPuzzle();
        break;
    }
}

/**
 * Generate a random room ID.
 * 0 = Empty Room
 * 1 = Monster Room
 * 2 = Treasure Room
 * 3 = Puzzle Room
 *
 * @return The room ID which was generated here.
 */

void GameHandler::BeginCombat() {
    int turn = 0;

    MonsterRoom* room = (MonsterRoom*)curRoom;
    Monster* monster = room->getMonster();

    while (room->isMonsterAlive()) {
        printf("The monster's health is currently: [%d / %d]\n", monster->getHealth(), monster->getBaseHealth());
        printf("The Monk's Health is currently: [%d / %d]\n", player->getHealth(), PLAYER_BASE_HEALTH);
        string log = "The Monk's health is currently: ";
        log += to_string(player->getHealth());

        cout << log;
        log = "The Monster's health is currently: ";
        log += to_string(monster->getHealth());

        cout << log;
        if (turn == 0) {
            string instruction = "2";

            while (instruction != "0" && instruction != "1") {
                cout << "What will the all-powerful Monk do? \n [0] = Attack \n [1] = Defend\n";
                cin >> instruction;
                if (instruction != "0" && instruction != "1") {
                    cout << "The Monk didn't understand this instruction!" << endl;
                }
            }

            if (instruction == "0") {
                CombatTryAttack(monster, turn);
            }
            else {
                CombatTryDefend(monster, turn);
            }

            turn = 1; // Set the turn to the monster.
        }
        else {

            if (monster->actionToPerform() == 0) {
                CombatTryAttack(monster, turn);
            }
            else {
                CombatTryDefend(monster, turn);
            }
            if (monster->tryAction()) { // Tries to attack or defend

            }
            turn = 0; // Set the turn back to the player.
        }
    }

    // The Monster has been defeated, allow the player to move on.
    cout << "The " << monster->getName() << " was defeated by " << player->getName() << " The Monk! \n The Monk moves on to the next room..." << endl;
    cout << "DEFEAT: Monster was defeated by player";

    MoveRoom();
}

void GameHandler::ExploreEmptyRoom() {
    // Initialise the "input" to contains user's input
    int input = -1;

    // Keep asking the player for the correct instruction. Break out of the loop when it's a 0 or 1.
    cout << "\n What would you like to do? \n [0] = pray \n [1] = move on" << endl;
    while (true) {
        if (_kbhit()) {
            input = toupper(_getch());

            if (input == '0' || input == '1')
                break;
            else
                cout << "Input unrecognised :( " << endl;
        }
    }

    if (input == '0') {
        player->setHealth(PLAYER_BASE_HEALTH);
        cout << "Player prayed in empty room: restoring health";
        printf("Naturally, you sit inside the demonic-looking summoning circle. You're now full health! [%d / %d] \n",
            player->getHealth(), PLAYER_BASE_HEALTH);
    }

    // Cast the current room to an EmptyRoom object.
    EmptyRoom* room = (EmptyRoom*)curRoom;

    if (room->Item()) {
        cout << "As " << player->getName() << " walks forward, they see a glisten in front of them." << endl;
        cout << "Generated item inside current room";
        cout << " What do you do? \n [0] = Pick Up \n [1] = Ignore" << endl;

        input = -1;
        while (true) {
            if (_kbhit()) {
                input = toupper(_getch());

                if (input == '0' || input == '1')
                    break;
                else
                    cout << "The Monk didn't understand that!" << endl;
            }
        }

        if (input == '0') {
            if (generateRand(1, 100) < 21) {
                cout << "ITEM: Staff of Protection";
                cout << "You approach the item and pick it up... It's a Staff of Protection! \n During your next combat, the Staff of Protection will block the first attack." << endl;
                player->setHasProtection(true);
            }
            else {
                cout << "ITEM: sewing needle; subtracting player health";
                cout << "You approach the item and pick it up... OUCH! It was a sewing needle! \n You lose 1 HP. :( " << endl;
                player->takeDamage(1);
            }
        }
    }

    cout << player->getName() << " the Monk moves on to the next room..." << endl;
    MoveRoom();
}

void GameHandler::CombatTryAttack(Monster* monster, int turn) {
    if (turn == 0) {
        if (player->tryAction()) {
            cout << player->getName() << " the Monk attacks the " << monster->getName() << "!" << endl;
            cout << "ATTACK: The monk successfully attacked the monster";
            monster->takeDamage(player->getDamage());
        }
        else {
            cout << "The " << monster->getName() << " dodged " << player->getName() << "'s attack!" << endl;
            cout << "ATTACK FAILED: The monk failed to attack the monster";
        }
    }
    else {
        if (monster->tryAction()) {
            if (player->hasProtection()) {
                cout << "\n The " << monster->getName() << " tried to attack, but the Staff of Protection blocked the attack from the " << monster->getName() << "!" << endl;
                cout << "ATTACK BLOCKED: Player had Staff of Protection item";
                player->setHasProtection(false);
            }
            else {
                cout << "\nThe " << monster->getName() << " strikes " << player->getName() << " the Monk! OUCH!" << endl;
                cout << "ATTACK: The monster attacked the player - the player had no Protection items";
                player->takeDamage(monster->getDamage());
            }
        }
        else {
            cout << "\nThe " << monster->getName() << " failed to attack " << player->getName() << " the Monk!" << endl;
            cout << "ATTACK FAILED: Monster failed to attack player!";
        }
    }
}

void GameHandler::CombatTryDefend(Monster* monster, int turn) {
    if (turn == 0) {
        if (player->tryAction()) {
            cout << endl;
            cout << player->getName() << " the Monk defends themselves against the monster, restoring 1 HP." << endl;
            cout << "DEFEND: The Monk successfully defended, gaining 1 HP.";
            // If the player does not have max health, increase it by 1. Otherwise, move on.
            if (player->getHealth() != PLAYER_BASE_HEALTH)
                player->setHealth(player->getHealth() + 1);
            else cout << "DEFEND: Failed to increase health: Health was already max!";
        }
        else {
            cout << endl;
            cout << player->getName() << " the Monk failed to defend against the " << monster->getName() << endl;
            cout << "The " << monster->getName() << " dealt ";
            printf("%d damage!\n", monster->getDamage());
            cout << "DEFEND FAILED: The Monk failed to defend against the monster - taking health away";
            player->takeDamage(monster->getDamage());
        }
    }
    else {
        if (monster->tryAction()) {
            if (monster->getHealth() != monster->getBaseHealth()) {
                monster->setHealth(monster->getHealth() + 1);
                cout << "\nThe " << monster->getName() << " defended against " << player->getName() << " the Monk and gained +1 health." << endl;
                cout << "DEFEND: Monster defended against player";
            }
            else {
                cout << "\nThe " << monster->getName() << " defended itself, but was already full health." << endl;
                cout << "DEFEND: Monster defended against the player [Full health]";
            }
        }
        else {
            monster->takeDamage(player->getDamage());
            cout << "\nThe " << monster->getName() << " failed to defend itself, and " << player->getName() << " exploited this!" << endl;
            cout << "DEFEND FAILED: Monster failed to defend itself";
        }
    }
}

void GameHandler::BeginPuzzle() {
    cout << "There seems to be spikes in the floor. If the answer is incorrect, face a painful punishment. If the answer is correct, accept a generous reward." << endl;
    PuzzleRoom* room = (PuzzleRoom*)curRoom;

    string instruction = "_";

    while (instruction != "0" && instruction != "1") {
        cout << "Does " << player->getName() << " the Monk accept the challenge? \n [0] = Yes \n [1] = No" << endl;
        cin >> instruction;
        if (instruction != "0" && instruction != "1") cout << player->getName() << " realised this wasn't an option!";
    }

    if (instruction == "0") {
        cout << "The player chose to answer the question. The question was: ";
        cout << room->getPuzzle();
        cout << "The Egyptian writing reads: \n" << endl;
        cout << room->getPuzzle() << endl;

        cout << "The answer is: ";
        cout << room->getPuzzleAnswer();
        string answer;
        cin >> answer;

        if (answer == room->getPuzzleAnswer()) {
            cout << "The walls begin to change. The symbols fade away. " << player->getName() << " answered correctly!" << endl;
            cout << "As the symbols fade, a hole in the wall reveals a Staff of Protection. " << player->getName() << " picks it up!" << endl;
            cout << "During the next battle, the first attack from a monster will be blocked!" << endl;

            cout << "The answer was correct";
            player->setHasProtection(true);
        }
        else {
            player->takeDamage(5);
            cout << "The walls begin to change. The symbols fade away. The floor begins to shake. " << player->getName() << " answered incorrectly!" << endl;
            printf("The Monk loses 5 HP for their mistake. [%d / %d] \n", player->getHealth(), PLAYER_BASE_HEALTH);
            cout << "Player answered incorrectly - subtracting 5 HP from the player";
        }
    }

    cout << player->getName() << " moves on to the next room..." << endl;

    MoveRoom();
}

void GameHandler::Main_Menu()
{
    int box_width = 20;
    int box_height = 3;
    MENU MainMenu("MAIN MENU", MAINMENU, MAINMENU_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 3 / 2, box_height * MAINMENU_SIZE), box_width, box_height, WHITE, BLACK);
    int buf = 0;

    while (true)
    {
        system("cls");

        //Draw tiltle
        drawArt(title, title_height, midWidth(SCREEN_WIDTH, title_width), midHeight(SCREEN_HEIGHT / 2, title_height));

        MainMenu.printMenu();

        //Play menu theme
        mciSendString(TEXT("play Menu_Theme repeat"), NULL, 0, NULL);

        //Take input from player
        buf = MainMenu.inputMenu();

        switch (buf)
        {
        case 0: //Play
        {
            system("cls");
            printMessCenter("LOADING ...");

            resetGame();
            system("cls");

            mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
            mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

            startGame();

            break;
        }
        case 1: //Load Game
        {
            system("cls");

            //game.loadGame();
            system("cls");

            //if (!game.isPlaying())
            //	continue;

            mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
            mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

            //game.resumeThread();

            break;
        }
        case 2: //Leader Board
        {
            system("cls");

            //displayLeaderBoard();

            toupper(_getch());

            break;
        }
        case 3: //Instruction
        {
            system("cls");

            //drawInstruction();

            do {
                buf = toupper(_getch());
            } while (buf != ESC && buf != ENTER);

            break;
        }
        case 4://Settings
        {
            system("cls");

            Settings_Menu();

            MainMenu.setMenu("MAIN MENU", MAINMENU, MAINMENU_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 3 / 2, box_height * MAINMENU_SIZE), box_width, box_height, WHITE, BLACK);
            break;
        }
        case 5: //Credits
        {
            system("cls");

            //drawCredits();

            do {
                buf = toupper(_getch());
            } while (buf != ESC && buf != ENTER);

            break;
        }
        case 6: //Quit
        case -1:
        {
            system("cls");
            printMessCenter("GOOD BYE! :-)", rand() % 15 + 1, BLACK);
            Sleep(1000);

            //sub.detach();
            return;
        }
        }

    }
}

void GameHandler::Settings_Menu()
{
    int box_width = 21;
    int box_height = 5;
    MENU settingsMenu("SETTINGS", SETTINGS, SETTINGS_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * SETTINGS_SIZE), box_width, box_height, WHITE, BLACK);
    int buf = 0;

    while (true)
    {
        system("cls");
        settingsMenu.printMenu();
        int buf = settingsMenu.inputMenu();

        switch (buf)
        {
        case 0:
        {
            // MENU SETTINGS
            buf = WindowMode_Settings();
            if (buf == 0)
                FullScreenMode();
            else if (buf == 1)
            {
                WindowedMode();
                SetWindowSize(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL);
            }
            else
                break;

            FixConsoleWindow();
            HideCursor();
            SetUpParameters();
            settingsMenu.setMenu("SETTINGS", SETTINGS, SETTINGS_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * SETTINGS_SIZE), box_width, box_height, WHITE, BLACK);

            break;
        }
        case 1:
        {
            // AUDIO SETTINGS
            buf = Volumes_Settings();

            SetAllVolumes(buf);

            break;
        }
        case 2:
        case -1:
            return;
        }
    }
}

int GameHandler::WindowMode_Settings()
{
    string window_title = "WINDOW SETTINGS";
    BOX Title;
    Title.setBox(midWidth(SCREEN_WIDTH, window_title.size() + 10), SCREEN_HEIGHT / 20, window_title.size() + 10, 3, YELLOW, BLACK, window_title);

    int box_width = 21;
    int box_height = 5;
    string windowModes[] =
    {
        "FullScreen Mode",
        "Windowed Mode",
        "Cancel"
    };
    int size = sizeof(windowModes) / sizeof(string);

    MENU askWindow("Select Mode", windowModes, size, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * size), box_width, box_height, WHITE, BLACK);
    askWindow.setBoxFormat(0, box_width, box_height, LIGHTGREEN, BLACK);
    askWindow.setBoxFormat(1, box_width, box_height, LIGHTBLUE, BLACK);

    Title.printBox();
    askWindow.printMenu();

    return askWindow.inputMenu();
}

int GameHandler::Volumes_Settings()
{
    string audio_title = "AUDIO SETTINGS";
    string guide1 = "-----Volume Range: [1 - 1000]-----";
    string guide2 = "--Type [-1] to Cancel--";
    BOX Title[3];
    Title[0].setBox(midWidth(SCREEN_WIDTH, audio_title.size() + 10), SCREEN_HEIGHT / 20, audio_title.size() + 10, 3, YELLOW, BLACK, audio_title);
    Title[1].setBox(midWidth(SCREEN_WIDTH, guide1.size()), SCREEN_HEIGHT * 4 / 20, guide1.size(), 3, LIGHTCYAN, BLACK, guide1);
    Title[2].setBox(midWidth(SCREEN_WIDTH, guide2.size()), SCREEN_HEIGHT * 6 / 20, guide2.size(), 3, LIGHTCYAN, BLACK, guide2);

    int volume = 0;

    string input;
    while (true) {
        system("cls");

        Title[0].printBox();
        Title[1].printContent();
        Title[2].printContent();

        GotoXY(midWidth(SCREEN_WIDTH, "Enter Volume Number: "), midHeight(SCREEN_HEIGHT, 1));
        cout << "Enter Volume Number: ";

        getline(cin, input);
        char* flag = NULL;
        volume = strtol(input.c_str(), &flag, 10);

        if (*flag != NULL)
        {
            system("cls");
            printMessCenter("Wrong format! Please type in a number", WHITE, RED);
            waitForKeyBoard();
        }
        else
            break;
    }


    return volume;
}