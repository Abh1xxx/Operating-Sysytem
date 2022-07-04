#include<unistd.h>
#include<stdio.h>
int main()
{
    int pid,start;
    pid=fork();
    if(pid==-1)
    {
        perror("error fork()");
    }
    else if (pid==0)
    {
        printf("I am the child process\n");
        printf("process id of the child is =  %d \n",getpid());
        execlp("pwd","pwd",NULL);
    }
    else 
    {
       printf("I am the parent process\n");
    }
    return(0);
}