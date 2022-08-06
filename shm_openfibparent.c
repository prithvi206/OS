#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<string.h>


int main(int argc,char *argv[])
{
int i;
pid_t pid;
int k;
int n1,n2,n3;
const int size=4096;
int shm_fd;
void *ptr;

if(argc>1)
{
    sscanf(argv[1],"%d",&i);
    // sscanf reads formatted input.
    if(i<1)
    {
        printf("Error input: %d\n",i);
        return 0;
    }
}
else
{
    printf("Error : not passing N in command line\n");
    exit(0);

}
pid = fork();

if(pid==0)//child
{
    execlp("./fib","fib",argv[1],NULL);
}
else if(pid>0)
{
    wait(NULL);
    printf("\nPARENT: child completed\n");

    shm_fd = shm_open("fibno",O_RDONLY,0666);
    ptr = mmap(0,1024,PROT_READ,MAP_SHARED,shm_fd,0);
     /*<sys/mman.h> directory for mmap()reates a new mapping in the virtual address space of the
    calling process.
    format:
    void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
    length -- 1024  , length of the mapping
    MAP_SHARED--Share this mapping.  Updates to the mapping are visible to other processes mapping the same region
    PROT_READ-- Page can be read*/
    printf("Key/ID/fd of the shared memory: %d\n",shm_fd);
    printf("Parent printing\n");
    printf("%s",(char *)ptr);
    shm_unlink("OS");


}
return 0;


}