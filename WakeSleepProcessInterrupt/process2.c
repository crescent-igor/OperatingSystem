#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int flag=1;
void sig_handler(int signo)
{
    if (signo == SIGUSR1)
    {
        printf("received SIGUSR1 woke up\n");
        flag=0;
    }
    if (signo == SIGUSR2)
    {
        printf("received SIGUSR2 sleeping\n");
        flag=1;
    }
}

int main(void)
{
    int id = getpid();
    printf("%d\n", id);
    if (signal(SIGUSR1, sig_handler) == SIG_ERR)
    {
        printf("\ncan't catch SIGUSR1\n");
    }
    if (signal(SIGUSR2, sig_handler) == SIG_ERR)
    {
        printf("\ncan't catch SIGUSR2\n");
    }
    while(1){
        if(flag)
            sleep(0);
        else
        printf("awake\n");
        sleep(1);
    }
}
