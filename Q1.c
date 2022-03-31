/*
Q1.Write a pthread application where main task terminated but pending pthreads task still execute.
*/

#include<pthread.h>
#include<stdio.h>


void *thread(void)
{
	printf("\nI am in my thread\n");
}

int main()
{

	pthread_t mythread;
	pthread_create(&mythread,NULL,thread,NULL);
	printf("\nExit for main thread\n");
	pthread_exit(NULL);

    return 0;
}