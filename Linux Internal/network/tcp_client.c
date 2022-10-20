#include<stdio.h>
#include<sys/types.h> 
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
//tcp client program
//has creation(socket),connect.send/receive

int main()
{
	int sockfd,connfd,len;
	struct sockaddr_in server,client;
	char *buff_1 = "abcd";
        char buff_2 [10];	
	//create the client socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd > 0)
	{
		printf("Client socket created successfully\n");
	}
	server.sin_family=AF_INET;
	server.sin_addr.s_addr = inet_addr("193.168.0.133");
	server.sin_port = htons(8080);
	//connect the client socket to server 
	if(connect(sockfd,(struct sockaddr *)&server,sizeof(server)) == 0)
	{
		printf("Client socket connected successfully to server\n");
	}
	//
	write(sockfd,buff_1,sizeof(buff_1)+1);
	printf("Message written to server:%s\n",buff_1);
	read(sockfd,buff_2,sizeof(buff_2)+1);
	close(sockfd);
	return 0;
}

