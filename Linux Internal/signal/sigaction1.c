#include<signal.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void handler_sig(int sig)
{
	printf("hello\n");
}
int main()
{
	int call;
	struct sigaction sa;
	sa.sa_handler = handler_sig;
	sa.sa_flags=0;
	call=sigaction(SIGUSR1,&sa,NULL);	
		if(call == 0)
		{
			printf("sigaction is success\n");
		}
         printf("PID= %d\n",getpid());
	 return 0;
}
