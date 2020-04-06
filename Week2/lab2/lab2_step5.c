// Name: Lindsey Reynolds
// Date: 02/17/20
// Title: Lab 2 Step 5
// Description: This program demonstrates the capabilities 
// of the fork(), execlp() and wait() functions.


#include <stdio.h> /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h> /* fork */
#include <stdlib.h> /* atoi */
#include <errno.h> /* errno */
#include <sys/wait.h> /* wait function */

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) 
{
    pid_t pid;
    printf("\n Before forking.\n");
    pid = fork();

    if (pid == -1) 
    {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    else if(pid == 0)
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child Complete");
        exit(0);
    }
    return 0;
}