#include <iostream>
#include <vector>
#include <unistd.h>
#include "bgsh.h"

int main() {
    std::vector<std::string> args;
    std::string line;

    while(!EXIT) { // terminates after exit command
        printf(">>> ");
        std::getline(std::cin, line);
        line = trim(line);
        args = resplit(line); // tokenize

        if (args.empty())
            continue;

        if (bgsh_commands.contains(args[0])) // if command is from the special commands
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
