#include "shell.h"

/**
 * main - Entry for the shell
 *
 * Return: Always 0 on success
 */
int main(void)
{
    size_t buff_s = 0;
    char *buff = NULL;

    while (1)
    {
        message("#cisfun$ ");
        getline(&buff, &buff_s, stdin);

        buff[strcspn(buff, "\n")] = '\0';

        if (strcmp(buff, "exit") == 0)
        {
            message("Exit\n");
            free(buff);
            exit(EXIT_SUCCESS);
        }

        execute(buff);
        free(buff);
    }

    return 0;
}