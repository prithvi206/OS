#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
    int k=2,n1,n2,n3;
    void *ptr;
    int shm_fd = shm_open("fibno",O_CREAT | O_RDWR,0666);
    ftruncate(shm_fd,4096);
    ptr =mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
    printf("CHILD:\n");
    int i= atoi(argv[1]);
    //The atoi() function converts a character string to an integer value
    n1=0;
    n2=1;
    sprintf(ptr,"%d",n1);
    //sprintf stands for “String print”. 
    //Instead of printing on console, it store output on char buffer which are specified in sprintf.
    ptr+=strlen(ptr);
    printf("%d",n1);
    sprintf(ptr,"%d",n2);
    ptr+=strlen(ptr);
    printf("%d",n2);
    while(k!=i)
    {
        n3=n1+n2;
        sprintf(ptr,"%d",n3);
        printf("%d",n3);
        n1=n2;
        n2=n3;
        ptr+=strlen(ptr);
        k++;

    }

}


