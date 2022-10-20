#include<stdio.h>
#include<sys/types.h>
#include<signal.h>

void handler(int sig)
{
    printf("hello from handler\n");
    printf("The signal number is :%d\n",sig);
    
}    
int main()
{
	signal(SIGINT,handler);
	while(1);
	return 0 ;
}


