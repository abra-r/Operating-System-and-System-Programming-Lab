#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define SIZE 5
using namespace std;

sem_t empt,full;
int buffer[SIZE];
int in=0,out=0;
pthread_mutex_t mutex;

void *producer(void* arg)
{
    int item=1;
    while (1)
    {
        sem_wait(&empt);
        pthread_mutex_lock(&mutex);
        buffer[in]=item;
        cout<<"Produced: "<<item<<" at "<<in<<endl;
        in=(in+1)%SIZE;
        item++;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }


    
}

void* consumer(void *arg)
{
     while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        cout << "\tConsumed: " << item << " from " << out << endl;
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empt);
        sleep(2);
    }
    
}

int main() {
    pthread_t prod, cons;
    sem_init(&empt, 0, SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}