#include "shell.h"
/**
* main - shell entry point
* @ac: arg c
* @argv: arg v
*
* Return: status value
*/
int main(int ac, char **argv)
{
char *myLine = NULL;
int myStatus = 0, index = 0;
char **myCmd = NULL;
(void)ac;
while (1)
{
myLine = sh_read();
if (myLine == NULL)
{
if (isatty(STDIN_FILENO))
manar_print("\n");
return (myStatus);
}
index++;
myCmd = sh_tokenizer(myLine);
if (!myCmd)
continue;
if (sh_builtin_check(myCmd[0]))
{	sh_builtin_handle(myCmd, argv, &myStatus, index);
}
else
myStatus = sh_execute(myCmd, argv, index);
}
}
