#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int b;
int c;

void *thread1()
{
	    b = b + c;
		    c = b + c;
}

void *thread2()
{
	    b = b + c;
		    c = b + c;
}

int main()
{
	    while(1) {
			        b = 1;
					        c = 2;

							        pthread_t th1;
									        pthread_t th2;

											        pthread_create(&th1, NULL, thread1, NULL);
													        pthread_create(&th2, NULL, thread2, NULL);

															        pthread_join(th1, NULL);
																	        pthread_join(th2, NULL);

																			        printf("b = %d, c = %d\n", b, c);
																					        sleep(1);
																							    }
		    return 0;
}

