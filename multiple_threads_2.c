#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


pthread_mutex_t lock;

void *myThreadFun(void *data)
{
    pthread_mutex_lock(&lock);

    int *time = (int *)data;
    sleep(*time);
    printf("Time slept %d\n", *time);

    pthread_mutex_unlock(&lock);
}


int main()
{
    int i;
    pthread_t tid[10];

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("/n mutex init has failed /n");
        return 1;
    }

    for (i = 0; i < 10; i++)
    {
        pthread_create(&tid[i], NULL, myThreadFun, (void *)&i);
    }

    for (i = 0; i < 10; i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_exit(NULL);

    return (0);
}
