#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>    // contains prototype for wait
#include <unistd.h>      // contains fork()

int main(void)
{
    int pid;
    int status;

    printf("Hello World!\n");

    pid = fork();  // create child process

    if (pid == -1)  // check for error in fork
    {
        perror("bad fork");
        exit(1);
    }

    if (pid == 0)
    {
        // child process
        printf("I am the child process.\n");
    }
    else 
    {
        // parent process
        wait(&status);  // parent waits for child to finish
        printf("I am the parent process.\n");
        return 0;
    }
}
