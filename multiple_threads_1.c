#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g = 0;

void *myThreadFun(void *vargp)
{
    int *myid = (int *)vargp;
    static int s = 0;

    s++;
    g++;
    printf("Thread ID: %d, Static: %d, Global %d\n", *myid, ++s, ++g);
}


int main()
{
    int i;
    pthread_t tid;

    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
    pthread_mutex_lock(&lock);
	unsigned long i = 0;
	counter += 1;
	printf("\n Job %d has started\n", counter);

	for (i = 0; i < (0xFFFFFFFF); i++)
		;
	printf("\n Job %d has finished\n", counter);

    pthread_mutex_unlock(&lock);
	return NULL;
    pthread_exit(NULL);

    return (0);
}


