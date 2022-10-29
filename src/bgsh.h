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

/**
 * Splits the string by a regex pattern. The default pattern is whitespaces.
 *
 * @param s string to split
 * @param sep_regex separator regex pattern
 * @return vector of substrings - tokens
 */
std::vector<std::string> resplit(const std::string &s, const std::regex &sep_regex = std::regex{"\\s+"});

/**
 * Executes the special shell commands. It does this by converting the special
 * command to its shell equivalent. Then this command is executed via the
 * exec_sh() function.
 *
 * Special commands are listed below:
 * [listdir, mycomputername, whatsmyip, printfile, dididothat, hellotext, exit]
 *
 *
 * @param line the line to be executed
 * @param args the arguments of the line
 * @return 0 if successful, 1 if not
 */
int exec_bgsh(const std::string& line, const std::vector<std::string>& args);

/**
 * Executes the standard shell command with fork() and exec(),
 * redirects the child processes output to stdout.
 *
 * @param line the line to be executed
 * @param args the arguments of the line
 * @return 0 if successful, 1 if not
 */
int exec_sh(const std::string& line, const std::vector<std::string>& args);

/**
 * Removes the leading and trailing characters in delims from string s.
 * Default delims are standard whitespaces.
 *
 * @param s the string to be trimmed
 * @param delims the characters to be removed
 * @return the trimmed string
 */
std::string trim(const std::string &s, const std::string &delims = WHITESPACE);

#endif //BGSH_BGSH_H
