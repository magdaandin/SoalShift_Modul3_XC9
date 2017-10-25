#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
void main()
{ char iter[100];
int jum,input;
        key_t key1 = 1234;
	key_t key2 = 1235;
	key_t key3 = 1236;
	key_t key4 = 1237;
	key_t key5 = 1238;
	key_t key6 = 1239;
        int *value1,*value2,*value3,*value4,*value5,*value6;

        int shmid1 = shmget(key1, sizeof(int), IPC_CREAT | 0666);
        value1 = shmat(shmid1, NULL, 0);
int shmid2 = shmget(key2, sizeof(int), IPC_CREAT | 0666);
        value2 = shmat(shmid2, NULL, 0);
int shmid3 = shmget(key3, sizeof(int), IPC_CREAT | 0666);
        value3 = shmat(shmid3, NULL, 0);
int shmid4 = shmget(key4, sizeof(int), IPC_CREAT | 0666);
        value4 = shmat(shmid4, NULL, 0);
int shmid5 = shmget(key5, sizeof(int), IPC_CREAT | 0666);
        value5 = shmat(shmid5, NULL, 0);
int shmid6 = shmget(key6, sizeof(int), IPC_CREAT | 0666);
        value6 = shmat(shmid6, NULL, 0);
*value1=0;
*value2=0;
*value3=0;
*value4=0;
*value5=0;
*value6=0;
while(1){
printf("Tekan 1 untuk lihat senjata\n");
printf("Tekan 2 untuk beli senjata\n");

scanf("%d",&input);

if(input==1)
{
printf("MP4A1 %d\n",*value1);
printf("PM2-V1 %d\n",*value2);
printf("SPR-3 %d\n",*value3);
printf("SS2-V5 %d\n",*value4);
printf("SPG1-V3 %d\n",*value5);
printf("MINE %d\n",*value6);

}
        
else if(input==2){
{ scanf("%s%d",iter,&jum);
	if(strcmp(iter,"MP4A1")==0)
	{if(*value1==0)printf("barang di stock tidak cukup\n"); 
	*value1-=jum;
	}
	else if(strcmp(iter,"PM2-V1")==0)
	{if(*value2==0)printf("barang di stock tidak cukup\n");  
	*value2-=jum;
	}
	else if(strcmp(iter,"SPR-3")==0)
	{if(*value3==0)printf("barang di stock tidak cukup\n");  
	*value3-=jum;
	}
	else if(strcmp(iter,"SS2-V5")==0)
	{if(*value4==0)printf("barang di stock tidak cukup\n");  
	*value4-=jum;
	}
else if(strcmp(iter,"SPG1-V3")==0)
	{if(*value5==0)printf("barang di stock tidak cukup\n");  
	*value5-=jum;
	}
else 
	{if(*value6==0)printf("barang di stock tidak cukup\n");  
	*value6-=jum;
	}
	}
}

}
       
        shmdt(value1);
	shmdt(value2);
	shmdt(value3);
	shmdt(value4);
	shmdt(value5);
	shmdt(value6);
        shmctl(shmid1, IPC_RMID, NULL);
shmctl(shmid2, IPC_RMID, NULL);
shmctl(shmid3, IPC_RMID, NULL);
shmctl(shmid4, IPC_RMID, NULL);
shmctl(shmid5, IPC_RMID, NULL);
shmctl(shmid6, IPC_RMID, NULL);

}
