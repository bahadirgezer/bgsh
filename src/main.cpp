#include <iostream>
#include <vector>
#include "bgsh.h"

int main() {
    std::vector<std::string> args;
    std::string line;

    while(!EXIT) {
        printf(">>> ");
        std::getline(std::cin, line);
        line = trim(line);
        args = resplit(line);

        if (args.empty())
            continue;

        if (bgsh_commands.contains(args[0]))
            exec_bgsh(line, args);
        else if (args[0] == "cd") {
            if (args.size() == 1)
                chdir(getenv("HOME"));
            else
                chdir(args[1].c_str());
        } else
            exec_sh(line, args);

        history.add(line);
    } //while end

    return 0;
}

