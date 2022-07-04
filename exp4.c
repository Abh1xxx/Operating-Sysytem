#include<dirent.h>
#include<stdio.h>
 #include <string.h>
int main ()
{
    DIR* dir;
    struct dirent *entry;
    if((dir=opendir ("/"))==NULL)
    perror("Error during opendir() error");
    else
    {
        puts("contents of the current directory ");
        while((entry =readdir(dir))!=NULL)
        {
            printf("%s .",entry->d_name);

        }
    } 
}

