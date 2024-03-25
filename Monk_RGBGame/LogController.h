//
// Created by Mike on 09/03/2019.
//

#ifndef MONKASSIGNMENT_LOGCONTROLLER_H
#define MONKASSIGNMENT_LOGCONTROLLER_H

#include <string>
using namespace std;

class LogController {
public:
    void log(string log);
    void clearLogs(){ clearLogs(false); } // Calls itself with false; giving a default action to keep the file if no parameter is given
    void clearLogs(bool deleteFile);
};


#endif //MONKASSIGNMENT_LOGCONTROLLER_H
