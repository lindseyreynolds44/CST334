// Name: Lindsey Reynolds
// Date: 03/24/20
// Title: Lab3 – Part 2
// Description: This program 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd[2];
    char buff[60];
    int count;
    int i;
    pipe(fd);

    // child 1 writes all command line arguments to the buffer
    if (fork() == 0)
    {
        printf("\nWriter on the upstream end of the pipe -> %d arguments \n", argc);
        close(fd[0]);
        for (i = 0; i < argc; i++)
        {
            write(fd[1], argv[i], strlen(argv[i]));
        }
        exit(0);
    }

    // child 2 reads buffer into stdout
    else if (fork() == 0)
    {
        printf("\nReader on the downstream end of the pipe \n");
        close(fd[1]);
        while ((count = read(fd[0], buff, 60)) > 0)
        {
            for (i = 0; i < count; i++)
            {
                write(1, buff + i, 1);
                write(1, " ", 1);
            }
            printf("\n");
        }
        exit(0);
    }
    else
    {
        close(fd[0]);
        close(fd[1]);
        wait(0);
        wait(0);
    }
    return 0;
}