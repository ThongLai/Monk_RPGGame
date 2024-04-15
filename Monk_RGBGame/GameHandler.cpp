#include "GameHandler.h"

GameHandler::GameHandler()
{
    StartUp();
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

void GameHandler::subThread() {
    int key = 0;
    while (true) {
        addBuf(BUF);

        Sleep(50);
    }
}

void GameHandler::resetData()
{
    system("cls");

    player = new Player;
    player->setPlayer();
    curRoom = new EmptyRoom;

    roomsExplored = 0;
    isPause = true;


    START_TIME = clock() / CLOCKS_PER_SEC;
    TIME = 0;
    PAUSE_TIME = 0;

    //UnDeadCMD = false;
}

void GameHandler::deleteData()
{
    delete curRoom;
    delete player;
}

void GameHandler::resetGame()
{
    init();

    resetData();
}

void GameHandler::processGame()
{
    drawGame();

    isPause = false;
    thread sub_thread(&GameHandler::subThread, this);

    while (true) {
        curRoom->displayRoomNameAndDesc();
        if (!curRoom->processRoom(player))
            break;

        GenerateNewRooms();
        MoveRoom();
    }

    sub_thread.detach();
}

void GameHandler::pauseGame()
{
    PAUSE_TIME = clock() / CLOCKS_PER_SEC;
    isPause = true;
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

    printString(player->getName(), GAMEPLAY_W + midWidth(STATUS_W, player->getName().size()), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 - 5, player->getPlayerColor());

    for (int i = 0; i < STATUS_VAR_SIZE; i++)
        printString(STATUS_VAR[i], GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + i * 2);

    for (int i = 0; i < GUIDEBUTTONS_SIZE; i++)
        printString(GUIDEBUTTONS[i], GAMEPLAY_W + midWidth(STATUS_W, GUIDEBUTTONS[GUIDEBUTTONS_SIZE - 1]), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 2 + i * 2);

    // Health: 
    player->displayHealth();

    // Attack:
    player->displayDamage();

    // Rooms:
    printString(to_string(roomsExplored), GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10) + STATUS_VAR[0].size(), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + 4, player->getPlayerColor());

    //displayCommand();
}

void GameHandler::drawGUI()
{
    BOX side[2];

    side[0].setBox(0, 0, GAMEPLAY_W, GAMEPLAY_H, LIGHTGREEN, BLACK);
    side[0].printBox();

    side[1].setBox(0, GAMEPLAY_H, GAMEPLAY_W, DESCRIPTION_H, LIGHTGREEN, BLACK);
    side[1].printBox();
}

void GameHandler::updateTime()
{
    //Only update when the [TIME] fluctuates more than 1 second
    if (clock() / CLOCKS_PER_SEC - START_TIME - TIME < 1)
        return;

    TIME = clock() / CLOCKS_PER_SEC - START_TIME;

    GotoXY(GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10) + 3 + STATUS_VAR[0].size(), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5);
    cout << setfill('0') << setw(2) << TIME / 3600 << ":" << setfill('0') << setw(2) << (TIME / 60) % 60 << ":" << setfill('0') << setw(2) << TIME % 60 << endl;
}

void GameHandler::checkUnDeadCMD()
{
    if (buf == CHEATCODE)
    {
        UNDEADCMD = !UNDEADCMD;
        displayCommand();
        buf.clear();
    }
}

void GameHandler::addBuf(char key)
{
    if (!buf.empty() && key == buf.back())
        return;

    if (CHEATCODE.compare(0, buf.size() + 1, buf + key) == 0)
    {
        buf.push_back(key);
        checkUnDeadCMD();
    }
    else
    {
        buf.clear();
        buf.push_back(key);
    }
}

void GameHandler::displayCommand()
{
    string prompt = "UNDEAD COMMAND - ON";
    if (UNDEADCMD)
        printString(prompt, GAMEPLAY_W + midWidth(STATUS_W, 19), SCREEN_HEIGHT - 3, RED);
    else
        removeString(prompt, GAMEPLAY_W + midWidth(STATUS_W, 19), SCREEN_HEIGHT - 3);
}

void GameHandler::GenerateNewRooms() {
    roomsExplored += 1;

    //Update "Explored Rooms" value:
    printString(to_string(roomsExplored), GAMEPLAY_W + midWidth(STATUS_W, STATUS_VAR[0].size() + 10) + STATUS_VAR[0].size(), midHeight(SCREEN_HEIGHT, STATUS_VAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + 4, player->getPlayerColor());

    //Set the chance of finding a treasure gradually higher
    if (roomsExplored == 10) {
        TREASURE_ROOM_CHANCE += 5;
        MONSTER_ROOM_CHANCE -= 5;
        printOnDescriptionCenterAndWait("The Player has explored more than 10 rooms - increasing the chance of treasure rooms.", TREASURE_ROOM_COLOR);
    }
    else if (roomsExplored == 5) {
        TREASURE_ROOM_CHANCE += 5;
        EMPTY_ROOM_CHANCE -= 5;
        printOnDescriptionCenterAndWait("The Player has explored more than 5 rooms - increasing the chance of treasure rooms slightly", TREASURE_ROOM_COLOR);
    }
    
    int roomChance = generateRand(0, 100);
    Room* leftRoom, * rightRoom;

    if (roomChance < TREASURE_ROOM_CHANCE)
        leftRoom = new TreasureRoom;
    else if (roomChance < EMPTY_ROOM_CHANCE)
        leftRoom = new EmptyRoom;
    else
        leftRoom = new MonsterRoom;

    roomChance = generateRand(0, 100);
    if (roomChance < TREASURE_ROOM_CHANCE)
        rightRoom = new TreasureRoom;
    else if (roomChance < EMPTY_ROOM_CHANCE)
        rightRoom = new EmptyRoom;
    else
        rightRoom = new MonsterRoom;

    curRoom->setLeftRoom(leftRoom);
    curRoom->setRightRoom(rightRoom);
}

string MOVEROOM_PROMPT[] =
{
    "Left",
    "Right",
};
int MOVEROOM_PROMPT_SIZE = sizeof(MOVEROOM_PROMPT) / sizeof(string);

void GameHandler::MoveRoom() {
    curRoom->removeRoomName();

    printOnDescriptionCenterAndWait(player->getName() + " The Monk has explored " + to_string(roomsExplored) + " room(s) in the dungeon.");
    printOnDescriptionCenterAndWait(player->getName() + " the Monk moves on to the next room... ");
    
    int box_width = 21;
    int box_height = 5;
    MENU moveRoomMenu("Which direction will " + player->getName() + " go next?", MOVEROOM_PROMPT, MOVEROOM_PROMPT_SIZE, midWidth(GAMEPLAY_W, box_width), midHeight(GAMEPLAY_H, box_height * PRAY_PROMPT_SIZE), box_width, box_height, WHITE, BLACK);

    moveRoomMenu.printMenu();
    int buf = moveRoomMenu.inputMenu();
    moveRoomMenu.removeMenu();

    switch (buf)
    {
    case 0:
        curRoom = curRoom->getLeftRoom();
        printOnDescriptionCenterAndWait("You decided to go to the Left Room");
        break;
    case 1:
        curRoom = curRoom->getRightRoom();
        printOnDescriptionCenterAndWait("You decided to go to the Right Room");
        break;
    }
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
        drawArt(TITLE, TITLE_HEIGHT, midWidth(SCREEN_WIDTH, TITLE_WIDTH), midHeight(SCREEN_HEIGHT / 2, TITLE_HEIGHT));

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
            printStringCenter("LOADING ...");

            resetGame();
            system("cls");

            mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
            mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

            processGame();

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

            buf = toupper(_getch());

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
            printStringCenter("GOOD BYE! :-)", rand() % 15 + 1, BLACK);
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
            printStringCenter("Wrong format! Please type in a number", WHITE, RED);
            waitForKeyBoard();
        }
        else
            break;
    }


    return volume;
}