//
// Created by Mike on 09/03/2019.
//
#include <random>
#include <iostream>
#include <new>
#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(Room *sender) : Room (sender){

}

void MonsterRoom::Generate(int monsterId) {
    monster = new MonsterController(monsterId);
}

MonsterController *MonsterRoom::getMonster() {
    return monster;
}

void MonsterRoom::Render() {
    if(monster->getMonsterName() == "Goblin"){
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
    else if(monster->getMonsterName() == "Vampire"){
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
                     "\n"  << endl;
    }
    if(monster->getMonsterName() == "Zombie"){
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

    cout << "You enter a dark room, you can hardly see. In front of you, you hear a " << monster->getMonsterNoise() << endl;
    cout << "It's a " << monster->getMonsterName() << "! The door behind you locks. The battle has already begun." << endl;
}

bool MonsterRoom::isMonsterAlive() {
    return (monster->getMonsterHealth() > 0);
}

int MonsterRoom::getMonsterHealth() {
    return monster->getMonsterHealth();
}

int MonsterRoom::getMonsterBaseHealth() {
    return monster->getMonsterBaseHealth();
}

string MonsterRoom::getMonsterName() {
    return monster->getMonsterName();
}

string MonsterRoom::getMonsterNoise() {
    return monster->getMonsterNoise();
}

void MonsterRoom::setMonsterHealth(int value) {
    monster->setMonsterHealth(value);
}

void MonsterRoom::subtractMonsterHealth(int value) {
    monster->subtractMonsterHealth(value);
}

int MonsterRoom::getMonsterAttackPoints() {
    return monster->getMonsterAttackPoints();
}

bool MonsterRoom::monsterTryAction() {
    return monster->tryAction();
}

int MonsterRoom::monsterActionToPerform() {
    return monster->actionToPerform();
}
