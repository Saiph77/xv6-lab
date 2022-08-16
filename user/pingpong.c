#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

#define MSGSIZE 16

int main() {
    int fd[2];
    char buf[MSGSIZE];
    pipe(fd);

    int pid = fork();
    if (pid > 0) {
        printf("父进程\n");
        write(fd[1], "ping", MSGSIZE);
        wait(NULL);
        read(fd[0 ], buf,MSGSIZE);
        printf("父进程收到了：%s\n", buf);
    } else {
        printf("子进程\n");
        read(fd[0], buf, MSGSIZE);
        printf("子进程收到了：%s\n", buf);
        write(fd[1],"pong",MSGSIZE);
    }
    return 0;
}