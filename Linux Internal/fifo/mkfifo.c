#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
//second way of creating fifo
//created a fifo using mkfifo library function
//takes 2  arguments = path and file permission

int main()
{
	int fd1,call,nbytes;
	char buff1_w[10];
	char buff1_r[10];
        char *path = "/tmp/fifo";
	//create fifo 
	call = mkfifo(path,0666);
	if(call == 0)
	{
		printf("Fifo created successfully\n");
	}
	//for loop for getting data
	while(1)
	{
		//open the file in read only mode 
	fd1 = open(path,O_RDONLY);
	//read from the buffer 
	read(fd1,buff1_r,10);
	if(nbytes > 0)
	{
		printf("read  from  fifo1 is succesfull\n");
	}
	//display the message
        printf("The message received from fifo: %s",buff1_r);
 
	//close the read end
	close(fd1);
	//open the file with write mode
	fd1=open(path,O_WRONLY);
	// get the data from the stdin(to write into the file)
	printf("Enter the message to respond: ");
	fgets(buff1_w,10,stdin);
	// write the collected data to the buffer 
	write(fd1,buff1_w,strlen(buff1_w)+1);
	//close the write back end
	close(fd1);
	}
	return 0;
}
