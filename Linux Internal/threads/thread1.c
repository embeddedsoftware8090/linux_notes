/* program on threads
 * used pthread_create,pthread_join,pthread_exit
 * after pthread_exit ,if you print something it wont display */

#include<stdio.h>
#include<pthread.h>
void *thread (void * arg)
{
	int i;
	pthread_t call;
	static int s=0;
	call = pthread_self();
	printf("Thread ID = %ld\n",call);
	for(i=0;i<3;i++)
	{
	printf("s=%d\n",s);
	s++;
	}
}

int main()
{
	pthread_t thread_id,call;
	pthread_create(&thread_id,NULL,thread,NULL);
	printf("Hello\n");
	call = pthread_self();
	printf("Thread ID = %ld\n",call);
        pthread_join(thread_id,NULL);
	printf("Bye!!!!\n");
	pthread_exit(NULL);
	//this line won't print 
	printf("Thread exited\n");
	return 0;
}
