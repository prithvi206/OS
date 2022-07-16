// Stimulation of "cat" command
// cat :Standard Unix utility that read files sequentially writing them to standard output
#include<stdio.h>
#include<stdlib.h>
int main(int argc ,char *argv)
{
    FILE *fp1;
    char ch;
    if(argc<2 )
    {
        printf("\n You are not passing the Filename\n");
        exit(1);
    }
     fp1 = fopen(argv[1],"r");
     fopen(const char * filename,  const char * mode)
    //  filename : name of the FILENAME
    //  mode: file access mode -> "r" means Opens a file for reading.The file must exist

     if(fp1==NULL)
     {
        printf("File doesn't exits \n");
        exit(1);
     }
     while((ch=fgetc(fp1))!=EOF)/*fgetc is used to read character from the file,
                                 it returns the character pointed by file pointer.
                                at the end of file fgetc returns EOF*/
     {
        printf("%c",ch);//EOF means END OF FILE
     }
     fclose(fp1);
     return 0;
}