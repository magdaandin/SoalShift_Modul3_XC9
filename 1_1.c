#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main()
{ char iter[100];
int jum;
        key_t key1 = 1234;
	key_t key2 = 1235;
	key_t key3 = 1236;
	key_t key4 = 1237;
	key_t key5 = 1238;
	key_t key6 = 1239;
        int *value1,*value2,*value3,*value4,*value5,*value6;

        int shmid = shmget(key1, sizeof(int), IPC_CREAT | 0666);
        value1 = shmat(shmid, NULL, 0);
int shmid = shmget(key2, sizeof(int), IPC_CREAT | 0666);
        value2 = shmat(shmid, NULL, 0);
int shmid = shmget(key3, sizeof(int), IPC_CREAT | 0666);
        value3 = shmat(shmid, NULL, 0);
int shmid = shmget(key4, sizeof(int), IPC_CREAT | 0666);
        value4 = shmat(shmid, NULL, 0);
int shmid = shmget(key5, sizeof(int), IPC_CREAT | 0666);
        value5 = shmat(shmid, NULL, 0);
int shmid = shmget(key6, sizeof(int), IPC_CREAT | 0666);
        value6 = shmat(shmid, NULL, 0);
*value1=0;
*value2=0;
*value3=0;
*value4=0;
*value5=0;
*value6=0;
        While(1)
{ scanf("%s%d",iter,jum);
	if(iter=="MP4A1")
	{ *value1+=jum;
	}
	else if(iter=="PM2-V1")
	{ *value2+=jum;
	}
	else if(iter=="SPR-3")
	{ *value3+=jum;
	}
	else if(iter=="SS2-V5")
	{ *value4+=jum;
	}
else if(iter=="SPG1-V3")
	{ *value5+=jum;
	}
else 
	{ *value6+=jum;
	}
	}


        printf("Program 1 : %d\n", *value);

        sleep(5);

        printf("Program 1: %d\n", *value);
        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}
