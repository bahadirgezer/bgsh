//
// Created by Bahadır Gezer on 24.10.2022.
//

#include "bgsh.h"

extern int EXIT;

const std::unordered_set<std::string> bgsh_commands (
        {"listdir",
         "mycomputername",
         "whatsmyip",
         "printfile",
         "dididothat",
         "hellotext"}
         );

int exec_bgsh(const std::vector<std::string>& args) {

    return 0;
}

std::vector<std::string> resplit(const std::string &s, const std::regex &sep_regex) {
    std::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
    std::sregex_token_iterator end;
    return {iter, end};
}
