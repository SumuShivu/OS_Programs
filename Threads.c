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

int* pqr(void* args){
  int a,b;
  scanf("%d%d",&a,&b);
  int* res=(int*)malloc(sizeof(int));
 *res=a-b;
    return res;
}
int main(){
    pthread_t thread1,thread2;
 void* a=(int*)malloc(sizeof(int));
  void* b=(int*)malloc(sizeof(int));
  pthread_create(&thread1,NULL,abc,NULL);
    pthread_join(thread1,&a);
    pthread_create(&thread2,NULL,pqr,NULL);
  
     pthread_join(thread2,&b);
  printf("ans1=%d\n ans2=%d\n",*(int*)a,*(int*)b);
  free(a);free(b);
    return 0;
}