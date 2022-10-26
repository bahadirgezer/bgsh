//
// Created by Bahadır Gezer on 24.10.2022.
//

#ifndef BGSH_BGSH_H
#define BGSH_BGSH_H

#include <regex>
#include <unordered_set>

extern const std::unordered_set<std::string> bgsh_commands;

std::vector<std::string> resplit(const std::string &s, const std::regex &sep_regex = std::regex{"\\s+"});

int exec_bgsh(const std::vector<std::string>& args);

#endif //BGSH_BGSH_H
