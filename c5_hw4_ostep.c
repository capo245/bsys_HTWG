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
        char *args[3];
        args[0] = strdup("/bin/ls");
        args[1] = strdup("/usr/");
        args[2] = NULL;
        printf("\nTrying exec variants\n");
        execl("/bin/ls", "/usr/", NULL);
        execle("/bin/ls", "ls", "/usr/", NULL, NULL);
        execlp("/bin/ls","ls", "/usr/", NULL);
//        execv("/bin/ls", "/usr/");
        execv(args[0], args);
        execvp(args[0], args);   
    }
//3
    else {
        // parent
        //int rc_wait = wait(NULL);
    }
/*---------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------*/
