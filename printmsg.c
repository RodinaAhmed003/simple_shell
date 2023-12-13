#include "shell.h"

/**
 * print_en - Print the environment
 *
 * Return: void
 */
void print_en(void)
{
    int i = 0;

    while (en [i] != NULL)
    {
        printf("%s\n", en [i]);
        i++;
    }
}