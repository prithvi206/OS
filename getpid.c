//Demonstrate exit(),execlp(),getpid(),getppid()

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t child_pid , my_pid, parent_pid ,wid; // PROCESS ID datatype
    int i=10;
    child_pid = fork();

    if(child_pid<0)
    {
        printf("Fork failed. Exiting! \n");
    }
    if(child_pid==0)
    {
        // printf("[CHILD] Before using exit syscall\n");
        // exit(0);
        parent_pid = getppid();
        printf("[CHILD] this is the child process.\n");
        my_pid= getpid();
        printf("[CHILD] My pid is %d\n",my_pid);
        printf("[CHILD] My parent's pid is %d\n",parent_pid);
        printf("[CHILD] -i =%d\n",--i);
        printf("[CHILD] Child process going to load another program using execlp syscall\n");
        execlp("/bin/pwd","pwd",NULL);
        // execlp(const char *file,const char *arg0,..,NULL)
        //pwd : print working directory, gives full path of the current working directory
        //<unistd.h> header file
        //The execlp() function replaces the current process image with a new process image specified by file
        //Pointers to NULL-terminated character strings
    }
    else
    {
        // parent process
        printf("[PARENT] This is the parent process.\n");
        my_pid= getpid();
        printf("[PARENT] Waiting for child to terminate\n");
        wid= wait(NULL);
        // <sys/wait.h> header file
        printf("[PARENT] Resuming after the termination of %d \n",wid);
        printf("[PARENT] My parent's pid is %d\n",parent_pid);
        printf("[PARENT] My childs pid is %d\n",child_pid);
        printf("[PARENT] i = %d\n",++i);
    }
}
