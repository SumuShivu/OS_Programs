#include<stdio.h>
#include<sys/types.h>

int main(){
    int pid=fork();
    if(pid==0){
        printf("\nChild running...\n");
        printf("pid=%d,ppid=%d",getpid(),getppid());
        exit(0);
    }
else {
      sleep(50);
        printf("\nParent running...\n");
        
    }

}