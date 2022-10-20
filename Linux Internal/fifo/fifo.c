//fifo can be created using 2 ways
//this is the creation of fifo by using mknod system call
//takes 3 argument = path,mode and device


#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
	int fd,call;
	char buff_w[10];
	char *path = "/tmp/fifo";
	char buff_r[10];
	// create a pipe by mknod 
	call=mknod("path",0666,0);
	if(call == 0)
	{
		printf("Fifo created successfully by mknod system call\n");
	}
	while(1)
	{
		//open the fie with write permission
	fd=open(path,O_WRONLY);
	printf("Enter the message to send: ");
	      // get the data from the user to write in the file
	fgets(buff_w,10,stdin);
        //write to a fifo
	write(fd,buff_w,strlen(buff_w)+1);
	// close the fd
        close(fd);
	//open a file in read only mode 
	fd=open(path,O_RDONLY);
        //read from fifo
	read(fd,buff_r,10);
        printf("The message received from fifo1 : %s",buff_r);
	//close the read fd 
        close(fd);
	}
        return 0;
}	
