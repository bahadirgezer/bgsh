#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    printf("%d\n", fork());
    printf("Hello\n");
    return 0;
}
