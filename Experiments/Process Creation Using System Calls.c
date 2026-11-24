//Q1: Create a new process by invoking the appropriate system call. Get the process identifier of the currently running process and its respective parent using system calls and display the same using a C program.
//program:
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("Parent Process ID: %d\n", getpid());
    printf("Parent's Parent ID: %d\n", getppid());

    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        printf("\nChild Process\n");
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    }
    else
    {
        wait(NULL);
        printf("\nParent Process\n");
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }

    return 0;
}

//Output
// Parent Process ID: 45196
// Parent's Parent ID: 45134

// Child Process
// Child Process ID: 45197
// Parent Process ID: 45196

// Parent Process
// Parent Process ID: 45196
// Child Process ID: 45197
