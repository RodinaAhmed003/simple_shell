#include "shell.h"
/**
* manar_print - print
*
* @myText: int parameter
*
* Return: void
*/
void manar_print(const char *myText)
{
write(STDOUT_FILENO, myText, strlen(myText));
}
