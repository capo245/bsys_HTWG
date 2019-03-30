/*---------------------------------------------------------------------------*/
//gcc -Wall -Werror -Wextra -Wpedantic -Wpedantic -pedantic-errors -fopenmp 
//-O0 -march=native -mstackrealign -mfpmath=both -masm=intel -S -c ostep_hw2.c 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*---------------------------------------------------------------------------*/
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
static signed int *shared_var;
/*---------------------------------------------------------------------------*/
int
main(void)
{
//1
    shared_var = mmap(NULL, sizeof *shared_var, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *shared_var = -1;
    signed int rc = -1;
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
        // child
        printf("\nHi :)\n");
        *shared_var = 9;   
    }
//3
    else {
        // parent
        while(*shared_var != 9)
            continue;
        printf("\nGoodbye\n");
        munmap(shared_var, sizeof *shared_var);
    }
/*---------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------*/
