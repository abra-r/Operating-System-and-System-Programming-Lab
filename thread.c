//Thread Crate And Join

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *threadFunction(void *arg)
{
    printf("It is Thread Function\n");
    return NULL;
}

int main()
{
    pthread_t t1;
    pthread_create(&t1,NULL,threadFunction,NULL);

    pthread_join(t1,NULL);

    printf("This is main function. Exicuting after complete thread exicution\n");


}