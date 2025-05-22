#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdint.h>
#include<stdlib.h>
typedef struct{
    int *arr;
    int start;
    int end;
}threadArgs;


void *sum( void *args)
{
    threadArgs *range=args;
    int s=0;
    for(int i=range->start;i<range->end;i++)
    {
        s+=range->arr[i];
    }
    int *result=malloc(sizeof(int));
    *result=s;

    if(range->start==0)
    {
        printf("sum of first half is %d\n",s);
    }
    else{
        printf("sum of second half is %d\n",s);

    }
    pthread_exit((void*)result);

    
}

int main()
{
    pthread_t t1,t2;
    printf("\nProgramm to calculate sum by deviding a arry into two parts\n\n");

    printf("Enter array size:\n");
    int n;
    scanf("%d",&n);

    int *arr=(int*)malloc(sizeof(int)*n);

    printf("Enter elements of the array\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    threadArgs arg1={arr,0,n/2};
    threadArgs arg2={arr,n/2,n};
    int *r1,*r2;

    pthread_create(&t1,NULL,sum,(void*)&arg1);
    pthread_create(&t2,NULL,sum,(void*)&arg2);
    pthread_join(t1,(void**)&r1);
    pthread_join(t2,(void**)&r2);

    int total= *r1 + *r2;
    printf("Sum of the array is %d\n",total);

    free(arr);
    free(r1);
    free(r2);








    






}