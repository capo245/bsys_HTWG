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
main(void)
{
//1
    signed int fd1[2];  // Pipe Information  
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
        //child
        char msg[] = "PIPE";
        write(fd1[1], msg, strlen(msg)+1);
        close(fd1[1]);
        exit(0);
    }
//3
    else {
        //parent
        char msgbox[5];
        wait(NULL);
        read(fd1[0], msgbox, 5);
        printf("%s\n", msgbox);
        return 0;
//
    }
/*---------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------*/
