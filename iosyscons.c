#include<stdio.h>
#include<unistd.h>
#define BUFFER_SIZE 30

int main()
{
    char buffer[BUFFER_SIZE];
    int n;

    printf("Enter the string:\n");
    n= read(0,buffer,BUFFER_SIZE);
    printf("Number of characters read:%d\n",n);
    write(1,buffer,BUFFER_SIZE);
    return 0;
}
