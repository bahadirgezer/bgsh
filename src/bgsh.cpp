//
// Created by Bahadır Gezer on 24.10.2022.
//

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "bgsh.h"

int EXIT = 0;



bgsh_history history; // 15 element history buffer

int exec_bgsh(const std::string& line, const std::vector<std::string>& args) {
    // parses the special command and executes the shell equivalent
    if (args[0] == "listdir") {
        exec_sh("ls", args);

    } else if (args[0] == "mycomputername") {
        exec_sh("hostname", args);

    } else if (args[0] == "whatsmyip") {
        exec_sh("curl ifconfig.me", args);
        printf("\n");

    } else if (args[0] == "printfile") {
        if (args.size() == 1) {
            printf("bgsh: printfile: missing operand\n");
            return 1;
        }
        if (args.size() == 2) {
            std::fstream file;
            file.open(args[1], std::ios::in);
            if (!file.is_open()) {
                printf("bgsh: printfile: No such file or directory\n");
                return 1;
            }
            std::string pf_line;
            while (std::getline(file, pf_line)) {
                printf("%s", pf_line.c_str()); // print line by line
                while (getchar() != '\n'); // wait for enter ignore other inputs
            }
            file.close();
            return 0;
        }
        if (args.size() == 4) {
            if (args[2] != ">") {
                printf("bgsh: printfile: syntax error near unexpected token '%s'\n", args[2].c_str());
                return 1;
            }
            exec_sh("cat " + args[1] + " > " + args[3], args); // same as cp except the edge cases
            return 0;
        }
        printf("bgsh: printfile: Missing arguments\n");
        return 1;

    } else if (args[0] == "dididothat") {
        if (args.size() == 1) {
            printf("bgsh: dididothat: missing operand\n");
            return 1;
        }
        if (history.contains(line)) // if the buffer class contains the line
            printf("Yes\n");
        else
            printf("No\n");

    } else if (args[0] == "hellotext") {
        //exec_sh("${VISUAL-${EDITOR-nano}}", args);
        popen("gedit", "w");// open gedit

    } else if (args[0] == "exit") { // exit command, sets the global EXIT variable to 1
        EXIT = 1;

    } else { // default
        printf("bgsh: %s: command not found\n", args[0].c_str());
        return 1;
    }

    return 0;
}

int exec_sh(const std::string& line, const std::vector<std::string>& args) {
    pid_t pid = fork();
    if (pid == 0) { //child
        execl("/bin/sh", "sh", "-c", line.c_str(), NULL); // pass the line to the shell
        exit(0);
    } else if (pid > 0) { // parent
        int status;
        if (waitpid(pid, &status, 0) <= 0) // wait for child to finish
            perror("waitpid");
        if (!WIFEXITED(status))
            perror("WIFEXITED");
        if (WEXITSTATUS(status) != 0) { // if child exited with error
            if (WEXITSTATUS(status) == 127) {
                printf("bgsh: %s: command not found\n", args[0].c_str());
            } else {
                printf("bgsh: %s: command exited with status %d\n", args[0].c_str(), WEXITSTATUS(status));
            }
        }
    } else {
        perror("fork");
        return 1;
    }
    return 0;
}

// tokenizer function
std::vector<std::string> resplit(const std::string &s, const std::regex &sep_regex) {
    std::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
    std::sregex_token_iterator end;
    std::vector<std::string> tokens(iter, end);
    return tokens;
}

std::string ltrim(const std::string &s, const std::string &delims = WHITESPACE) {
    size_t start = s.find_first_not_of(delims);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s, const std::string &delims = WHITESPACE) {
    size_t end = s.find_last_not_of(delims);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

// string trimming function, removes characters from the beginning and end of the string.
// default characters are whitespace characters
std::string trim(const std::string &s, const std::string &delims) {
    return rtrim(ltrim(s, delims), delims);
}
