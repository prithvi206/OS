// CONSUMER PROGRAM SHARED MEMORY of shm_open

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>

int main()
{
    void *psm;
    int shmid1;
    shmid1 = shm_open("OS",O_RDONLY,0666);
    ftruncate(shmid1,1024);

    
    psm = mmap(0,1024,PROT_READ,MAP_SHARED,shmid1,0);


    /*<sys/mman.h> directory for mmap()reates a new mapping in the virtual address space of the
    calling process.
    format:
    void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
    length -- 1024  , length of the mapping
    MAP_SHARED--Share this mapping.  Updates to the mapping are visible to other processes mapping the same region
    PROT_READ-- Page can be read*/

    printf("key/ID/fs of the shared memory is %d\n",shmid1);
    printf("shared memory for consumer is attached at:%p\n", psm);
    printf("%s",(char *)psm);
    printf("\n");
    shm_unlink("OS");

    //removes the shared memory object named by the string pointed to by name.
    return 0;
}


