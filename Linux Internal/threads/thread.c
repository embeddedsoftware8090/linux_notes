#include<stdio.h>
#include<pthread.h>

void *pthread_function(void *arg )
{
   int a=5,b=5,sum;
   sum=a+b;
   printf("sum = %d\n",sum);
  
}

int main ()
{
	 pthread_t thread_id;
	 printf("Hi\n");
	 pthread_create(&thread_id,NULL,pthread_function,NULL);
	 pthread_join(thread_id,NULL);
	 printf("Thread created\n");
	 return 0;
}

