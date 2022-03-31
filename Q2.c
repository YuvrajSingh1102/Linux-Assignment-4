/*
Q2.Write a program where a structure of information passed to pthread task function, and display
structure of information.
*/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

struct my_thread
{
	int thread_id;
	char message[100];
};

void *PrintHello(void *threadobj)
{
	pthread_t thread_ID;
	struct my_thread *t1;
	t1 = (struct my_thread *) threadobj;
	thread_ID = pthread_self();
	printf("\nThread Id : %u\n",thread_ID);
	printf("\n %d Thread message :%s\n",t1->thread_id,t1->message);
}

int main()
{
	pthread_t thread2,thread3,thread4,thread_ID;
	int rc;
	struct my_thread t2,t3,t4;
	t4.thread_id = 4;
	strcpy(t4.message,"I am forth thread\n");
	t2.thread_id=2;
	strcpy(t2.message,"I am second thread\n");
	t3.thread_id=3;
	strcpy(t3.message,"I am third thread\n");
	
	thread_ID = pthread_self();
	printf("\nMain thread ID : %u",thread_ID);
	
	pthread_create(&thread4,NULL,PrintHello,(void *)&t4);
	pthread_create(&thread4,NULL,PrintHello,(void *)&t2);
	pthread_create(&thread4,NULL,PrintHello,(void *)&t3);
	
	printf("\nExit from main thread");
	pthread_exit(NULL);

    return 0;
}