#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFFER_SIZE 30

int main()
{
    int fd,n;
    char buff[BUFFER_SIZE],filename[100];
    printf("\nEnter filename: ");
    scanf("%s", filename);

    fd= open(filename,O_RDWR);
    printf("File descriptor is %d \n",fd);
      if(fd==1)
      {
        printf("Failed to open file\n");
        exit(0);

      }
      printf("Readig first 10 characters from first file\n");
      n= read(fd,buff,10);
      write(1,buff,10);
      printf("\nSkipping 5 characters from current position in the file:\n");
      lseek(fd,5,SEEK_CUR);
      n= read(fd,buff,10);
      write(1,buff,10);
      printf("\nGoing to 5th last character is the file\n");
      lseek(fd,-5,SEEK_END);
      n= read(fd,buff,7);
      write(1,buff,5);
      printf("\nGoing to the 3rd characters in the file\n");
      lseek(fd,3,SEEK_SET);
      n=read(fd,buff,5);
      write(1,buff,n);
      return 0;
}