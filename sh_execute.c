#include "shell.h"
/**
* sh_execute - execute cmd
*
* @myCmd: char ptr parameter
* @argv: char ptr parameter
* @index: int  parameter
*
* Return: void
*/
int sh_execute(char **myCmd, char **argv, int index)
{
pid_t myChild;
int status;
char *fullCmd;
fullCmd = sh_getpath(myCmd[0]);
if (fullCmd == NULL)
{
sh_printerror(argv[0], myCmd[0], index);
return (108);
}
myChild = fork();
if (myChild == 0)
{
if (execve(fullCmd, myCmd, environ) == -1)
{
free(fullCmd), fullCmd = NULL;
}
}
else
{
waitpid(myChild, &status, 0);
free(fullCmd), fullCmd = NULL;
}
return (WEXITSTATUS(status));
}
