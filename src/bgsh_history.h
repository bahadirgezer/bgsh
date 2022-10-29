//
// Created by Bahadır Gezer on 26.10.2022.
//

#ifndef BGSH_BGSH_HISTORY_H
#define BGSH_BGSH_HISTORY_H

#include <deque>
#include <string>

/**
 * @class bgsh_history
 * @brief A class that stores the command history for bgsh.
 * It can be though of as a circular buffer of size 15.
 */
class bgsh_history : private std::deque<std::string> {
public:
    bgsh_history() = default;
    ~bgsh_history() = default;

    /**
     * Adds a command to the history. If the history is full, the oldest command is removed.
     *
     * @param line the command to be added
     */
    void add(const std::string& line);

    /**
     * Checks if the command is in the history.
     *
     * @param line the command to be checked
     * @return true if the command is in the history, false if not
     */
    bool contains(const std::string& line);
};

#endif //BGSH_BGSH_HISTORY_H
