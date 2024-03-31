#include "GameHandler.h"

<<<<<<< HEAD
GameHandler::GameHandler()
{
    StartUp();

    init();
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

    logs = new Logs();

    logs->clearLogs();
}

void GameHandler::resetData()
{
    randomController = new RandomController();
=======
GameHandler::GameHandler(string playerName, string description) {
    playerController = new PlayerController(3, playerName, description);
    logController = new LogController();
    randomController = new RandomController;

    logController->clearLogs();
    logController->log("Monk created with name: " + playerName + " with a base health of 15, and a damage of 3.");
    logController->log("Monk's description: " + description);

>>>>>>> origin/main
    EmptyRoom* spawnRoom = new EmptyRoom(nullptr);
    spawnRoom->Generate(randomController->getRandomIndex(1, 100));
    spawnRoom->Render();
    currentRoom = spawnRoom;
<<<<<<< HEAD
    logs->printLogs("Generated Empty spawn room.");
    ExploreEmptyRoom();

    //removeArts();

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

    logs->clearLogs();
}

void GameHandler::resetGame()
{
    resetData();

    init();
}

void GameHandler::setPlayer(string playerName, string description)
{
    playerController = new PlayerController(3, playerName, description);
    //logController->log("Monk created with name: " + playerName + " with a base health of 15, and a damage of 3.");
    //logController->log("Monk's description: " + description);
=======
    logController->log("Generated Empty spawn room.");
    ExploreEmptyRoom();
>>>>>>> origin/main
}

void GameHandler::GenerateRoom(Room *sender, string direction) {
    roomsExplored += 1;

    string log = "Generating new room... #";
    log += to_string(roomsExplored);
<<<<<<< HEAD
    logs->printLogs(log);
=======
    logController->log(log);
>>>>>>> origin/main

    cout << playerController->getPlayerName() << " The Monk has explored ";
    printf("%d room(s) in the dungeon. \n", roomsExplored);
    /*
       Set the chance of finding a treasure gradually higher, and the chance of finding an empty room to heal lower.
       This behaviour should encourage an end-game. Whether it be defeat due to a lower chance of healing, or win if
       the treasure room is found. This prevents the game from running for too long.
    */
    if(roomsExplored > 10) {
        treasureChance = 40;
        emptyChance = 13;
        monsterChance = 47;
<<<<<<< HEAD
        logs->printLogs("The Player has explored more than 10 rooms - increasing the chance of treasure rooms.");
=======
        logController->log("The Player has explored more than 10 rooms - increasing the chance of treasure rooms.");
>>>>>>> origin/main
    }
    else if(roomsExplored > 5) {
        treasureChance = 15;
        monsterChance = 55;
<<<<<<< HEAD
        logs->printLogs("The Player has explored more than 5 rooms - increasing the chance of treasure rooms slightly");
=======
        logController->log("The Player has explored more than 5 rooms - increasing the chance of treasure rooms slightly");
>>>>>>> origin/main
    }
    int roomId = rngRoomId();
    Room* newRoom;

<<<<<<< HEAD
    logs->printLogs("Generating new room....");
=======
    logController->log("Generating new room....");
>>>>>>> origin/main
    switch (roomId) {
        default:
        case (0):
            newRoom = new EmptyRoom(sender);
            newRoom->Generate(randomController->getRandomIndex(1, 100));
            newRoom->Render();

            if (direction == "0") currentRoom->setLeftRoom(newRoom);
            else currentRoom->setRightRoom(newRoom);

            currentRoom = newRoom;
<<<<<<< HEAD
            logs->printLogs("Generated new Empty room");
=======
            logController->log("Generated new Empty room");
>>>>>>> origin/main
            ExploreEmptyRoom();
            break;
        case (1): {
            newRoom = new MonsterRoom(sender);
            newRoom->Generate(randomController->getRandomIndex(0, 2));
            newRoom->Render();

            if (direction == "0") currentRoom->setLeftRoom(newRoom);
            else currentRoom->setRightRoom(newRoom);

            currentRoom = newRoom;
<<<<<<< HEAD
            logs->printLogs("Generated new Monster room");
=======
            logController->log("Generated new Monster room");
>>>>>>> origin/main
            BeginCombat();
            break;
        }
        case (2): {
            TreasureRoom *treasureRoom = new TreasureRoom(sender);
            treasureRoom->Generate();

            if (direction == "0") currentRoom->setLeftRoom(treasureRoom);
            else currentRoom->setRightRoom(treasureRoom);

            currentRoom = treasureRoom;
            treasureRoom->Render(playerController->getPlayerName());
<<<<<<< HEAD
            logs->printLogs("Generated Treasure room!");
=======
            logController->log("Generated Treasure room!");
>>>>>>> origin/main
            break;
        }
        case (3): {
            PuzzleRoom *puzzleRoom = new PuzzleRoom(sender);
            puzzleRoom->Generate();
            puzzleRoom->Render(playerController->getPlayerName());
            currentRoom = puzzleRoom;

<<<<<<< HEAD
            logs->printLogs("Generated Puzzle room!");
=======
            logController->log("Generated Puzzle room!");
>>>>>>> origin/main
            int puzzleId = randomController->getRandomIndex(0, (puzzleRoom->getPuzzleSize() - 1) );
            puzzleRoom->setPuzzleId(puzzleId);
            BeginPuzzle();
            break;
        }
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
int GameHandler::rngRoomId() {
<<<<<<< HEAD
    logs->printLogs("Choosing a random room ID from the percentage chances");
=======
    logController->log("Choosing a random room ID from the percentage chances");
>>>>>>> origin/main
    int roomChance = randomController->getRandomIndex(1,100);
    if(roomChance < treasureChance) {
        return 2;
    }
    else if (roomChance < puzzleChance) {
        return 3;
    }
    else if (roomChance < emptyChance) {
        return 0;
    }
    else {
        return 1;
    }
}

void GameHandler::BeginCombat() {
    int turn = 0;

    MonsterRoom* room = (MonsterRoom*) currentRoom;

    while(room->isMonsterAlive()) {
        printf("The monster's health is currently: [%d / %d]\n", room->getMonsterHealth(), room->getMonsterBaseHealth());
        printf("The Monk's Health is currently: [%d / %d]\n", playerController->getPlayerHealth(), playerController->getPlayerBaseHealth());
        string log = "The Monk's health is currently: ";
        log += to_string(playerController->getPlayerHealth());

<<<<<<< HEAD
        logs->printLogs(log);
        log = "The Monster's health is currently: ";
        log += to_string(room->getMonsterHealth());

        logs->printLogs(log);
=======
        logController->log(log);
        log = "The Monster's health is currently: ";
        log += to_string(room->getMonsterHealth());

        logController->log(log);
>>>>>>> origin/main
        if(turn == 0) {
            string instruction = "2";

            while(instruction != "0" && instruction != "1"){
                cout << "What will the all-powerful Monk do? \n [0] = Attack \n [1] = Defend\n";
                cin >> instruction;
                if(instruction != "0" && instruction != "1") {
                    cout << "The Monk didn't understand this instruction!" << endl;
                }
            }

            if(instruction == "0") {
                CombatTryAttack(room, turn);
            }
            else {
                CombatTryDefend(room, turn);
            }

            turn = 1; // Set the turn to the monster.
        }
        else {

            if(room->monsterActionToPerform() == 0) {
                CombatTryAttack(room, turn);
            }
            else {
                CombatTryDefend(room, turn);
            }
            if (room->monsterTryAction()) { // Tries to attack or defend

            }
            turn = 0; // Set the turn back to the player.
        }
    }

    // The Monster has been defeated, allow the player to move on.
    cout << "The " << room->getMonsterName() << " was defeated by " << playerController->getPlayerName() << " The Monk! \n The Monk moves on to the next room..." << endl;
<<<<<<< HEAD
    logs->printLogs("DEFEAT: Monster was defeated by player");
=======
    logController->log("DEFEAT: Monster was defeated by player");
>>>>>>> origin/main
    currentRoom->isRoomComplete = true;

    MoveRoom();
}

<<<<<<< HEAD
void GameHandler::BeginPuzzle() {
    cout << "There seems to be spikes in the floor. If the answer is incorrect, face a painful punishment. If the answer is correct, accept a generous reward." << endl;
    PuzzleRoom* room = (PuzzleRoom*)currentRoom;

    string instruction = "_";

    while (instruction != "0" && instruction != "1") {
        cout << "Does " << playerController->getPlayerName() << " the Monk accept the challenge? \n [0] = Yes \n [1] = No" << endl;
        cin >> instruction;
        if (instruction != "0" && instruction != "1") cout << playerController->getPlayerName() << " realised this wasn't an option!";
    }

    if (instruction == "0") {
        logs->printLogs("The player chose to answer the question. The question was: ");
        logs->printLogs(room->getPuzzle());
        cout << "The Egyptian writing reads: \n" << endl;
        cout << room->getPuzzle() << endl;

        logs->printLogs("The answer is: ");
        logs->printLogs(room->getPuzzleAnswer());
        string answer;
        cin >> answer;

        if (answer == room->getPuzzleAnswer()) {
            cout << "The walls begin to change. The symbols fade away. " << playerController->getPlayerName() << " answered correctly!" << endl;
            cout << "As the symbols fade, a hole in the wall reveals a Staff of Protection. " << playerController->getPlayerName() << " picks it up!" << endl;
            cout << "During the next battle, the first attack from a monster will be blocked!" << endl;

            logs->printLogs("The answer was correct");
            playerController->setPlayerProtection(true);
        }
        else {
            playerController->subtractPlayerHealth(5);
            cout << "The walls begin to change. The symbols fade away. The floor begins to shake. " << playerController->getPlayerName() << " answered incorrectly!" << endl;
            printf("The Monk loses 5 HP for their mistake. [%d / %d] \n", playerController->getPlayerHealth(), playerController->getPlayerBaseHealth());
            logs->printLogs("Player answered incorrectly - subtracting 5 HP from the player");
        }
    }

    cout << playerController->getPlayerName() << " moves on to the next room..." << endl;

    MoveRoom();
}

=======
>>>>>>> origin/main
void GameHandler::ExploreEmptyRoom() {
    // Initialise the instruction to something other than the supported options, to enter the while loop
    string instruction = "2";

    // Keep asking the player for the correct instruction. Break out of the loop when it's a 0 or 1.
    while(instruction != "0" && instruction != "1") {
        cout << "\n What would you like to do? \n [0] = pray \n [1] = move on" << endl;
        cin >> instruction;
        if(instruction != "0" && instruction != "1") { cout << "Input unrecognised :( " << endl; }
    }

    if(instruction == "0") {
        playerController->setPlayerHealth(playerController->getPlayerBaseHealth());
<<<<<<< HEAD
        logs->printLogs("Player prayed in empty room: restoring health");
=======
        logController->log("Player prayed in empty room: restoring health");
>>>>>>> origin/main
        printf("Naturally, you sit inside the demonic-looking summoning circle. You're now full health! [%d / %d] \n",
               playerController->getPlayerHealth(), playerController->getPlayerBaseHealth());
    }

    // Cast the current room to an EmptyRoom object.
    EmptyRoom* room = (EmptyRoom*) currentRoom;

    if(room->hasItem) {
        cout << "As " << playerController->getPlayerName() << " walks forward, they see a glisten in front of them." << endl;
<<<<<<< HEAD
        logs->printLogs("Generated item inside current room");
=======
        logController->log("Generated item inside current room");
>>>>>>> origin/main
        instruction = "2";
        while (instruction != "0" && instruction != "1") {
            cout << " What do you do? \n [0] = Pick Up \n [1] = Ignore" << endl;

            cin >> instruction;
            if(instruction != "0" && instruction != "1") cout << "The Monk didn't understand that!"<< endl;
        }

        if(instruction == "0") {
            if(randomController->getRandomIndex(1, 100) < 21) {
<<<<<<< HEAD
                logs->printLogs("ITEM: Staff of Protection");
=======
                logController->log("ITEM: Staff of Protection");
>>>>>>> origin/main
                cout << "You approach the item and pick it up... It's a Staff of Protection! \n During your next combat, the Staff of Protection will block the first attack." << endl;
                playerController->setPlayerProtection(true);
            }
            else {
<<<<<<< HEAD
                logs->printLogs("ITEM: sewing needle; subtracting player health");
=======
                logController->log("ITEM: sewing needle; subtracting player health");
>>>>>>> origin/main
                cout << "You approach the item and pick it up... OUCH! It was a sewing needle! \n You lose 1 HP. :( " << endl;
                playerController->subtractPlayerHealth(1);
            }
        }
    }

    cout <<  playerController->getPlayerName() << " the Monk moves on to the next room..." << endl;
    MoveRoom();
}

void GameHandler::MoveRoom() {
    string direction = "_";

    // which direction will the player go?
    while(direction != "0" && direction != "1") {
        cout << "Which way does " << playerController->getPlayerName() << " go?\n [0] = Left \n [1] = Right \n";
        cin >> direction;
        if(direction != "0" && direction != "1") {
            cout << "The Monk realises this isn't a direction..." << endl;
<<<<<<< HEAD
            logs->printLogs("Player did not provide a valid option - expected [0] || [1]");
=======
            logController->log("Player did not provide a valid option - expected [0] || [1]");
>>>>>>> origin/main
        }
    }
    GenerateRoom(currentRoom, direction);
}

void GameHandler::CombatTryAttack(MonsterRoom* room, int turn) {
    if(turn == 0) {
        if(playerController->tryAction()) {
            cout << playerController->getPlayerName() << " the Monk attacks the " << room->getMonsterName() << "!" << endl;
<<<<<<< HEAD
            logs->printLogs("ATTACK: The monk successfully attacked the monster");
=======
            logController->log("ATTACK: The monk successfully attacked the monster");
>>>>>>> origin/main
            room->subtractMonsterHealth(playerController->getPlayerDamage());
        }
        else {
            cout << "The " << room->getMonsterName() << " dodged " << playerController->getPlayerName() << "'s attack!" << endl;
<<<<<<< HEAD
            logs->printLogs("ATTACK FAILED: The monk failed to attack the monster");
=======
            logController->log("ATTACK FAILED: The monk failed to attack the monster");
>>>>>>> origin/main
        }
    }
    else {
        if(room->monsterTryAction()) {
            if(playerController->playerHasProtection()) {
                cout << "\n The " << room->getMonsterName() << " tried to attack, but the Staff of Protection blocked the attack from the " << room->getMonsterName() << "!" << endl;
<<<<<<< HEAD
                logs->printLogs("ATTACK BLOCKED: Player had Staff of Protection item");
                playerController->setPlayerProtection(false);
            } else {
                cout << "\nThe " << room->getMonsterName() << " strikes " << playerController->getPlayerName() << " the Monk! OUCH!" << endl;
                logs->printLogs("ATTACK: The monster attacked the player - the player had no Protection items");
=======
                logController->log("ATTACK BLOCKED: Player had Staff of Protection item");
                playerController->setPlayerProtection(false);
            } else {
                cout << "\nThe " << room->getMonsterName() << " strikes " << playerController->getPlayerName() << " the Monk! OUCH!" << endl;
                logController->log("ATTACK: The monster attacked the player - the player had no Protection items");
>>>>>>> origin/main
                playerController->subtractPlayerHealth(room->getMonsterAttackPoints());
            }
        }
        else {
            cout << "\nThe " << room->getMonsterName() << " failed to attack " << playerController->getPlayerName() << " the Monk!" << endl;
<<<<<<< HEAD
            logs->printLogs("ATTACK FAILED: Monster failed to attack player!");
=======
            logController->log("ATTACK FAILED: Monster failed to attack player!");
>>>>>>> origin/main
        }
    }
}

void GameHandler::CombatTryDefend(MonsterRoom* room, int turn) {
    if (turn == 0) {
        if(playerController->tryAction()) {
            cout << endl;
            cout << playerController->getPlayerName() << " the Monk defends themselves against the monster, restoring 1 HP." << endl;
<<<<<<< HEAD
            logs->printLogs("DEFEND: The Monk successfully defended, gaining 1 HP.");
            // If the player does not have max health, increase it by 1. Otherwise, move on.
            if(playerController->getPlayerHealth() != playerController->getPlayerBaseHealth())
                playerController->setPlayerHealth(playerController->getPlayerHealth() + 1);
            else logs->printLogs("DEFEND: Failed to increase health: Health was already max!");
=======
            logController->log("DEFEND: The Monk successfully defended, gaining 1 HP.");
            // If the player does not have max health, increase it by 1. Otherwise, move on.
            if(playerController->getPlayerHealth() != playerController->getPlayerBaseHealth())
                playerController->setPlayerHealth(playerController->getPlayerHealth() + 1);
            else logController->log("DEFEND: Failed to increase health: Health was already max!");
>>>>>>> origin/main
        }
        else {
            cout << endl;
            cout << playerController->getPlayerName() << " the Monk failed to defend against the " << room->getMonsterName() << endl;
            cout << "The " << room->getMonsterName() << " dealt ";
            printf("%d damage!\n", room->getMonsterAttackPoints());
<<<<<<< HEAD
            logs->printLogs("DEFEND FAILED: The Monk failed to defend against the monster - taking health away");
=======
            logController->log("DEFEND FAILED: The Monk failed to defend against the monster - taking health away");
>>>>>>> origin/main
            playerController->subtractPlayerHealth(room->getMonsterAttackPoints());
        }
    }
    else {
        if(room->monsterTryAction()) {
            if (room->getMonsterHealth() != room->getMonsterBaseHealth()) {
                room->setMonsterHealth(room->getMonsterHealth() + 1);
                cout << "\nThe " << room->getMonsterName() << " defended against " << playerController->getPlayerName() << " the Monk and gained +1 health." << endl;
<<<<<<< HEAD
                logs->printLogs("DEFEND: Monster defended against player");
            }
            else {
                cout << "\nThe " << room->getMonsterName() << " defended itself, but was already full health." << endl;
                logs->printLogs("DEFEND: Monster defended against the player [Full health]");
=======
                logController->log("DEFEND: Monster defended against player");
            }
            else {
                cout << "\nThe " << room->getMonsterName() << " defended itself, but was already full health." << endl;
                logController->log("DEFEND: Monster defended against the player [Full health]");
>>>>>>> origin/main
            }
        }
        else {
            room->subtractMonsterHealth(playerController->getPlayerDamage());
            cout << "\nThe " << room->getMonsterName() << " failed to defend itself, and " << playerController->getPlayerName() << " exploited this!" << endl;
<<<<<<< HEAD
            logs->printLogs("DEFEND FAILED: Monster failed to defend itself");
=======
            logController->log("DEFEND FAILED: Monster failed to defend itself");
>>>>>>> origin/main
        }
    }
}

<<<<<<< HEAD
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
        drawArt(title, title_height, midWidth(SCREEN_WIDTH, title_width), midHeight(SCREEN_HEIGHT / 2, title_height), rand() % (15) + 1);

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

            //game.resumeThread();

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
            toupper(_getch());
        }
        else
            break;
    }


    return volume;
=======
void GameHandler::BeginPuzzle() {
    cout << "There seems to be spikes in the floor. If the answer is incorrect, face a painful punishment. If the answer is correct, accept a generous reward." << endl;
    PuzzleRoom* room = (PuzzleRoom*) currentRoom;

    string instruction = "_";

    while(instruction != "0" && instruction != "1") {
        cout << "Does " << playerController->getPlayerName() << " the Monk accept the challenge? \n [0] = Yes \n [1] = No" << endl;
        cin >> instruction;
        if (instruction != "0" && instruction != "1") cout << playerController->getPlayerName() << " realised this wasn't an option!";
    }

    if(instruction == "0") {
        logController->log("The player chose to answer the question. The question was: ");
        logController->log(room->getPuzzle());
        cout << "The Egyptian writing reads: \n" << endl;
        cout << room->getPuzzle() << endl;

        logController->log("The answer is: ");
        logController->log(room->getPuzzleAnswer());
        string answer;
        cin >> answer;

        if(answer == room->getPuzzleAnswer()) {
            cout << "The walls begin to change. The symbols fade away. " << playerController->getPlayerName() << " answered correctly!" << endl;
            cout << "As the symbols fade, a hole in the wall reveals a Staff of Protection. " << playerController->getPlayerName() << " picks it up!" << endl;
            cout << "During the next battle, the first attack from a monster will be blocked!" << endl;

            logController->log("The answer was correct");
            playerController->setPlayerProtection(true);
        }
        else {
            playerController->subtractPlayerHealth(5);
            cout << "The walls begin to change. The symbols fade away. The floor begins to shake. " << playerController->getPlayerName() << " answered incorrectly!" << endl;
            printf("The Monk loses 5 HP for their mistake. [%d / %d] \n", playerController->getPlayerHealth(), playerController->getPlayerBaseHealth());
            logController->log("Player answered incorrectly - subtracting 5 HP from the player");
        }
    }

    cout << playerController->getPlayerName() << " moves on to the next room..." << endl;

    MoveRoom();
>>>>>>> origin/main
}