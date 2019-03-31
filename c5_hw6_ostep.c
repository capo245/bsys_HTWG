/*---------------------------------------------------------------------------*/
//gcc -Wall -Werror -Wextra -Wpedantic -Wpedantic -pedantic-errors -fopenmp 
//-O0 -march=native -mstackrealign -mfpmath=both -masm=intel -S -c ostep_hw2.c 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
/*---------------------------------------------------------------------------*/
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
/*---------------------------------------------------------------------------*/
int
main(int argc, char*argv[])
{
//1
    signed int rc = -1;
    signed char selector = 'p'; //p = parent, c = child
    signed int status;
/*---------------------------------------------------------------------------*/    
    rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
//2
    if (rc == 0)
    {
        if(selector == 'p')
        {
            printf("\nParent waits\n");
        }
        else {
            int rc_wait = waitpid(0, &status, WNOHANG);
            printf("\nChild finished\nWAITPID, STATUS returned %i, %i\n", rc_wait, status);
        }
    }
//3
    else {
        // parent
        if(selector == 'c')
        {
            printf("\nChild waits\n");
        }
        else {
            int rc_wait = waitpid(1, &status, WNOHANG);
            printf("\nParent finished\nWAITPID, STATUS returned %i, %i\n", rc_wait, status);
        }
    }
/*---------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------*/
