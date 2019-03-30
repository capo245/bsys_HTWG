/*---------------------------------------------------------------------------*/
//gcc -Wall -Werror -Wextra -Wpedantic -Wpedantic -pedantic-errors -fopenmp 
//-O0 -march=native -mstackrealign -mfpmath=both -masm=intel -S -c ostep_hw2.c 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*---------------------------------------------------------------------------*/
signed int
shared_var = -1;//static voltaile?
/*---------------------------------------------------------------------------*/
int
main(void)
{
//1
    signed int access_count = 0;
    signed int rc = -1;
    printf("\n*ELTERNPROZESS >(pid:%d)\nSchreibe Wert> 1 in globale Variable"
        "\nWert von Zugriffszähler>%i\n",
         (int) getpid(), access_count);
    shared_var = 1;
    //prüfen ob wert 1?
    access_count = access_count+1;
/*---------------------------------------------------------------------------*/    
    rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
//2
        // child (new process)
        printf("\n#KINDPROZESS (pid:%d)\nWert von globaler Variable %i\n"
            "\nSchreibe Wert> 99 in globale Variable"
            "\nWert von Zugriffszähler>%i\n",
             (int) getpid(), shared_var, access_count);
        shared_var = 99;
        //prüfung DES ZUGRIFFES?
        access_count = access_count+1;
    }
/*    else
    {
        // parent goes down this path (original process)
        printf("\n*ELTERNPROZESS von > %d (pid:%d)\n",
	       rc, (int) getpid());
    }
*/
//3
    printf(
        "\n"
        "µENDE>%i"
        "---------------------------------------------------------------------"
        "\nWert von globaler Variable %i\nWert von Zugriffszähler>%i\n",
             (int) getpid(), shared_var, access_count);
/*---------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------*/
