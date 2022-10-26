//
// Created by Bahadır Gezer on 26.10.2022.
//

#ifndef BGSH_BGSH_HISTORY_H
#define BGSH_BGSH_HISTORY_H

#include <deque>
#include <string>

class bgsh_history : private std::deque<std::string> {
public:
    bgsh_history() = default;
    ~bgsh_history() = default;
    void add(const std::string& line);
    bool contains(const std::string& line);
};

#endif //BGSH_BGSH_HISTORY_H
