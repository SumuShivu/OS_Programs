#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    struct rlimit limit;
    limit.rlim_cur=2;
    limit.rlim_max=2;
    if(setrlimit(RLIMIT_CPU,&limit)==-1){
        perror("setrlimit");
        exit(1);
    }
    printf("CPU LINIT IS %lu",limit.rlim_cur);

    while(1);
}