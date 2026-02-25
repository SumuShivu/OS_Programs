#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* abc(void* args){
    int a,b;
  scanf("%d%d",&a,&b);
 int* res=(int*)malloc(sizeof(int));
 *res=a+b;
    return res;
}

int main(){
    pthread_t thread1;
 void* a=(int*)malloc(sizeof(int));
  pthread_create(&thread1,NULL,abc,NULL);
    pthread_join(thread1,&a);
  printf("ans=%d\n",*(int*)a);
  free(a);
    return 0;
}