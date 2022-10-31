#include <iostream>
#include <vector>
#include <unistd.h>
#include "bgsh.h"

int main() {
    std::vector<std::string> args;
    std::string line;
    //std::unordered_set<std::string> bgsh_commands (
    // {"listdir","mycomputername","whatsmyip","printfile",
    // "dididothat","hellotext","exit"}); // special commands

    std::unordered_set<std::string> bgsh_commands;
    bgsh_commands.insert("listdir");
    bgsh_commands.insert("mycomputername");
    bgsh_commands.insert("whatsmyip");
    bgsh_commands.insert("printfile");
    bgsh_commands.insert("dididothat");
    bgsh_commands.insert("hellotext");
    bgsh_commands.insert("exit"); //initializer_list did not work?

    while(!EXIT) { // terminates after exit command
        printf(">>> ");
        std::getline(std::cin, line);
        line = trim(line);
        args = resplit(line); // tokenize

        if (args.empty())
            continue;

        // if command is from the special commands
        if (bgsh_commands.find(args[0]) != bgsh_commands.end())
            exec_bgsh(line, args);
        else if (args[0] == "cd") { // ch of parent process
            if (args.size() == 1)
                chdir(getenv("HOME"));
            else
                chdir(args[1].c_str());
        } else // if command is not from the special commands just exec the shell command
            exec_sh(line, args);

        history.add(line); // add to history
    } //while end

    return 0;
}
