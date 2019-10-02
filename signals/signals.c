#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int stopInf = 1;
int stopPrint = 1;

void signalHandler(int signum)
{
    if(stopPrint == 0)
    {
        printf("Signal received: %d.\n", signum);
        stopInf = 0;
    }
}

int main()
{
    int pid;
    signal(10, signalHandler);
    pid = fork();

    if(pid == 0)
    {
        printf("I am son.\n");
        while(stopInf == 1)
        {
            if(stopPrint == 1)
            {
                printf("In the loop.\n");
                stopPrint = 0;
            }
        }
        printf("Son stopped.\n");
    }
    else
    {
        printf("I am parent.\n");
        for(;;)
        {
            kill(pid, 10);
            sleep(1);
        }
    }
}