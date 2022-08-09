#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<dirent.h>
void main(int argc, char *argv[])
{
    //The dirent structure, defined in the dirent.h file, is used for directory access operations

    DIR *dp;
    struct dirent *dirp;
    if(argc<2)
    {
        printf("\n You are not passing the directory\n");
        exit(1);
    }
    if((dp=opendir(argv[1]))==NULL)
    {
        printf("\nCannot open it doesnot exit %s file\n",argv[1]);
        exit(1);
    }
    while((dirp=readdir(dp))!=NULL)
    {
        printf("%s\n",dirp->d_name);
    }
    closedir(dp);
}