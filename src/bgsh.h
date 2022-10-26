//
// Created by Bahadır Gezer on 24.10.2022.
//

#ifndef BGSH_BGSH_H
#define BGSH_BGSH_H

#include <unordered_set>
#include <regex>
#include "bgsh_history.h"

extern const std::unordered_set<std::string> bgsh_commands;
extern int EXIT;
extern bgsh_history history;

const std::string WHITESPACE = " \n\r\t\f\v";

std::vector<std::string> resplit(const std::string &s, const std::regex &sep_regex = std::regex{"\\s+"});

int exec_bgsh(const std::string& line, const std::vector<std::string>& args);

int exec_sh(const std::string& line, const std::vector<std::string>& args);

std::string trim(const std::string &s, const std::string &delims = WHITESPACE);

#endif //BGSH_BGSH_H
