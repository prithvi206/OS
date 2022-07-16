//To demonstrate fork() system call

#include<stdio.h>
#include<unistd.h>
int main(){
    printf("Before fork\n");//P0
    fork();//2^1=2 :P0 ,P1
    fork();//2^2=4: P2,P3
    fork();//2^3=8: P4,P5,P6,P7
    printf("after fork\n");
    return 0;

}