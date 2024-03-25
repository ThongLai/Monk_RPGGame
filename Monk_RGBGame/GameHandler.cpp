#include "GameHandler.h"

GameHandler::GameHandler(string playerName, string description) {
    playerController = new PlayerController(3, playerName, description);
    logController = new LogController();
    randomController = new RandomController;

    logController->clearLogs();
    logController->log("Monk created with name: " + playerName + " with a base health of 15, and a damage of 3.");
    logController->log("Monk's description: " + description);

    EmptyRoom* spawnRoom = new EmptyRoom(nullptr);
    spawnRoom->Generate(randomController->getRandomIndex(1, 100));
    spawnRoom->Render();
    currentRoom = spawnRoom;
    logController->log("Generated Empty spawn room.");
    ExploreEmptyRoom();
}

void GameHandler::GenerateRoom(Room *sender, string direction) {
    roomsExplored += 1;

    string log = "Generating new room... #";
    log += to_string(roomsExplored);
    logController->log(log);

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
        logController->log("The Player has explored more than 10 rooms - increasing the chance of treasure rooms.");
    }
    else if(roomsExplored > 5) {
        treasureChance = 15;
        monsterChance = 55;
        logController->log("The Player has explored more than 5 rooms - increasing the chance of treasure rooms slightly");
    }
    int roomId = rngRoomId();
    Room* newRoom;

    logController->log("Generating new room....");
    switch (roomId) {
        default:
        case (0):
            newRoom = new EmptyRoom(sender);
            newRoom->Generate(randomController->getRandomIndex(1, 100));
            newRoom->Render();

            if (direction == "0") currentRoom->setLeftRoom(newRoom);
            else currentRoom->setRightRoom(newRoom);

            currentRoom = newRoom;
            logController->log("Generated new Empty room");
            ExploreEmptyRoom();
            break;
        case (1): {
            newRoom = new MonsterRoom(sender);
            newRoom->Generate(randomController->getRandomIndex(0, 2));
            newRoom->Render();

            if (direction == "0") currentRoom->setLeftRoom(newRoom);
            else currentRoom->setRightRoom(newRoom);

            currentRoom = newRoom;
            logController->log("Generated new Monster room");
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
            logController->log("Generated Treasure room!");
            break;
        }
        case (3): {
            PuzzleRoom *puzzleRoom = new PuzzleRoom(sender);
            puzzleRoom->Generate();
            puzzleRoom->Render(playerController->getPlayerName());
            currentRoom = puzzleRoom;

            logController->log("Generated Puzzle room!");
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
    logController->log("Choosing a random room ID from the percentage chances");
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

        logController->log(log);
        log = "The Monster's health is currently: ";
        log += to_string(room->getMonsterHealth());

        logController->log(log);
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
    logController->log("DEFEAT: Monster was defeated by player");
    currentRoom->isRoomComplete = true;

    MoveRoom();
}

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
        logController->log("Player prayed in empty room: restoring health");
        printf("Naturally, you sit inside the demonic-looking summoning circle. You're now full health! [%d / %d] \n",
               playerController->getPlayerHealth(), playerController->getPlayerBaseHealth());
    }

    // Cast the current room to an EmptyRoom object.
    EmptyRoom* room = (EmptyRoom*) currentRoom;

    if(room->hasItem) {
        cout << "As " << playerController->getPlayerName() << " walks forward, they see a glisten in front of them." << endl;
        logController->log("Generated item inside current room");
        instruction = "2";
        while (instruction != "0" && instruction != "1") {
            cout << " What do you do? \n [0] = Pick Up \n [1] = Ignore" << endl;

            cin >> instruction;
            if(instruction != "0" && instruction != "1") cout << "The Monk didn't understand that!"<< endl;
        }

        if(instruction == "0") {
            if(randomController->getRandomIndex(1, 100) < 21) {
                logController->log("ITEM: Staff of Protection");
                cout << "You approach the item and pick it up... It's a Staff of Protection! \n During your next combat, the Staff of Protection will block the first attack." << endl;
                playerController->setPlayerProtection(true);
            }
            else {
                logController->log("ITEM: sewing needle; subtracting player health");
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
            logController->log("Player did not provide a valid option - expected [0] || [1]");
        }
    }
    GenerateRoom(currentRoom, direction);
}

void GameHandler::CombatTryAttack(MonsterRoom* room, int turn) {
    if(turn == 0) {
        if(playerController->tryAction()) {
            cout << playerController->getPlayerName() << " the Monk attacks the " << room->getMonsterName() << "!" << endl;
            logController->log("ATTACK: The monk successfully attacked the monster");
            room->subtractMonsterHealth(playerController->getPlayerDamage());
        }
        else {
            cout << "The " << room->getMonsterName() << " dodged " << playerController->getPlayerName() << "'s attack!" << endl;
            logController->log("ATTACK FAILED: The monk failed to attack the monster");
        }
    }
    else {
        if(room->monsterTryAction()) {
            if(playerController->playerHasProtection()) {
                cout << "\n The " << room->getMonsterName() << " tried to attack, but the Staff of Protection blocked the attack from the " << room->getMonsterName() << "!" << endl;
                logController->log("ATTACK BLOCKED: Player had Staff of Protection item");
                playerController->setPlayerProtection(false);
            } else {
                cout << "\nThe " << room->getMonsterName() << " strikes " << playerController->getPlayerName() << " the Monk! OUCH!" << endl;
                logController->log("ATTACK: The monster attacked the player - the player had no Protection items");
                playerController->subtractPlayerHealth(room->getMonsterAttackPoints());
            }
        }
        else {
            cout << "\nThe " << room->getMonsterName() << " failed to attack " << playerController->getPlayerName() << " the Monk!" << endl;
            logController->log("ATTACK FAILED: Monster failed to attack player!");
        }
    }
}

void GameHandler::CombatTryDefend(MonsterRoom* room, int turn) {
    if (turn == 0) {
        if(playerController->tryAction()) {
            cout << endl;
            cout << playerController->getPlayerName() << " the Monk defends themselves against the monster, restoring 1 HP." << endl;
            logController->log("DEFEND: The Monk successfully defended, gaining 1 HP.");
            // If the player does not have max health, increase it by 1. Otherwise, move on.
            if(playerController->getPlayerHealth() != playerController->getPlayerBaseHealth())
                playerController->setPlayerHealth(playerController->getPlayerHealth() + 1);
            else logController->log("DEFEND: Failed to increase health: Health was already max!");
        }
        else {
            cout << endl;
            cout << playerController->getPlayerName() << " the Monk failed to defend against the " << room->getMonsterName() << endl;
            cout << "The " << room->getMonsterName() << " dealt ";
            printf("%d damage!\n", room->getMonsterAttackPoints());
            logController->log("DEFEND FAILED: The Monk failed to defend against the monster - taking health away");
            playerController->subtractPlayerHealth(room->getMonsterAttackPoints());
        }
    }
    else {
        if(room->monsterTryAction()) {
            if (room->getMonsterHealth() != room->getMonsterBaseHealth()) {
                room->setMonsterHealth(room->getMonsterHealth() + 1);
                cout << "\nThe " << room->getMonsterName() << " defended against " << playerController->getPlayerName() << " the Monk and gained +1 health." << endl;
                logController->log("DEFEND: Monster defended against player");
            }
            else {
                cout << "\nThe " << room->getMonsterName() << " defended itself, but was already full health." << endl;
                logController->log("DEFEND: Monster defended against the player [Full health]");
            }
        }
        else {
            room->subtractMonsterHealth(playerController->getPlayerDamage());
            cout << "\nThe " << room->getMonsterName() << " failed to defend itself, and " << playerController->getPlayerName() << " exploited this!" << endl;
            logController->log("DEFEND FAILED: Monster failed to defend itself");
        }
    }
}

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
}