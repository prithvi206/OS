//Zombie process
// Zombie is a process that has terminated but has not been cleaned up yet, wait function cleans up child process
// The init process automatically cleans up any zombie process that it inherits

// If the child process finishes before the parent process calls wait the child process becomes a zombie

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
    pid_t child_pid , my_pid, parent_pid;
    child_pid = fork();

    if(child_pid<0)
    {
        printf("Fork failed .Exiting\n");
        exit(0);
    }
    if(child_pid==0)
    {
        //child process
        printf("[CHILD]This is the child process\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[CHILD]My pid is %d\n",my_pid);
        printf("[CHILD]My parent's pid is %d\n",parent_pid);
        printf("[CHILD] Exiting\n");
        exit(0);
    }
    else
    {
      //parent process
      printf("[PARENT]This is the parent process.\n");
      my_pid = getpid();
      parent_pid = getppid();
      printf("[PARENT] My pid is %d \n",my_pid);
      printf("[PARENT]My parent's pid is %d\n",parent_pid);
      printf("Sleeping for 10 seconds\n");
      sleep(10);
      printf("[PARENT] Child pid =%d has ended but it has an entry in process table . It is a Zombie process.\n ",child_pid);
    }
    return 0;
}