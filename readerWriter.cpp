#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t writeLock = PTHREAD_MUTEX_INITIALIZER;
int readCount = 0;

void* reader(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        readCount++;
        if (readCount == 1)
            pthread_mutex_lock(&writeLock);
        pthread_mutex_unlock(&mutex);

        cout << "Reader reading...\n";
        sleep(1);

        pthread_mutex_lock(&mutex);
        readCount--;
        if (readCount == 0)
            pthread_mutex_unlock(&writeLock);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
}

void* writer(void* arg) {
    while (1) {
        pthread_mutex_lock(&writeLock);
        cout << "\tWriter writing...\n";
        sleep(2);
        pthread_mutex_unlock(&writeLock);
        sleep(2);
    }
}

int main() {
    pthread_t r1, r2, w1;
    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    return 0;
}
