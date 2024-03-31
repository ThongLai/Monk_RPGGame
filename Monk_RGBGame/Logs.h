#pragma once

#include "CommonConfig.h"

class Logs {
private:
    string log_filename;
    ofstream outputFile;
public:
    Logs(string log_filename = "");
    ~Logs();

    void printLogs(string log = "game_events");
    void clearLogs();
    void deleteLogsFile();
};