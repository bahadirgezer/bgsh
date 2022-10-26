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
    for (auto & it : *this) {
        if (it == line) // whole line
            return true;
        if (resplit(line)[0] == resplit(it)[0]) // command
            return true;
    }
    return false;
}
