#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread
#include <string.h>

void *count( void *ptr );


int main()
{
     pthread_t thread1, thread2;//inisialisasi awal
      char *word1 ;
      char *word2 ;
scanf("%s%s",word1,word2);
    
     pthread_create( &thread1, NULL, count, word1);//membuat thread pertama
     pthread_create( &thread2, NULL, count, word2);//membuat thread kedua
     
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     exit(EXIT_SUCCESS);
}

void * count(void *ptr)
{char* string;
string =(char *)ptr;
int total;
FILE *fo, *fw;	
	char str[1024];
	fo = fopen("Novel.txt", "r");


	while (fgets(str, 1024, fo) != NULL)
	{
	if(strstr(str, string))
	{
		total++;
		
	}
	}
	fclose(fo);
	fclose(fw);


   
}
