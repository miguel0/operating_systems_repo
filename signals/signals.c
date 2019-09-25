#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void signalHandler(int signum)
{
    printf("Signal received: %d.\n", signum);
}

int main()
{
    int pid;
    signal(10, signalHandler);
    pid = fork();

    if(pid == 0)
    {
        printf("I am son.\n");
        for(;;);
    }
    else
    {
        printf("I am parent.\n");
        kill(pid, 10);
        for(;;);
    }
}