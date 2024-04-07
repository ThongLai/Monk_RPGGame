#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(int monsterId) : Room("Monster Room") {
    description = "Monster room, danger lurks. The monk must face a formidable creature in a fierce battle for survival.";
    monster = new Monster(generateRand(0, 2));
}

Monster* MonsterRoom::getMonster() {
    return monster;
}

bool MonsterRoom::isMonsterAlive() {
    return (monster->getHealth() > 0);
}

void MonsterRoom::CombatTryAttack(Player* player, int turn) {
    if (turn == 0) {
        if (player->tryAction()) {
            cout << player->getName() << " the Monk attacks the " << monster->getName() << "!" << endl;
            monster->takeDamage(player->getDamage());
        }
        else {
            cout << "The " << monster->getName() << " dodged " << player->getName() << "'s attack!" << endl;
        }
    }
    else {
        if (monster->tryAction()) {
            if (player->hasProtection()) {
                cout << "\n The " << monster->getName() << " tried to attack, but the Staff of Protection blocked the attack from the " << monster->getName() << "!" << endl;
                player->setHasProtection(false);
            }
            else {
                cout << "\nThe " << monster->getName() << " strikes " << player->getName() << " the Monk! OUCH!" << endl;
                player->takeDamage(monster->getDamage());
            }
        }
        else {
            cout << "\nThe " << monster->getName() << " failed to attack " << player->getName() << " the Monk!" << endl;
        }
    }
}
void MonsterRoom::CombatTryDefend(Player* player, int turn) {
    if (turn == 0) {
        if (player->tryAction()) {
            cout << endl;
            cout << player->getName() << " the Monk defends themselves against the monster, restoring 1 HP." << endl;
            // If the player does not have max health, increase it by 1. Otherwise, move on.
            if (player->getHealth() != PLAYER_BASE_HEALTH)
                player->setHealth(player->getHealth() + 1);
            else 
                cout << "DEFEND: Failed to increase health: Health was already max!";
        }
        else {
            cout << endl;
            cout << player->getName() << " the Monk failed to defend against the " << monster->getName() << endl;
            cout << "The " << monster->getName() << " dealt ";
            printf("%d damage!\n", monster->getDamage());
            player->takeDamage(monster->getDamage());
        }
    }
    else {
        if (monster->tryAction()) {
            if (monster->getHealth() != monster->getBaseHealth()) {
                monster->setHealth(monster->getHealth() + 1);
                cout << "\nThe " << monster->getName() << " defended against " << player->getName() << " the Monk and gained +1 health." << endl;
            }
            else {
                cout << "\nThe " << monster->getName() << " defended itself, but was already full health." << endl;
            }
        }
        else {
            monster->takeDamage(player->getDamage());
            cout << "\nThe " << monster->getName() << " failed to defend itself, and " << player->getName() << " exploited this!" << endl;
        }
    }
}

void MonsterRoom::Render(string) {
    if (monster->getName() == "Goblin") {
        std::cout << "                   (    )\n"
            "                  ((((()))\n"
            "                  |o\\ /o)|\n"
            "                  ( (  _')\n"
            "                   (._.  /\\__\n"
            "                  ,\\___,/ '  ')\n"
            "    '.,_,,       (  .- .   .    )\n"
            "     \\   \\\\     ( '        )(    )\n"
            "      \\   \\\\    \\.  _.__ ____( .  |\n"
            "       \\  /\\\\   .(   .'  /\\  '.  )\n"
            "        \\(  \\\\.-' ( /    \\/    \\)\n"
            "         '  ()) _'.-|/\\/\\/\\/\\/\\|\n"
            "             '\\\\ .( |\\/\\/\\/\\/\\/|\n"
            "               '((  \\    /\\    /\n"
            "               ((((  '.__\\/__.')\n"
            "                ((,) /   ((()   )\n"
            "                 \"..-,  (()(\"   /\n"
            "                  _//.   ((() .\"\n"
            "          _____ //,/\" ___ ((( ', ___\n"
            "                           ((  )\n"
            "                            / /\n"
            "                          _/,/'\n"
            "                        /,/,\"\n"
            "\n"
            "------------------------------------------------\n" << endl;
    }
    else if (monster->getName() == "Vampire") {
        std::cout << "\n"
            "                            __...---^^^^^---...__\n"
            "                       _.-^^                     ^^-._\n"
            "                     ./'                             `\\.\n"
            "                   _/'                                 `\\_\n"
            "                  /'                                     `\\\n"
            "                 /                                         \\\n"
            "                |'                                         `|\n"
            "              __'                                           `__\n"
            "     ____.---^^^^-.                                       .-^^^^---.____\n"
            "\\_  (   __,--^^-._ ^.                                   .^ _.-^^--.__   )  _/\n"
            " `\\_ `-^      |  `\\  \\                                 /  /'  |      ^-' _/'\n"
            " |\\`\\_        |    \\  \\                               /  /    |        _/'/|\n"
            "|`|`\\`\\_     .|     \\  \\              .              /  /     |.     _/'/'|'|\n"
            "| |  `\\`\\_   |'     |   \\             |             /   |     `|   _/'/'  | |\n"
            "`|    /`\\`\\ ||                        |                        || /'/'\\    |'\n"
            " |  :'   \\,|'                  .._         _..                  `|.'   `:  |\n"
            " `| |     /                       ^=._ _.=^                       \\     | |'\n"
            "  |      d^^^xxx.__                  `|'                  __.xxx^^^b      |\n"
            "  `|    d#.  9XX^^\\\\^^--..__          |          __..--^^//^^XX    #b    |'\n"
            "   |   |##x__  |    \\       ^^Xx..__  |  __..xX^^       /    |  __x#|    |\n"
            "    \\     ^^   |     \\_            _/^ ^\\_            _/     |   ^^     /\n"
            "     `-._      |       ^^-----...-^       ^-...-----^^      |'      _.-'\n"
            "         ^-._  `|   ^^-------^^^^    |      ^^^^-------^^   |   _.-^\n"
            "             ^- ||                  .|                     || -^\n"
            "               |^||                 l|                    ||^|\n"
            "               |  |                .d|xx.                 |  |\n"
            "              |'  `|                                     |'  `|\n"
            "              |   |;               ..----.               ;|   |\n"
            "              |   |X\\._            ^ __               _./X|   |\n"
            "             |'    |  ^-._         .X\"\"^^^         _.-^  |    `|\n"
            "             |     |     \\^-._                 _.-^/     |     |\n"
            "         ___|,     `|      `\\\\^-._         _.-^//'      |'     `|___\n"
            "..---^^^^   |       |         `\\\\\\^-.___.-^///'         |       |   ^^^^---..\n"
            "            |       `|            `\\\\XXX//'            |'       |\n"
            "            |      | `|              ^^^              |' |      |\n"
            "            `|     `| `|                             |' |'     |'\n"
            "                     \\  \\                           /  /\n"
            "..........------------------.....__      __.....-------------------..........\n"
            "                                   ^\\   /^\n"
            "                                     \\v/\n"
            "                                      |\n"
            "                                      |\n"
            "___                                   |                                    __\n"
            "#######xxxxxx_____                    |                    _____xxxxxx#######\n"
            "#######################xxxxxxxxxx___  |  ___xxxxxxxxxx#######################\n"
            "#############################################################################\n"
            "#############################################################################\n"
            "#############################################################################\n"
            "#############################################################################\n"
            "\n" << endl;
    }
    if (monster->getName() == "Zombie") {
        std::cout << "X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n"
            "|                           ,,'``````````````',,                            |\n"
            "X                        ,'`                   `',                          X\n"
            "|                      ,'                         ',                        |\n"
            "X                    ,'          ;       ;          ',                      X\n"
            "|       (           ;             ;     ;             ;     (               |\n"
            "X        )         ;              ;     ;              ;     )              X\n"
            "|       (         ;                ;   ;                ;   (               |\n"
            "X        )    ;   ;    ,,'```',,,   ; ;   ,,,'```',,    ;   ;               X\n"
            "|       (    ; ',;   '`          `',   ,'`          `'   ;,' ;              |\n"
            "X        )  ; ;`,`',  _--~~~~--__   ' '   __--~~~~--_  ,'`,'; ;     )       X\n"
            "|       (    ; `,' ; :  /       \\~~-___-~~/       \\  : ; ',' ;     (        |\n"
            "X  )     )   )',  ;   -_\\  o    /  '   '  \\    o  /_-   ;  ,'       )   (   X\n"
            "| (     (   (   `;      ~-____--~'       '~--____-~      ;'  )     (     )  |\n"
            "X  )     )   )   ;            ,`;,,,   ,,,;',            ;  (       )   (   X\n"
            "| (     (   (  .  ;        ,'`  (__ '_' __)  `',        ;  . )     (     )  |\n"
            "X  )     \\/ ,\".). ';    ,'`        ~~ ~~        `',    ;  .(.\", \\/  )   (   X\n"
            "| (   , ,'|// / (/ ,;  '        _--~~-~~--_        '  ;, \\)    \\|', ,    )  |\n"
            "X ,)  , \\/ \\|  \\\\,/  ;;       ,; |_| | |_| ;,       ;;  \\,//  |/ \\/ ,   ,   X\n"
            "|\",   .| \\_ |\\/ |#\\_/;       ;_| : `~'~' : |_;       ;\\_/#| \\/| _/ |.   ,\"  |\n"
            "X#(,'  )  \\\\\\#\\ \\##/)#;     :  `\\/       \\/   :     ;#(\\##/ /#///  (  ',)# ,X\n"
            "|| ) | \\ |/ /#/ |#( \\; ;     :               ;     ; ;/ )#| \\#\\ \\| / | ( |) |\n"
            "X\\ |.\\\\ |\\_/#| /#),,`   ;     ;./\\_     _/\\.;     ;   `,,(#\\ |#\\_/| //.| / ,X\n"
            "| \\\\_/# |#\\##/,,'`       ;     ~~--|~|~|--~~     ;       `',,\\##/#| #\\_// \\/|\n"
            "X  ##/#  #,,'`            ;        ~~~~~        ;            `',,#  #\\##  //X\n"
            "|####@,,'`                 `',               ,'`                 `',,@####| |\n"
            "X#,,'`                        `',         ,'`                        `',,###X\n"
            "|'                               ~~-----~~                               `' |\n"
            "X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n"
            "\n"
            "------------------------------------------------\n" << endl;
    }

    cout << description << monster->getDescription() << endl;
    cout << "It's a " << monster->getName() << "! The door behind you locks. The battle has already begun." << endl;
}

void MonsterRoom::processRoom(Player* player) {
    int turn = 0;
    while (isMonsterAlive()) {
        printf("The monster's health is currently: [%d / %d]\n", monster->getHealth(), monster->getBaseHealth());
        printf("The Monk's Health is currently: [%d / %d]\n", player->getHealth(), PLAYER_BASE_HEALTH);

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
                CombatTryAttack(player, turn);
            }
            else {
                CombatTryDefend(player, turn);
            }

            turn = 1; // Set the turn to the monster.
        }
        else {

            if (monster->actionToPerform() == 0) {
                CombatTryAttack(player, turn);
            }
            else {
                CombatTryDefend(player, turn);
            }
            if (monster->tryAction()) { // Tries to attack or defend

            }
            turn = 0; // Set the turn back to the player.
        }
    }

    // The Monster has been defeated, allow the player to move on.
    cout << "The " << monster->getName() << " was defeated by " << player->getName() << " The Monk! \n The Monk moves on to the next room..." << endl;
}
