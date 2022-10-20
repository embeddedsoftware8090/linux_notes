#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int pfd[2];
	pid_t call;
	char *buff_w="hello";
	char buff_r[20];	
	//create a pipe
	pipe(pfd);
	//create a child process
	call = fork();
	if (call < 0)
	{
		perror("fork\n");
	}
	 if ( call == 0)
	{
		//communicate from child process to parent
		//close fd[0] of child
		close(pfd[0]);
		write(pfd[1],buff_w,strlen(buff_w)+1);
		exit(0);
	}
	else  
	{
	   //close fd[1] of parent process
	   //since it is a parent process
	   close(pfd[1]);
   	   read(pfd[0],buff_r,sizeof(buff_r));
	   printf("Received message=%s\n",buff_r);
	}
     return 0;
}

