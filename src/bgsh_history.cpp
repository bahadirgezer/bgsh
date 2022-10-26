//
// Created by Bahadır Gezer on 26.10.2022.
//

#include "bgsh_history.h"
#include "bgsh.h"

void bgsh_history::add(const std::string& line) {
    if (this->size() == 15) {
        this->pop_front();
    }
    this->push_back(line);
}

bool bgsh_history::contains(const std::string& line) {
    std::string check, command;
    if (std::regex_match(line, std::regex{"dididothat\\s*\"?(.*)\"?"}))
        check = std::regex_replace(line, std::regex{"dididothat\\s*\"?(.*)\"?"}, "$1");
    else
        return false;
    command = resplit(check)[0];
    for (auto & it : *this) {
        if (check == it) // whole line
            return true;
        if (command == resplit(it)[0]) // command
            return true;
    }
    return false;
}
