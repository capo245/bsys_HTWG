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
                //child
                close(STDOUT_FILENO);
                open("./output.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
                printf("CHILD_>\n");
    }
//3
    else {
        // parent
        printf("PARENT_>\n");
    }
/*---------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------*/
