//To implement Producer-consumer using shared memory
//Implement the above using shm_open and mmap,fruncate(),shm_unlink

//PRODUCER PROGRAM SHARED MEMORY

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
    void *psm;
    char buf[10];
    int shmid1;
    shmid1 = shm_open("OS", O_CREAT | O_RDWR, 0666);
    ftruncate(shmid1,1024);

    psm = mmap(0,1024,PROT_WRITE,MAP_SHARED,shmid1,0);
      /*<sys/mman.h> directory for mmap()reates a new mapping in the virtual address space of the
    calling process.
    format:
    void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
    length -- 1024  , length of the mapping
    MAP_SHARED-- A flag used to specify Share this mapping.  Updates to the mapping are visible to other processes mapping the same region
    PROT_WRITE-- Page may be written */

    printf("Key/ID/fd of the shared memory: %d\n",shmid1);
    printf("shared memory is attached at: %p\n",psm);
    printf("enter some data to write to shared memory\n");
    read(0,buf,10);
    //unistd.h directory
    // read (int fd, void* buf, size_t cnt);  
    sprintf(psm,"%s",buf);
    return 0;
}
