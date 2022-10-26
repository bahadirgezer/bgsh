#include <iostream>
#include <vector>
#include <unistd.h>
#include "bgsh.h"

#define BUFFER_SIZE 1024

int EXIT = 0;

int main() {
    std::vector<std::string> args;
    std::string line;
    FILE* system_out;

    while(!EXIT) {
        printf(">>> ");
        std::getline(std::cin, line);
        args = resplit(line);

        if (args.empty())
            continue;

        if (bgsh_commands.contains(args[0])) {
            exec_bgsh(args);

        } else if (args[0].compare("cd") == 0) {
            if (args.size() == 1)
                chdir(getenv("HOME"));
            else
                chdir(args[1].c_str());

        } else if (args[0].compare("exit") == 0) {
            EXIT = 1;

        } else {
            pid_t pid = fork();
            if (pid == 0) {
                execl("/bin/sh", "sh", "-c", line.c_str(), NULL);
                exit(0);

            } else if (pid > 0) {
                int status;
                if (waitpid(pid, &status, 0) <= 0)
                    perror("waitpid");

                if (!WIFEXITED(status))
                    perror("WIFEXITED");

                if (WEXITSTATUS(status) == 127)
                    printf("bgsh: %s: command not found\n", args[0].c_str());

            } else {
                perror("fork");
                exit(1);
            }
        }

    } //while end

    return 0;
}

