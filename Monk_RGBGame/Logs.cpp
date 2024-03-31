#include "Logs.h"

Logs::Logs(string log_filename) : log_filename(log_filename + ".log")
{
    outputFile.open(this->log_filename, ios_base::app);
}

Logs::~Logs()
{
    outputFile.close();
}

/*
 * An easy interface to log any text into the log file.
 * Appends a new line to the log file with the log parameter.
 */
void Logs::printLogs(string log) {
    outputFile << log << "\n";
}

/**
 * Clear the logs file.
 */
void Logs::clearLogs() {
    outputFile.open(log_filename, ofstream::out | ofstream::trunc);
}

void Logs::deleteLogsFile()
{
    if (remove(log_filename.c_str()))
        printMessCenter("Failed to delete the log file");
}
