#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
int main(){
    pid_t pid=fork();
    if(pid==0){
      
        printf("Child process with pid %d\n",getpid());
        exit(5);

    }
    else{
      
        int  status;
        wait(&status);

        if(WIFEXITED(status)){
            printf("Process exitted with signal %d\n",WEXITSTATUS(status));
        }
    }
}