#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
pthread_t tid3;
pthread_t tid4;
int status;
int nomor;
int status1,status2;
 
void* makan1(void *arg)
{
    status1 = status1+10;
 
    
 
    
}


void* makan2(void *arg)
{
    status2=status+10;
printf("status2==%d",status2);
}

void* proses2(void *arg)
{
    while(status2>0||status2<=100)
{status2 = status2-10;
sleep(20);}
}

void* proses1(void *arg)
{printf("aaaa");
    while(status1>0||status1<=100)
{status1 = status1-15;
sleep(10);}

}
 
int main(void)
{	printf("Untuk memberi makan lohan tekan 1\n");
	printf("Untuk memberi makan kepiting tekan 2");
	
int iter;

status1=100;
status2=100;

pthread_create(&(tid1), NULL, &proses1, NULL);
pthread_create(&(tid2), NULL, &proses2, NULL);



while(status1>0||status1<=100||status2>0||status2<=100)
{printf("bbbbbb");
scanf("%d",&iter);
printf("%d",iter);
if(iter==1)
pthread_create(&(tid3), NULL, &makan1, NULL);

else
pthread_create(&(tid4), NULL, &makan2, NULL);
if(status1<=0||status1>100||status2<=0||status2>100)break;}

  
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);	
	pthread_join(tid4, NULL);
 
    return 0;
}

