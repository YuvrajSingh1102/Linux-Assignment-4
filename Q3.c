/*
Q3. Write a pthread program that implements simple initialization code.
*/

#include<pthread.h>
#include<stdio.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *init()
{
	printf("\nInside Pthread once function\n");
}

void *mythread(void *i)
{
	printf("\n%s\n",(char *)i);
	printf("\nInside thread function\n");
	pthread_once(&once,(void *)init);
	printf("\nExit from thread function\n\n");
}

int main()
{

	pthread_t thread, thread1;
    	printf("====Start of main program====");
	pthread_create(&thread,NULL,mythread,(void *)"Thread function called 1st time");
	pthread_create(&thread1,NULL,mythread,(void *)"Thread function called 2nd time");

	
	pthread_join(thread,NULL);
	pthread_join(thread1,NULL);
	printf("\nEnd of program\n");
    	printf("====End of the main program====\n");

    return 0;
}
