#include<sys/ipc.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/shm.h>
// shared memory server kind program read
// use ftok,shmget,shmat,shmdt and shmctl 
// note:
//     the remove is neccesary on the server/read from memory program 
//
int main()
{
	int shmid;
	key_t key;
	char*call;
        char buff1_w[20];
	char buff1_r[20];
	//key creation	
	key=ftok("share",45);
	//create the shared memory
	shmid = shmget(key,20,O_CREAT|0666);
	//attach the shared memory
        call = shmat(shmid,(void *)0,0);
	//read 
	printf("Enter the message to respond: ");
	fgets(buff1_r,20,stdin);
	printf("The responded message:%s\n",buff1_r);
	//detach from the memory
	shmdt(call);
	//destroy the memory 
	shmctl(shmid,IPC_RMID,0);
	return 0;
}
