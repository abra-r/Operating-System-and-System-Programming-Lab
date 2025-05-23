#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void *thrF1(void *arg)
{
    pthread_mutex_lock(&mutex1);
    printf("Thred 1 acquired mutex1\n");
    sleep(1);
    printf("Theread 1 trying to acqire mutex2\n");
    pthread_mutex_lock(&mutex2);
    printf("thread 1 acquired mutex2\n");


    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return NULL;

}

void *thrF2(void *arg)
{
    pthread_mutex_lock(&mutex2);
    printf("Thred 2 acquired mutex2\n");
    sleep(1);
    printf("Theread 2 trying to acqire mutex1\n");
    pthread_mutex_lock(&mutex1);
    printf("thread 2 acquired mutex1\n");

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    
    return NULL;

}

int main()
{
    pthread_t t1,t2;

    printf("Simulating Deadlock situation using Mutex lock\n");

    pthread_mutex_init(&mutex1,NULL);
    pthread_mutex_init(&mutex2,NULL);


    pthread_create(&t1,NULL,thrF1,NULL);
    pthread_create(&t2,NULL,thrF2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);


}