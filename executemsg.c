#include "shell.h"

/**
 * execute - Execute a command in shell
 * @input: Command to be executed
 *
 * Return: void
 */
void executemsg(const char *input)
{
    char *take_it;
    int i = 0, stat = 0;
    char **arr;
    pid_t child_pid;

    take_it = strtok(input, "\t\n");

    arr = malloc(sizeof(char *) * 1024);

    while (take_it != NULL)
    {
        arr[i] = take_it;
        take_it = strtok(NULL, "\t\n");
        i++;
    }

    arr[i] = NULL;

    if (strcmp(arr[0], "env") == 0)
    {
        print_en();
    }
    else
    {
        child_pid = fork();

        if (child_pid == 0)
        {
            if (execve(arr[0], arr, NULL) == -1)
            {
                perror("Error Message in execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&stat);
        }
    }

    free(arr);
}
