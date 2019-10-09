#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(void)
{
  int pid;
  pid = fork();

  if (pid == 0)
  {
    int key = 10;
    int shmid = shmget(key, 100, IPC_CREAT|0666);
    char* message = (char*) shmat(shmid, NULL, 0);
    sprintf(message, "Hello world");

    while(message[0] == 'H')
    {
      sleep(1);
    }

    printf("Value of message: %s \n", message);
  }
  else
  {
    int key = 10;
    int shmid = shmget(key, 100, IPC_CREAT|0666);
    char* message = (char*) shmat(shmid, NULL, 0);
    
    sleep(1);

    printf("Value of message: %s \n", message);
    sprintf(message, "Another message");

    sleep(1);
  }

  return 0;
}
