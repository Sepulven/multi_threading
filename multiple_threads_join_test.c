#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];

void* trythis1(void* arg)
{

    while(1)
    {
        sleep(1);
        printf("S: %d\n", 1);
    }
	return NULL;
}
void* trythis2(void* arg)
{

    while(1)
    {
        sleep(2);
        printf("S: %d\n", 2);
    }
	return NULL;
}

int main(void)
{
	int i = 0;
	int error;

    pthread_create(&(tid[0]), NULL, &trythis1, NULL);
    pthread_create(&(tid[0]), NULL, &trythis2, NULL);
	pthread_detach(tid[0]);
	pthread_detach(tid[1]);
    sleep(10);
	return 0;
}
