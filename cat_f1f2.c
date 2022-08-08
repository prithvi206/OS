#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    /*argc (ARGument Count) is int and stores number of command-line arguments passed by the user including the name of the program. So if we pass a value to a program, value of argc would be 2 (one for argument and one for program name)
The value of argc should be non negative.
argv(ARGument Vector) is array of character pointers listing all the arguments.
If argc is greater than zero,the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
Argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments.*/
    FILE *fp1,*fp2;
    char ch;
    if(argc<3)
    {
        printf("insufficient no. of arguments\n");
        exit(1);
    }
    fp1=fopen(argv[1],"a");
    fp2=fopen(argv[2],"r");
    if(fp2==NULL)
    {
        printf("Error in opening file\n");
        exit(1);
    }
    while((ch=fgetc(fp2))!=EOF)
    {
        fprintf(fp1,"%c",ch);

    }
    fclose(fp1);
    fclose(fp2);
    }