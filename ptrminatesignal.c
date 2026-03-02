#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
int main(){
    pid_t pid=fork();
    if(pid==0){
        printf("Child entering sleep mode...\n");
        sleep(10);
        printf("Child process with pid %d\n",getpid());
        exit(0);

    }
    else{
        sleep(2);
        kill(pid,SIGKILL);
        int  status;
        wait(&status);

        if(WIFSIGNALED(status)){
            printf("Process exitted with signal %d\n",WTERMSIG(status));
        }
    }
}