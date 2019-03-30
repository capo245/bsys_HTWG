/*---------------------------------------------------------------------------*/
//gcc -Wall -Werror -Wextra -Wpedantic -Wpedantic -pedantic-errors -fopenmp 
//-O0 -march=native -mstackrealign -mfpmath=both -masm=intel -S -c ostep_hw2.c 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/*---------------------------------------------------------------------------*/
signed int
shared_var = -1;//static voltaile?
/*---------------------------------------------------------------------------*/
int
main(void)
{
//1
    unsigned int cnter = 0;
    signed int access_count = 0;
    signed int rc = -1;
    close(STDOUT_FILENO);
    open("./output.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    printf("\n*ELTERNPROZESS >(pid:%d)\nSchreibe Wert> $ in Datei"
        "\nWert von Zugriffszähler>%i\n",
         (int) getpid(), access_count);
    while(cnter < 10)
    {
        printf("$");
        cnter = cnter + 1;
        if(cnter % 5 == 0)
        {
             printf("'");
        }
        access_count = access_count + 1;
    }
//    shared_var = 1;
    //prüfen ob wert 1?
    cnter = 0;
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
        printf("\n#KINDPROZESS (pid:%d)\n"
            "\nSchreibe Wert> € in globale Variable"
            "\nWert von Zugriffszähler>%i\n",
             (int) getpid(), access_count);
        while(cnter < 10)
        {
            printf("€");
            cnter = cnter + 1;
            if(cnter % 5 == 0)
            {
                printf("'");
            }
            access_count = access_count + 1;
        }
//        shared_var = 99;
        //prüfung DES ZUGRIFFES?
        cnter = 0;
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
        "\nELTERNPROZESS\nWert von Zugriffszähler>%i\n",
             (int) getpid(), access_count);
/*---------------------------------------------------------------------------*/
    return 0;
}
/*---------------------------------------------------------------------------*/
