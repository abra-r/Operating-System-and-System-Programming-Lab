#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>

int main()
{
    printf("Parent Process PID= %d\n",getpid());

    pid_t p1=fork();

    if(p1<0)
    {
        printf("fork failed\n");
        return 1;
    }
    else if(p1==0)
    {
        printf("Child process of process %d is started. This process id is %d\n",getppid(),getpid());
        printf("Simulation of downloading screen in process %d\n",getpid());

        
        for(int i=0;i<=10;i++ )
        {
            printf("Downlad..... %d%%\n",i*10);
            sleep(1);


        }
        printf("Download Complete!\n");


        printf("Child process is exiting\n");
        exit(0);
        printf("This part will not exicute\n");

    }
    else 
    {
        wait(NULL);
        printf("Parent process %d is exicuting\n",getpid());

    }
    return 0;


}
