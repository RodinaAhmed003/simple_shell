#include "shell.h"
/**
* sh_writeEr - execute cmd
*
* @argv: char ptr parameter
* @index_str: int parameter
* @msg: char ptr parameter
* @cmd: char ptr parameter
*
* Return: void
*/
void sh_writeEr(char **argv, char *index_str, char *msg, char **cmd)
{
write(STDERR_FILENO, argv[0], str_length(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index_str, str_length(index_str));
write(STDERR_FILENO, msg, str_length(msg));
write(STDERR_FILENO, cmd[1], str_length(cmd[1]));
write(STDERR_FILENO, "\n", 1);
}
/**
* sh_printerror - execute cmd
*
* @shellName: char ptr parameter
* @myCmd: char ptr parameter
* @index: int parameter
*
* Return: void
*/
void sh_printerror(char *shellName, char *myCmd, int index)
{
char *index_s, my_msg[] = ": not found\n";

index_s = sh_itoa(index);

write(STDERR_FILENO, shellName, str_length(shellName));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index_s, str_length(index_s));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, myCmd, str_length(myCmd));
write(STDERR_FILENO, my_msg, str_length(my_msg));
free(index_s);
}
