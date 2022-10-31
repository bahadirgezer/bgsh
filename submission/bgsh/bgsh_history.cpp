//
// Created by Bahadır Gezer on 26.10.2022.
//

#include "bgsh_history.h"
#include "bgsh.h"

/**
 * Adds a command to the history. If the history is full, the oldest command is removed.
 *
 * @param line the command to be added
 */
void bgsh_history::add(const std::string& line) {
    if (this->size() == 15) {
        this->pop_front();
    }
    this->push_back(line);
}

/**
 * Parses the dididothat line to get the command to be checked.
 *
 * Checks if the command is in the history.
 * @param line the command to be checked
 * @return true if the command is in the history, false if not
 */
bool bgsh_history::contains(const std::string& line) {
    std::string check, command;
    if (std::regex_match(line, std::regex("dididothat\\s*\"?(.+?(?=\")|.+)\"?"))) // regex parse
        check = std::regex_replace(line, std::regex("dididothat\\s*\"?(.+?(?=\")|.+)\"?"), "$1");
    else
        return false;
    //command = resplit(check)[0];
//    for (auto & it : *this) {
    for (std::deque<std::string>::iterator it = this->begin(); it != this->end(); it++) {
        if (check == *it) // whole line
            return true;
        /*
        if (command == resplit(it)[0]) // command
            return true;
         */
    }
    return false;
}
