#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
    int id,flag;
    scanf("%d", &id);
    printf("%d", id);
    while(1){
        scanf("%d",&flag);
        if(flag==1){
            kill(id, SIGUSR1);
        }
        else{
            kill(id,SIGUSR2);

        }
    }
}
