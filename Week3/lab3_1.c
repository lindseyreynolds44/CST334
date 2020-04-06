// Name: Lindsey Reynolds
// Date: 03/24/20
// Title: Lab3 – Part 1
// Description: This program creates a pipe in order
// to print the "ls | more" command when it is run. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);

    // child 1 duplicates upstream 
    if (fork() == 0)
    {
        dup2(fd[1], 1);
        close(fd[0]);
        execlp("/bin/ls", "ls", 0);
    }
    // child 2 duplicates downstream
    else if (fork() == 0)
    {
        dup2(fd[0], 0);
        close(fd[1]);
        execlp("more", "more", 0);
    }
    else
    { 
        // parent closes file descriptors and waits for children to terminate
        close(fd[0]);
        close(fd[1]);
        wait(0);
        wait(0);
    }
    return 0;
}