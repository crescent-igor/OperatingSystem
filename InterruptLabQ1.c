
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
void sig_handler(int signo)
{
    if (signo == SIGUSR1)
    {
        printf("received SIGUSR1 from child\n");
        _exit(0);
    }
}
void forkInterrupt()
{
    // child process because return value zero
    if (fork() == 0)
        // printf("Hello from Child!\n");

        kill(getppid(), SIGUSR1);

    // parent process because return value non-zero.
    else
    {

        printf("Hello from Parent!\n");

        if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        {
            printf("\ncan't catch SIGUSR1\n");
        }
        while (1)
            sleep(1);
    }
}
int main()
{
    forkInterrupt();
    return 0;
}
