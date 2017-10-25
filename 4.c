#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/
pthread_t tid[10];
int n;
int status;

 
void *faktorial( void *a)
{int *number =(int*) a;
int i,iter;
iter=1;

status=0;
printf("angka =%d\n",*number);
for(i=1;i<= *number;i++)
 {iter=iter*i;}

printf("%d\n",iter);

status = 1;
}


int main(void)
{
     char cmd[20],num[100],iter;
	int a,b,c,d,k,angka,i,j;
    n=0;
status=1;
    

while(1)
{
scanf("%d",&angka);
scanf("%c",&iter);
num[n]=angka;
if(iter=='\n')break;
n++;
}

for (i = 0; i < n+1; ++i)

    {

        for (j = i + 1; j < n+1; ++j)

        {

            if (num[i] > num[j])

            {

                a =  num[i];

                num[i] = num[j];

                num[j] = a;

            }

        }

    }	

i=2;
b=num[i];
 pthread_create(&(tid[i]),NULL,&faktorial,&b);
i=1;
    
c=num[i];

        pthread_create(&(tid[i]),NULL,&faktorial,&c);//membuat thread
i=0;      
d=num[0];
pthread_create(&(tid[i]),NULL,&faktorial,&d);
k=0;
	while(k<=n){
    pthread_join(tid[k],NULL);
	k++;
    }
    exit(EXIT_SUCCESS);
}
