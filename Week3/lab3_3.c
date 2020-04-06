// Name: Lindsey Reynolds
// Date: 03/24/20
// Title: Lab3 – Part 3
// Description: This program creates a pipe in order to print the 
// "cat /etc/passwd | grep root" command when it is run. 

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
        //arg = "cat /etc/passwd";
        
        execlp("cat", "cat", "/etc/passwd", 0);
    }
    // child 2 duplicates downstream
    else if (fork() == 0)
    {
        dup2(fd[0], 0);
        close(fd[1]);
        //arg = "grep root";
        execlp("grep", "grep", "root", 0);
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