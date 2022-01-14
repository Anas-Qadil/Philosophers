#include "philo.h"


int main()
{


    int j;
    int c = fork();
    if (c != 0)
    {
        waitpid(-1, &j, 0);
        printf("%d\n", j);
    }else
        printf("waiting\n");
}