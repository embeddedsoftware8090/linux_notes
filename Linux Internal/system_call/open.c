#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char *buff="Hello , I am printed";
	int fd;
	fd = open("kaviya.txt",O_CREAT,S_IWUSR|S_IWGRP|S_IWOTH);
	if(fd<0)
	{
		printf("Failed to create file\n");
	}
	else
	{
		printf("File created successfully\n");
	}
	write(fd,buff,30);
      	return 0;
}
