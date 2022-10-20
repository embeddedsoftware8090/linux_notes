#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

//server program
//has create,bind,listen,accept,send/receive
//

int main()
{
	int sockfd,connfd,len;	
	char buff_1[10];
	char *buff_2 = "Hi";
	struct sockaddr_in server,client;
	//create a socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
	{
		printf("Failed to create socket\n");
	}
	else
	{
		printf("Socket created successfully on client side\n");
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(8080);		
	//bind the socket
	if((bind(sockfd,(struct sockaddr *)&server,sizeof(struct sockaddr_in))) == 0)
	{
	 	printf("Server socket binded sucessfully\n");
	}
	//listen 
	if((listen(sockfd,5)) == 0)
	{
		printf("Socket listened successfully\n");
	}
	//accept
	len = sizeof(client);
	connfd = accept(sockfd,(struct sockaddr *)&client,&len);
	if(connfd < 0)
	{
		printf("Failed to accept socket\n");
	}
	else
	{
		printf("Server accepted the client connection\n");
	}
	//send/receive
	//read message from client
	read(connfd,buff_1,sizeof(buff_1)+1);
	printf("Message from client:%s\n",buff_1);
	//write back to client
	write(connfd,buff_2,sizeof(buff_2)+1);
	close(connfd);
	return 0;
}

