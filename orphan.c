//orphan process

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main()
{
    pid_t my_pid, parent_pid , child_pid;
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
        printf("[CHILD] Sleeping for 10 seconds .\n");
        sleep(10);
        printf("[CHILD] MY parent ended .So I am an orphan proces adopted by init process .\n");
    }
    else{
         //parent process
      printf("[PARENT]This is the parent process.\n");
      my_pid = getpid();
      parent_pid = getppid();
      sleep(2);
      printf("[PARENT] My pid is %d \n",my_pid);
      printf("[PARENT]My parent's pid is %d\n",parent_pid);
      printf("Exiting\n");
      exit(0);

    }
    return 0;
}