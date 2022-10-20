#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<fcntl.h>

//IPC through shared memory , steps = create,attach,read/write,detach,remove
//ftok call to create a key
//use shmget,shmat,shmdt to write to the memory


int main()
{
	int shmid;
	char buff_w[20];
	char buff_r[20];
	key_t key;
        char *call;
	//generate the key
	key=ftok("share",45);
	//create the memory
	shmid = shmget(key,1024,IPC_CREAT|0666);
        //attach 
	call = shmat(shmid,(void *)0,0);
	//read / write
	//write data
	printf("Enter the message to send: ");
	//get data from the user
	fgets(buff_w,20,stdin);
	printf("The sent data : %s\n",buff_w);
	//detach the memory
        shmdt(call);
	return 0;
}
	

