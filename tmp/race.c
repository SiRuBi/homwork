#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char c[6] = {'H','E','L','L','O','n'};
int i=0;

void *thread1(){
		i++;   
}

void *thread2(){
		if(i==6)
			i=0;
}

int main()
{

				
		while(1) {
							
			  
									
			 pthread_t th1;
			 pthread_t th2;

			 pthread_create(&th1, NULL, thread1, NULL);
			 pthread_create(&th2, NULL, thread2, NULL);

			 pthread_join(th1, NULL);
		     pthread_join(th2, NULL);

			 printf("%c",c[i]);
			 if(i==5)
				 printf("\n");

			 
				}
				    return 0;
}
