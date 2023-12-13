#include "shell.h"

/**
 * print_en - Print the environment.
 *
 * Return: void
 */
void print_en(void)
{
    int i = 0;

    while (en[i] != NULL)
    {
        printf("%s\n", en[i]);
        i++;
    }
}

/**
 * message - Print message to stdout.
 * @msg: The message to be printed.
 *
 * Return: void
 */
void message(const char *msg)
{
    printf("%s", msg);
}

=======
#include "shell.h"
/**
* message - Print message to stdout
* @msg: The message to be printed
*
* Return: void
*/
void message(const char *msg)
{
printf("%s", msg);
}
char **en;
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
>>>>>>> 4921f4a389e8aa360cd999d560c895fd6629fe1b
