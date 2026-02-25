// A C program to demonstrate working of
// fork() and process table entries.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int i;
    int pid = fork();

    if (pid == 0)
    {
        sleep(10);
        for (i=0; i<20; i++)
            printf("I am Child\n");
            printf("%d %d\n",getpid(),getppid());
    }
    else
    {
        printf("I am Parent\n");
        printf("%d\n",getpid());
        wait(NULL);
    }
}